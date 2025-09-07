# ft_printf

> Recreating `printf` from scratch — a deep dive into variadic functions and C formatting.

A C library function that mimics the behavior of the standard `printf()` function, reimplemented from scratch. This project focuses on understanding how variadic arguments work in C and how format specifiers are parsed and handled.

---

### 🛠️ Features (Mandatory)

- Implements the core `ft_printf` function with support for the following conversions:
  - `%c` – Print a single character
  - `%s` – Print a string
  - `%p` – Print a pointer address in hexadecimal
  - `%d`, `%i` – Print signed decimal integers
  - `%u` – Print unsigned decimal integers
  - `%x` – Print hexadecimal in lowercase
  - `%X` – Print hexadecimal in uppercase
  - `%%` – Print a literal percent sign
- Uses `va_list`, `va_start`, `va_arg`, `va_copy`, `va_end` to handle variable arguments
- Returns the number of characters printed (like the original `printf`)
- No use of external libraries — pure C implementation
- Complies with C89 standards and `-Wall -Wextra -Werror`

---

### 🧰 Tech Stack
- **Language**: C
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89 (no C99 features)
- **Dependencies**: None (uses only allowed functions)
