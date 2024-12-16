# Cub3D

Cub3D is a 3D game project inspired by the classic **Wolfenstein 3D**. It utilizes **raycasting** to simulate a 3D environment in a 2D world. This project demonstrates the fundamentals of graphical programming to offer an immersive experience in a maze-like environment.

## Project Objective

Cub3D aims to develop a simple yet effective 3D rendering engine using raycasting to simulate realistic perspectives. Key features include:
- A smooth 3D rendering engine.
- Navigation through a maze-like space.
- Texture integration and collision management.

---

## Features

### 3D Rendering with Raycasting
- Realistic display based on 2D projection calculations.
- Simulation of walls, textures, and perspectives.
- Precise collision detection for player movement.

### Navigation System
- Smooth forward, backward, and rotation movement.
- Keyboard and/or mouse interaction for player control.

### Textures and Colors
- Support for custom textures on walls.
- Configurable ceiling and floor colors.

### Flexible Configuration
- Load custom maps via `.cub` files.
- Easy to add and modify levels.

### Optimization and Error Handling
- Optimized rendering with efficient calculations.
- Rigorous checks for configuration files and maps.

---

## How to Build and Run

### Prerequisites
- **Compiler**: C with `gcc` or `clang` support.
- **Make**: For building the project.

### Build Instructions

Clone the repository:

```bash
git clone https://github.com/Nerada00/Cub3D.git
cd Cub3D
```
Compile the project:
```bash
make
```
Run the game:
```bash
./cub3d <map_file.cub>
```
### Controls

Once the game is running, you can control the player using the following keyboard inputs:

    W: Move forward.
    S: Move backward.
    A: Move left.
    D: Move right.
    Arrow keys: Rotate the camera view.

### Map Format

Maps are defined in .cub files. Each file contains:

    Textures: For the walls, floor, and ceiling.
    Map layout: Describes the maze using a grid of characters (e.g., '1' for walls, '0' for empty space).
    Resolution: Defines the window size for the game.


## Licence

This project is licensed under the MIT License. See the LICENSE file for more information.
