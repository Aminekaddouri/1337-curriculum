# so_long

> A 2D puzzle game where the player collects all items and reaches the exit.

A C program that implements a simple 2D game using **MiniLibX (MLX42)**. The player must collect all collectibles (`C`) on the map before reaching the exit (`E`). The game runs in a graphical window with real-time movement and step counting.

---

### 🛠️ Features

- **Map Loading**: Reads a `.ber` map file from the command line
- **Map Validation**: Ensures the map is rectangular, surrounded by walls (`1`), and contains:
  - Exactly one player (`P`)
  - At least one collectible (`C`)
  - Exactly one exit (`E`)
- **Player Movement**: Move with **WASD** or **Arrow keys**
- **Collectibles**: All must be collected before the exit can be used
- **Step Counter**: Displays the number of moves the player has made
- **Win Condition**: Player reaches the exit only after collecting all items
- **Error Handling**: Exits cleanly with `Error\n` and an explicit message if the map is invalid or file is missing

---

### 🧰 Tech Stack
- **Language**: C
- **Graphics**: MLX42 (MiniLibX)
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89
- **Input**: Keyboard events via MLX42
