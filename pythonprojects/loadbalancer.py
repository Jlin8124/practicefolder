#Program to create infrastructure for app
#installed aiohttp library to be a server and a client at same time (using aysncio)

import asyncio
import hashlib
import bisect
import os
from aiohttp import web, ClientSession
from typing import List, Dict, Set
from typing import Dict

# --- Configuration ---
BACKEND_SERVERS = [
    "http://localhost:8081",
    "http://localhost:8082",
    "http://localhost:8083"
]   
HEALTH_CHECK_INTERVAL = 5
HEALTH_CHECK_TIMEOUT = 2 

#SECURITY: Prevents Hash Flooding/DOS
HASH_SALT = os.environ.get("LB_SALT", "my_super_secret_salt_2026")

class ConsistentHashRing:
    def __init__(self, virtual_nodes=100):
        #typehints to make the code - self documenting
        self.ring: dict[int, str] = {} # Maps Hash -> Server URL
        self.sorted_keys: list[int] = [] # Sorted list of hashes
        self.virtual_nodes = virtual_nodes
        #tracking real server URLS just to know who is currently in the ring
        self.active_servers: Set[str] = set()


        
        #sort only once at the end
        self.sorted_keys.sort()
        
    def _hash(self, key: str) -> int:

        #Aware of potential DOS attacks so we need to have a secret key
        #Should be loaded from an environment variable
        salted_input = key + HASH_SALT
        return int(hashlib.md5(salted_input.encode('utf-8').hexdigest(), 16))
    def add_server(self, server_url):
        """Adds a server with 100 virtual nodes for even distribution."""
        if server_url in self.active_servers:
            return# Already added

        for i in range(self.virtual_nodes):
            virtual_key = f"{server_url}#{i}"
            key = self._hash(virtual_key)
            self.ring[key] = server_url
            bisect.insort(self.sorted_keys, key)
        
        self.active_servers.add(server_url)
        print(f" + Added {server_url} to ring.")

async def main():
    print('Hello')
    await asyncio.sleep(1)
    print('...World!')

