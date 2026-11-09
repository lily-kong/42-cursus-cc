#!/usr/bin/env python3

import sys
from typing import IO

if len(sys.argv) == 2:

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")

    try:
        file: IO[str] = open(sys.argv[1], "r")
        print("---")
        print()
        print(file.read())
        print("---")
        file.close()
        print(f"File '{sys.argv[1]}' closed.")
    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")

else:
    print("Usage: ft_ancient_text.py <file>")
