*This project has been created as part of the 42 curriculum by nedo-nas.*

# Ft_printf

## Description

Welcome to `ft_printf`, a project where we embark on the exciting journey of recreating the standard C library function `printf()`. This isn't just about copying; it's about understanding the magic behind one of C's most versatile functions. Our primary **goal** is to develop a robust and functional version of `printf()` that can handle a variable number of arguments, mirroring the behavior of the original. This project will deepen your understanding of **variadic functions** in C, a powerful feature that allows functions to accept a flexible number of arguments, making `ft_printf` incredibly adaptable.

## Instructions

To get `ft_printf` up and running and integrate it into your projects, follow these steps:

### 1. Compile the Library

Navigate into the `ft_printf` directory and compile the static library `libftprintf.a` using the provided `Makefile`:

```bash
make
```

This command will generate `libftprintf.a` in the root of your project directory, which you can then link against your own C programs.

### 2. Integrate and Use in Your Project

To use `ft_printf` in your C projects, you need to include its header file and link against the compiled library. Here's how:

#### Include the Header

Add the `ft_printf.h` header to your source files:

```c
#include "ft_printf.h"
```

#### Compile Your Program

When compiling your C source files, ensure you link with `libftprintf.a`. For example:

```bash
gcc your_program.c -L. -lftprintf -o your_program
```

Replace `your_program.c` with your actual source file and `your_program` with your desired executable name.

#### Run Your Program

Execute your compiled program:

```bash
./your_program
```

#### Example Usage

Here's a quick example demonstrating how to use `ft_printf`:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s! The answer is %d, and a character is %c.\n", "world", 42, 'A');
    ft_printf("Characters printed: %d\n", count);
    count = ft_printf("Hexadecimal: %x (lowercase), %X (uppercase)\n", 255, 255);
    ft_printf("Characters printed: %d\n", count);
    count = ft_printf("Pointer address: %p\n", &count);
    ft_printf("Characters printed: %d\n", count);
    return (0);
}
```

## Features

Our `ft_printf` implementation supports the following conversion specifiers:

*   `%c`: Prints a single character.
*   `%s`: Prints a string (as defined by the common C convention).
*   `%p`: The `void *` pointer argument has to be printed in hexadecimal format.
*   `%d`: Prints a decimal (base 10) number.
*   `%i`: Prints an integer in base 10.
*   `%u`: Prints an unsigned decimal (base 10) number.
*   `%x`: Prints a number in hexadecimal (base 16) lowercase format.
*   `%X`: Prints a number in hexadecimal (base 16) uppercase format.
*   `%%`: Prints a percent sign.

## Algorithm Explanation

The main function iterates through the input string character by character until it encounters a `%` symbol. When this happens, it delegates control to a helper function responsible for validating the format specifier.

This function (e.g., `check_type`) analyzes the character immediately following `%` and verifies whether it belongs to the set of valid conversion specifiers:

If a valid specifier is found, the corresponding function is called:

- `c` → `ft_putchar`
- `s` → `ft_putstr`
- `p` → `ft_puthex` (pointer address in hexadecimal)
- `d` / `i` → `ft_putnbr` (decimal integers)
- `x` / `X` → `print_nbr_hex` (hexadecimal numbers, lowercase or uppercase)

Each of these functions is responsible for:
1. Printing the formatted argument
2. Returning the number of characters printed

This return value is accumulated to keep track of the total number of printed characters, mimicking the behavior of the original `printf`.

In cases where a `NULL` argument is passed (e.g., for strings), the function outputs `(null)` instead of causing undefined behavior.

## Function Prototypes

Below are the prototypes of the main functions used in the implementation:

```c

int	ft_printf(const char *format, ...);

int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_puthex(void *s);
int	printf_nbr_hex(unsigned int nb, char *s);
int	ft_putnbr_unsigned(unsigned int n);

```

## Resources

This project was developed with the assistance of an AI. And the AI was used for:

*   **Initial README Generation:** Creating the first draft of this `README.md` based on the project subject.
*   **Refactoring and Structuring:** Reorganizing and refining the content to meet specific formatting and section requirements, ensuring clarity and adherence to guidelines.

Classic references related to the topic:

*   [The C Standard Library](https://en.wikipedia.org/wiki/C_standard_library)
*   [Variadic functions in C](https://en.wikipedia.org/wiki/Variadic_function)
*   [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
