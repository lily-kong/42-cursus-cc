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
            new_content += line + "#\n"

        print()
        print("Transform data:")
        print("---\n")
        print(f"{new_content}")
        print("---")

        sys.stdout.write("Enter new file name (or empty): ")
        sys.stdout.flush()
        user_input = sys.stdin.readline().strip()

        if not user_input:
            print("Not saving data.")

        else:
            print(f"Saving data to '{user_input}'")
            try:
                new_file: IO[str] = open(user_input, "w")
                new_file.write(new_content)
                new_file.close()
                print(f"Data saved in file '{user_input}'.")
            except PermissionError as e:
                sys.stderr.write(
                    f"[STDERR] Error opening file '{user_input}': {e}\n"
                    "Data not saved.\n"
                )

    except (FileNotFoundError, PermissionError) as e:
        sys.stderr.write(f"[STDERR] Error opening file '{sys.argv[1]}': {e}\n")
