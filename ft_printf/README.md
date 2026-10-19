*This project has been created as part of the 42 curriculum by yakong.*

# ft_printf

## Description

The `libftprintf` library recreates the standard C `printf()` function. It prints formatted output and supports characters, strings, pointers, integers, and hexadecimal numbers.

### Example

```c
ft_printf("Hello %d %s\n", 42, "world");
```
Output:

```text
Hello 42 world
```

## Instructions

### Compilation

- `make`: Compiles the source files and creates `libftprintf.a`.
- `make clean`: Removes the object files.
- `make fclean`: Removes the object files and the library.
- `make re`: Cleans and rebuilds the library.

### Execution

To use the library in your C project, include the appropriate header file `ft_printf.h` and link libftprintf.a during compilation.

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -I includes -o your_program
./your_program
```

## Format Specifiers

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Algorithm and Data Structure

### Algorithm

The `ft_printf` function reads the format string from left to right.

- If the character is not `%`, it prints the character.
- If it finds `%`, `handle_format()` checks the format specifier and calls the correct function.
- Each helper function prints the given data and returns the number of characters printed.
- Finally, `ft_printf` returns the total number of characters printed.

### Data Structure

- The format string is stored in a character array.
- `va_list` is used to access the variable arguments passed to `ft_printf`.
- Helper functions handle different data types separately.

### Justification

This algorithm is simple and efficient. `va_list` allows the function to handle different numbers of arguments. Helper functions make the code easier to read and maintain.

## Resources

- [Variadic arguments - cppreference.com](https://en.cppreference.com/w/c/language/variadic)
- [printf(3) - Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) - Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)

### AI Usage

Used AI to clarify documentation and translation issues and to assist in writing parts of this README.
