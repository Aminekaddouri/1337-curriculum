# get_next_line

> Read a line from a file descriptor — one line at a time.

A C function that reads a line (ending with `\n` or EOF) from a file descriptor using a static buffer, handling partial reads and multiple file descriptors. A deep dive into buffer management, dynamic memory, and static variables.

---

### 🛠️ Features

- Reads one line at a time from any file descriptor (`files`, `stdin`, etc.)
- Uses a **static buffer** to preserve state across calls
- Handles multiple file descriptors simultaneously
- Efficiently manages memory with `malloc` and `free`
- Compatible with any `BUFFER_SIZE` (tested with 1, 42, 9999, etc.)

---

### 🧰 Tech Stack
- **Language**: C
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror -D BUFFER_SIZE=n`
- **Standard**: C89 (no global variables, no `lseek`)
