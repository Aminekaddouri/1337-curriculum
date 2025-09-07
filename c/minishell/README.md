# minishell

> A fully functional Unix shell written in C — your own little Bash.

A C program that mimics the behavior of a Unix shell like `bash`. It parses commands, handles built-ins, manages processes, and supports pipes and redirections. Built to understand how shells work under the hood.

---

### 🛠️ Features (Mandatory)

- **Interactive Prompt**: Displays a prompt (`> `) and reads commands from the user.
- **Command Execution**: Runs executables using `PATH` lookup or absolute/relative paths.
- **Built-in Commands**:
  - `echo` (with `-n` option)
  - `cd` (absolute and relative paths)
  - `pwd` (without options)
  - `export` (without options)
  - `unset` (without options)
  - `env` (without arguments)
  - `exit` (with or without status)
- **Signal Handling**:
  - `Ctrl-C` → New prompt on a new line
  - `Ctrl-D` → Exits the shell
  - `Ctrl-\` → Ignored (no `SIGQUIT`)
- **Quoting & Escaping**:
  - `'` (single quotes): Prevents all interpretation
  - `"` (double quotes): Prevents interpretation except for `$`
  - `$?` expands to the exit status of the last command
  - `$VAR` expands environment variables
- **Redirections**:
  - `< file` → Input redirection
  - `> file` → Output redirection (truncate)
  - `>> file` → Output redirection (append)
  - `<< LIMIT` → Heredoc (reads until `LIMIT`)
- **Pipes** (`|`): Connects output of one command to input of the next
- **History**: Preserved across commands using `readline`
- **Error Handling**: Graceful errors for invalid syntax, missing files, etc.
- **Memory Safety**: No memory leaks in user code (valgrind-clean)

> ❌ **Bonus features** (`&&`, `||`, `*` wildcard) were **not implemented**.

---

### 🧰 Tech Stack
- **Language**: C
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89
- **Key Functions**: `fork`, `execve`, `pipe`, `dup2`, `waitpid`, `signal`, `sigaction`, `readline`, `getenv`
- **Libft**: Authorized and used
