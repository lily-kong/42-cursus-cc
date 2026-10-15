*This project has been created as part of the 42 curriculum by yakong.*

# Description

The `libft` library reimplements standard C library functions and provides additional utilities for string manipulation, memory management, numeric conversion, output operations, and linked list management.

# Instructions

## Compilation

```bash
make
```
Compiles the source files and generates the static library libft.a.

```bash
make clean
```
Removes the object files (.o) generated during compilation.

```bash
make fclean
```
Removes the object files and the compiled library libft.a.

```bash
make re
```
Rebuilds the library from scratch by cleaning up the previous build files and recompiling the source files.

## Execution

To use the library in your C project, include the appropriate header file and link libft.a during compilation.

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o your_program
./your_program
```

## Library Functions

### 1. Character Classification and Conversion

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is an alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII character set. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

### 2. String Manipulation

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strlcpy` | Copies a string with a specified size limit. |
| `ft_strlcat` | Appends a string with a specified size limit. |
| `ft_strdup` | Creates a duplicate of a string. |
| `ft_substr` | Extracts a substring. |
| `ft_strjoin` | Concatenates two strings into a new string. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string using a delimiter character. |
| `ft_strmapi` | Creates a new string by applying a function to each character. |
| `ft_striteri` | Applies a function to each character of a string by index. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strnstr` | Searches for a substring within a string, up to a specified length. |

### 3. Memory Management and Manipulation

| Function | Description |
|---|---|
| `ft_memset` | Fills a memory block with a specified byte value. |
| `ft_bzero` | Sets a memory block to zero. |
| `ft_memcpy` | Copies a memory block. |
| `ft_memmove` | Copies a memory block while handling overlapping regions. |
| `ft_memchr` | Searches for a byte in a memory block. |
| `ft_memcmp` | Compares two memory blocks. |
| `ft_calloc` | Allocates memory for an array and initializes it to zero. |

### 4. Numeric Conversion

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an integer. |
| `ft_itoa` | Converts an integer to a string. |

### 5. File Descriptor Output

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### 6. Linked List Management

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new linked list node. |
| `ft_lstadd_front` | Adds a node to the beginning of a list. |
| `ft_lstsize` | Counts the nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Deletes one node using a specified deletion function. |
| `ft_lstclear` | Deletes a list and frees its nodes. |
| `ft_lstiter` | Applies a function to each node's content. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

# Resources

- man 3: Manual pages for C library functions.
- Linux man-pages project: Documentation for Linux system calls and C library functions.

## AI Usage

Clarify translation issues in the manual and assist with writing parts of the README file.
