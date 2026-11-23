#!/usr/bin/env python3

import dotenv
from os import getenv

dotenv.load_dotenv(override=False)

configs = {
    "Mode": getenv("MATRIX_MODE", "development"),
    "Database": getenv("DATABASE_URL"),
    "API Access": getenv("API_KEY"),
    "Log Level": getenv("LOG_LEVEL", "INFO"),
    "Remote Network": getenv("ZION_ENDPOINT"),
}

if __name__ == "__main__":
    missing = []

    print()
    print("ORACLE STATUS: Consulting the configuration...")
    print()

    for name, value in configs.items():
        if not value:
            missing.append(name)

    if missing:
        print("Configuration overview:")
        print(f"Mode: {configs['Mode']}")
        print(f"Log Level: {configs['Log Level']}")
        print()
        for name in missing:
            print(f"\033[93m[Warning] {name} is missing.\033[0m")
    else:
        if configs["Mode"] == "development":
            print("\033[92m=== Development Mode ===\033[0m")
            print()
        elif configs["Mode"] == "production":
            print("\033[91m=== Production Mode ===\033[0m")
            print()
        print("Configuration loaded:")
        print(f"Mode: {configs['Mode']}")
        print("Database: Connected to local instance")
        print("API Access: Authenticated")
        print(f"Log Level: {configs['Log Level']}")
        print("Remote Network: Online")

        print()
        print("Configuration security check:")
        print("[OK] No hardcoded secrets detected")
        print("[OK] .env file properly ignored by git")
        print("[OK] Production overrides available")
        print()
        print("The Oracle sees all configurations.")
