*This activity has been created as part of the 42 curriculum by raahouar.*

---

<div align="center">

```
███████╗████████╗    ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
██╔════╝╚══██╔══╝    ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
█████╗     ██║       ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗
██╔══╝     ██║       ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝
██║        ██║       ██║     ██║  ██║██║██║ ╚████║   ██║   ██║
╚═╝        ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝
```

**Reimplementing printf() — because ft_putnbr() and ft_putstr() aren't enough.**

![C](https://img.shields.io/badge/Language-C-blue?style=flat-square)
![42](https://img.shields.io/badge/School-42-black?style=flat-square)
![Norm](https://img.shields.io/badge/Norm-compliant-brightgreen?style=flat-square)
![Memory](https://img.shields.io/badge/Memory%20leaks-none-brightgreen?style=flat-square)

</div>

---

## Description

`ft_printf` is a reimplementation of the standard C library function `printf()`. The goal is to reproduce its core behavior using variadic functions (`va_list`, `va_arg`, `va_start`, `va_end`) without relying on any existing formatted output functions.

Like the original, `ft_printf` returns the **total number of characters written** to the standard output.

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (writes `(null)` if pointer is NULL) |
| `%p` | Prints a pointer address in hexadecimal format with `0x` prefix |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal lowercase format |
| `%X` | Prints a number in hexadecimal uppercase format |
| `%%` | Prints a literal percent sign |

---

## File Structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c          — ft_putchar, ft_write_all, ft_check, ft_printf
├── pourcent_cs.c        — %c and %s handlers
├── pourcent_uid.c       — %d, %i and %u handlers
├── pourcent_xx.c        — %x and %X handlers
└── pourcent_p.c         — %p handler
```

---

## Instructions

### Compilation

```bash
make
```

This generates the static library `libftprintf.a` at the root of the repository, compiled with `-Wall -Wextra -Werror`.

### Usage in your project

```c
#include "ft_printf.h"
```

```bash
cc your_file.c -L. -lftprintf -o your_program
```

### Makefile rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Full recompilation from scratch |

---

## Function Reference

### Core

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_printf` | `int ft_printf(const char *str, ...)` | Main entry point — parses the format string and dispatches each specifier |
| `ft_putchar` | `void ft_putchar(char c)` | Writes a single character to stdout |
| `ft_write_all` | `int ft_write_all(char *str)` | Writes a full string to stdout and returns the number of characters written |

### Conversion handlers

| Function | Specifier | Description |
|----------|-----------|-------------|
| `ft_pourcent_c` | `%c` | Extracts a `char` argument and writes it |
| `ft_pourcent_s` | `%s` | Extracts a `char *` argument and writes it |
| `ft_pourcent_id_init` | `%d` / `%i` | Extracts the `int` argument and calls the recursive handler |
| `ft_pourcent_id` | `%d` / `%i` | Recursively prints a signed integer in base 10 |
| `ft_pourcent_u_init` | `%u` | Extracts the `unsigned int` argument and calls the recursive handler |
| `ft_pourcent_u` | `%u` | Recursively prints an unsigned integer in base 10 |
| `ft_pourcent_xx_init` | `%x` / `%X` | Extracts the argument and selects the right character set |
| `ft_pourcent_xx` | `%x` / `%X` | Recursively prints an unsigned integer in base 16 |
| `ft_pourcent_ptr` | `%p` | Extracts the `unsigned long` pointer argument |
| `ft_pourcent_p` | `%p` | Recursively prints a pointer address in hexadecimal with `0x` prefix |

---

## Algorithm and Data Structure

### Parsing loop

`ft_printf` walks the format string character by character. When it encounters a `%`, it reads the next character and passes it to `ft_check`, which dispatches to the right handler. Every handler returns the number of characters it wrote, which is accumulated in `len` and returned as the final result.

### Why recursion for numeric conversions?

Recursion is a natural fit for digit extraction: dividing by the base and taking the remainder produces digits in reverse order. Placing `ft_putchar` **after** the recursive call prints digits in the correct left-to-right order without needing a temporary buffer or a reversal step.

Each recursive call returns its own character count, accumulated with `len +=` back up the call stack, ensuring the total is always correct.

```
ft_pourcent_u(432)
  └── ft_pourcent_u(43)       → recurse
        └── ft_pourcent_u(4)  → base case: write '4', return 1
        write '3', return 1 + 1 = 2
  write '2', return 2 + 1 = 3   ← total: 3 chars
```

### `va_list` handling

Each specifier has a thin `_init` wrapper that calls `va_arg` to extract the typed argument, then passes the concrete value to the recursive computation function. This clearly separates argument extraction from digit conversion logic, and avoids any undefined behavior from passing `va_list` across multiple function boundaries.

---

## Resources

- [C standard — `printf` specification (cppreference)](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions in C (cppreference)](https://en.cppreference.com/w/c/variadic)
- [write(2) man page](https://man7.org/linux/man-pages/man2/write.2.html)
- [stdarg.h reference](https://en.cppreference.com/w/c/variadic)

### Use of AI

AI (Claude, Anthropic) was used during this project strictly as a **debugging assistant and Socratic guide** — never to generate code directly. Specifically:

- Tracing execution flow of recursive functions to identify where character counts were being lost.
- Identifying a bug where `va_arg` was called with the wrong variable (`m` instead of `n`).
- Discussing correct behavior for edge cases (`%x` with `0`, `%p` with a null pointer).
- Writing this README (structure and formatting only).

All code was written, understood, and debugged by the author. AI was used to ask questions and verify reasoning, not to produce solutions.
