# cub3D

> A 3D raycaster game inspired by Wolfenstein 3D — built from scratch in C.

A graphical simulation that renders a 3D view of a maze from a first-person perspective using **raycasting**. This project combines mathematics, computer graphics, and low-level C programming to create a dynamic and immersive environment.

---

### 🛠️ Features

#### ✅ **Mandatory Part**
- **Raycasting Engine**: Calculates wall distances and heights for realistic 3D perspective
- **Textured Walls**: North, South, East, and West walls use different textures (loaded from `.xpm` files)
- **Map Parsing**: Reads a `.cub` configuration file containing:
  - Texture paths (`NO`, `SO`, `WE`, `EA`)
  - Floor and ceiling colors (`F`, `C`)
  - Map layout with player spawn (`N`, `S`, `E`, `W`)
- **Player Controls**:
  - Move forward/backward and strafe with **WASD**
  - Rotate camera with **left/right arrow keys**
- **Map Validation**:
  - Ensures the map is closed with walls
  - Validates player spawn (exactly one)
  - Checks for invalid characters or missing elements
- **Error Handling**: Exits cleanly with `Error\n` and an explicit message on invalid input

#### ✅ **Bonus Part Implemented**
- **Wall Collision Detection**: Prevents the player from walking through walls
- **Minimap System**: Displays a real-time 2D top-down view of the map with player position and orientation
- **Doors**: Openable/closable doors with animation and interaction
- **Animated Sprites**: Enemies or collectibles with frame-by-frame animation
- **Mouse Look**: Rotate the camera using the mouse for smoother control
- **Ceiling & Floor Textures**: Instead of flat colors, both ceiling and floor are textured
- **HUD & Effects**: Includes a health bar, weapon sprite, and visual effects (e.g., shadows, flickering lights)

---

### 🧰 Tech Stack
- **Language**: C
- **Graphics**: MLX42 (MiniLibX)
- **Math**: Raycasting, distance calculation, texture mapping
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror -lm`
- **Standard**: C89
- **External Functions**: `open`, `close`, `read`, `write`, `malloc`, `free`, `gettimeofday`, `perror`, `strerror`, `exit`, and all `math.h` functions
- **Libft**: Used for string utilities (copied into `libft/` folder)
