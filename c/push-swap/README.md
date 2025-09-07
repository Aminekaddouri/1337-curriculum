# push_swap

> A sorting algorithm challenge using two stacks and minimal moves.

A C program that calculates and displays the shortest sequence of operations needed to sort a stack of integers using a limited set of instructions. The goal is to sort the numbers in ascending order with the fewest possible moves.

---

### 🛠️ Features (Mandatory)

- **Stack-Based Sorting**: Uses two stacks (`a` and `b`) to reorganize integers.
- **Allowed Operations**:
  - `sa` / `sb` / `ss`: Swap top two elements
  - `pa` / `pb`: Push between stacks
  - `ra` / `rb` / `rr`: Rotate up
  - `rra` / `rrb` / `rrr`: Reverse rotate
- **Input Validation**:
  - Checks for invalid arguments (non-integers, duplicates, overflow)
  - Exits cleanly with `Error\n` if input is invalid
- **Efficient Algorithm**:
  - Implements a custom sorting strategy to minimize the number of operations
  - Successfully sorts:
    - 3 to 5 numbers: < 12 moves
    - 100 numbers: < 700 moves
    - 500 numbers: < 5500 moves

---

### 🧰 Tech Stack
- **Language**: C
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89
- **External Functions**: `write`, `read`, `malloc`, `free`, `exit`, `ft_printf` (custom)
- **Libft**: Authorized and used for `ft_printf`

---

### 📂 Build & Usage

```bash
make        # Compiles push_swap
