#!/usr/bin/env python3

import sys
from typing import IO

if len(sys.argv) != 2:
    print("Usage: ft_ancient_text.py <file>")

else:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{sys.argv[1]}'")

    try:
        file: IO[str] = open(sys.argv[1], "r")
        content = file.read()
        file.close()
        print("---\n")
        print(content)
        print("---")
        print(f"File '{sys.argv[1]}' closed.")

        new_content = ""
        for line in content.splitlines():
            # "+=" means adding new content to the existing new_content string
            new_content += line + "#\n"

        print()
        print("Transform data:")
        print("---\n")
        print(f"{new_content}")
        print("---")

        user_input = input("Enter new file name (or empty): ")

        if not user_input:
            print("Not saving data.")

        else:
            print(f"Saving data to '{user_input}'")
            new_file: IO[str] = open(user_input, "w")
            new_file.write(new_content)
            new_file.close()
            print(f"Data saved in file '{user_input}'.")

    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
