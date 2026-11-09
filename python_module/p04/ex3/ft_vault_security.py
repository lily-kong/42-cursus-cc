#!/usr/bin/env python3

def secure_archive(
    file_name: str,
    operation_type: str | None = None,
    content: str | None = None
) -> tuple[bool, str]:

    if operation_type == "r":
        try:
            with open(file_name, "r") as file:
                file_content = file.read()
            return (True, file_content)
        except (FileNotFoundError, PermissionError) as e:
            return (False, f"{e}")

    elif operation_type == "w":
        try:
            with open(file_name, "w") as file:
                if content is not None:
                    file.write(content)
            return (True, "Content successfully written to file")
        except (FileNotFoundError, PermissionError) as e:
            return (False, f"{e}")

    return (False, "Operation Type Error: Please use 'r' or 'w'")


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", "r"))
    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("master.passwd", "r"))
    print()
    print("Using 'secure_archive' to read from a regular file:")
    print(secure_archive("ancient_fragment.txt", "r"))
    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_file.txt", "w", "content"))
