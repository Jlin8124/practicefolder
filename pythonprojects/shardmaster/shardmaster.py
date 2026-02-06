import asyncio
import asyncpg
import hashlib
import bisect
import random
import uuid
from collections import defaultdict

# --- CONFIGURATION ---
# These match the ports defined in your docker-compose.yml
SHARD_CONFIG = {
    "shard_1": {"host": "localhost", "port": 5432, "user": "admin", "password": "password123", "db": "shard1_db"},
    "shard_2": {"host": "localhost", "port": 5433, "user": "admin", "password": "password123", "db": "shard2_db"},
    "shard_3": {"host": "localhost", "port": 5434, "user": "admin", "password": "password123", "db": "shard3_db"},
}

class ConsistentHashRing:
    """
    Handles the mathematical distribution of keys across shards.
    Uses Virtual Nodes (vnodes) to prevent 'hot spots' and ensure even distribution.
    """
    def __init__(self, nodes, vnodes_per_node=100):
        self.ring = {}  # Map: Hash Value -> Node Name
        self.sorted_keys = []  # Sorted list of Hash Values
        self.vnodes = vnodes_per_node
        
        for node in nodes:
            self.add_node(node)

    def _hash(self, key):
        """Returns a large integer hash of the key using MD5."""
        return int(hashlib.md5(key.encode('utf-8')).hexdigest(), 16)

    def add_node(self, node):
        """Adds a physical node (shard) to the ring with multiple virtual points."""
        for i in range(self.vnodes):
            # Create a unique virtual node ID (e.g., "shard_1#0", "shard_1#1")
            virtual_id = f"{node}#{i}"
            hash_val = self._hash(virtual_id)
            
            self.ring[hash_val] = node
            bisect.insort(self.sorted_keys, hash_val)

    def get_node(self, key):
        """
        Determines which shard owns the given key.
        Finds the first node on the ring clockwise from the key's hash.
        """
        if not self.ring:
            return None
            
        hash_val = self._hash(key)
        
        # Binary search to find the position on the ring
        idx = bisect.bisect_right(self.sorted_keys, hash_val)
        
        # If we reach the end of the ring, wrap around to the start (Circle behavior)
        if idx == len(self.sorted_keys):
            idx = 0
            
        target_hash = self.sorted_keys[idx]
        return self.ring[target_hash]

class AsyncDatabaseManager:
    """
    Manages connection pools for all shards.
    """
    def __init__(self, config):
        self.config = config
        self.pools = {}

    async def connect(self):
        """Creates a connection pool for each shard."""
        print("Initializing connection pools...")
        for shard_name, conf in self.config.items():
            try:
                self.pools[shard_name] = await asyncpg.create_pool(
                    user=conf["user"],
                    password=conf["password"],
                    database=conf["db"],
                    host=conf["host"],
                    port=conf["port"],
                    min_size=5,
                    max_size=20
                )
            except Exception as e:
                print(f"Failed to connect to {shard_name}: {e}")
        
        # Initialize tables
        await self.init_tables()

    async def init_tables(self):
        """Ensures the data table exists on all shards."""
        create_table_sql = """
        CREATE TABLE IF NOT EXISTS user_data (
            key TEXT PRIMARY KEY,
            value TEXT,
            created_at TIMESTAMP DEFAULT NOW()
        );
        """
        for pool in self.pools.values():
            async with pool.acquire() as conn:
                await conn.execute(create_table_sql)

    async def close(self):
        """Gracefully closes all pools."""
        for pool in self.pools.values():
            await pool.close()

    async def write(self, shard_name, key, value):
        """Writes data to the specific shard."""
        pool = self.pools.get(shard_name)
        if not pool:
            return False
            
        async with pool.acquire() as conn:
            # Upsert logic (Insert, or Update if exists)
            await conn.execute("""
                INSERT INTO user_data (key, value) VALUES ($1, $2)
                ON CONFLICT (key) DO UPDATE SET value = $2
            """, key, value)
        return True

async def main():
    # 1. Initialize the Ring
    shard_names = list(SHARD_CONFIG.keys())
    ring = ConsistentHashRing(shard_names, vnodes_per_node=200) # Higher vnodes = smoother distribution
    
    # 2. Initialize Database Connections
    db_manager = AsyncDatabaseManager(SHARD_CONFIG)
    await db_manager.connect()
    
    print("\n--- STARTING LOAD TEST (10,000 Keys) ---")
    
    distribution_stats = defaultdict(int)
    tasks = []
    
    # 3. Simulate high-volume traffic
    for _ in range(10000):
        # Generate random data
        key = f"user_{uuid.uuid4().hex[:8]}"
        value = f"data_for_{key}"
        
        # Calculate routing
        target_shard = ring.get_node(key)
        distribution_stats[target_shard] += 1
        
        # Create async task (non-blocking)
        tasks.append(db_manager.write(target_shard, key, value))
    
    # Execute all 10,000 writes concurrently
    await asyncio.gather(*tasks)
    
    print("--- LOAD TEST COMPLETE ---\n")
    
    # 4. Print Distribution Report
    print("Shard Distribution Report:")
    total = sum(distribution_stats.values())
    for shard, count in sorted(distribution_stats.items()):
        percentage = (count / total) * 100
        print(f"  {shard}: {count} keys ({percentage:.2f}%)")
        
    await db_manager.close()

if __name__ == "__main__":
    asyncio.run(main())