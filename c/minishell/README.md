# minishell

> A fully functional Unix shell in C — your own little Bash.

A C program that mimics the behavior of a Unix shell like `bash`. This project demonstrates deep understanding of **process management**, **file descriptors**, **parsing**, and **system calls**. Implements all mandatory features and advanced bonus functionality.

---

### 🛠️ Features

#### ✅ **Mandatory Part**
- **Command Execution**: Parses and executes external commands (e.g., `ls`, `grep`, `cat`)
- **Built-in Commands**:
  - `echo` (with `-n` option)
  - `cd` (absolute and relative paths)
  - `pwd` (no options)
  - `export` (no options)
  - `unset` (no options)
  - `env` (no arguments)
  - `exit` (no options)
- **Pipes (`|`)**: Chains commands with proper file descriptor management
- **Redirections**:
  - `<` : Input redirection
  - `>` : Output redirection (truncate)
  - `>>` : Output redirection (append)
- **Signal Handling**:
  - `Ctrl+C` → New prompt (SIGINT)
  - `Ctrl+D` → Exit shell (EOF)
  - `Ctrl+\` → Ignored (SIGQUIT)
- **Quoting & Escaping**:
  - `'` (single quotes): Prevents all interpretation
  - `"` (double quotes): Prevents interpretation except for `$` (variable expansion)
  - `$?` : Expands to exit status of last command
  - `$$` : Expands to shell PID

#### ✅ **Bonus Part Implemented**
- **Logical Operators**: `&&` and `||` with support for parentheses `( )` to manage execution order
- **Wildcard Expansion**: `*` expands to matching files in the current directory
- **Hereditary Environment**: Environment variables are inherited and modifiable via `export`
- **Advanced Parsing**: Handles complex nested commands and operator precedence

---

### 🧰 Tech Stack
- **Language**: C
- **Core Concepts**: `fork`, `execve`, `pipe`, `dup2`, `signal`, `waitpid`
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89
- **External Functions**: `malloc`, `free`, `write`, `access`, `stat`, `opendir`, `getcwd`, `strerror`, `rl_*` (readline)
- **Libft**: Used for string utilities (copied into `libft/` folder)
