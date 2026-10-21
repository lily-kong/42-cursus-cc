*This project has been created as part of the 42 curriculum by yakong.*

# get_next_line

## Description

`get_next_line()` is a C function that reads a file or standard input one line at a time. It returns the next line on each call, including `\n` if present, and returns `NULL` when there is no more data to read or an error occurs.

## Instructions

### Compilation

This function is not a standalone program. Its source files must be compiled as part of another project.

`main.c` is an example test file and must be provided separately.

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` defines the number of bytes read per call to `read()`. Its default value is 42, but it can be changed at compilation time using `-D BUFFER_SIZE=n`.

For example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1337 \
main.c get_next_line.c get_next_line_utils.c
```

### Execution

Call `get_next_line()` with a valid file descriptor to read its input one line at a time. The file descriptor can refer to a file or standard input. Each returned line must be freed by the caller after use.

For example, after compiling the test program, run it with:

```bash
./a.out
```

## Algorithm and Data Structure

### Algorithm

1. Read data from the file descriptor in chunks using `read()`.
2. Append the data to `stash` until a newline is found or EOF is reached.
3. Extract the next line from `stash`, including the newline character if present.
4. Preserve any remaining data in `stash` for the next call.
5. Return the extracted line, or `NULL` if no data remains or an error occurs.

### Data Structure

A static pointer named `stash` stores accumulated input between calls, preserving unread characters after a line is extracted.

### Justification

This approach prevents data from being lost when a single read operation retrieves multiple lines.

## Error Handling and Edge Cases

- Read errors: If `read()` fails, the function returns `NULL`.
- Empty files: If the file contains no data, the function returns `NULL`.
- Final line without a newline: If the last line does not end with `\n`, the function returns the remaining data before returning `NULL`.
- Buffer size: `BUFFER_SIZE` determines the number of bytes requested by each call to `read()` and must be a valid positive value.

## Resources

- [Dynamic memory management - cppreference.com](https://en.cppreference.com/c/memory)
- [read(2) - Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html)

### AI Usage

Used AI to clarify documentation and translation issues, help write parts of this README, and assist in testing edge cases.
