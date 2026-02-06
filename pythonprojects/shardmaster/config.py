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
