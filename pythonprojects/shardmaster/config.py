"""
Database Configuration Module
==============================

This module handles loading database shard configurations from environment variables.
All sensitive credentials (passwords, hostnames) are stored in a .env file and never commited to version control

Required Environment Variables:
    POSTGRES_USER: Database username (shared across all shards)
    POSTGRES_PASSWORD: Database password (shared across all shards)
    SHARD1_HOST: Hostname for shard 1 (default: localhost)
    SHARD1_PORT: Port for shard 1 (default: 5432)
    SHARD1_DB: Database name for shard 1 (default: shard1_db)
    SHARD2_HOST: Hostname for shard 2 (default: localhost)
    SHARD2_PORT: Port for shard 2 (default: 5433)
    SHARD2_DB: Database name for shard 2 (default: shard2_db)
    SHARD3_HOST: Hostname for shard 3 (default: localhost)
    SHARD3_PORT: Port for shard 3 (default: 5434)
    SHARD3_DB: Database name for shard 3 (default: shard3_db)

Usage:
    from config import SHARD_CONFIG
    
    # Access a specific shard's configuration
    shard1_host = SHARD_CONFIG["shard_1"]["host"]
    
    # Pass entire config to database manager
    db_manager = AsyncDatabaseManager(SHARD_CONFIG)

Example .env file:
    POSTGRES_USER=admin
    POSTGRES_PASSWORD=your_secure_password
    SHARD1_PORT=5432
    SHARD2_PORT=5433
    SHARD3_PORT=5434
"""

import os
from dotenv import load_dotenv
from typing import Dict, Any

load_dotenv()

password = os.getenv("DB_PASSWORD")
user = os.getenv("DB_USER")

def load_config() -> Dict[str, Dict[str, any]]:

    return {
        "shard_1": {
            "host": os.getenv("SHARD1_HOST", "localhost"),
            "port": int(os.getenv("SHARD1_PORT", "5432")),
            "user": os.getenv("POSTGRES_USER"),
            "password": os.getenv("POSTGRES_PASSWORD"),
            "db": os.getenv("SHARD1_DB", "shard1_db"),
        },
        "shard_2": {
            "host": os.getenv("SHARD2_HOST", "localhost"),
            "port": int(os.getenv("SHARD2_PORT", "5433")),
            "user": os.getenv("POSTGRES_USER"),
            "password": os.getenv("POSTGRES_PASSWORD"),
            "db": os.getenv("SHARD2_DB", "shard2_db"),
        },
        "shard_3": {
            "host": os.getenv("SHARD3_HOST", "localhost"),
            "port": int(os.getenv("SHARD3_PORT", "5434")),
            "user": os.getenv("POSTGRES_USER"),
            "password": os.getenv("POSTGRES_PASSWORD"),
            "db": os.getenv("SHARD3_DB", "shard3_db"),
        },
    }

SHARD_CONFIG = load_config()
