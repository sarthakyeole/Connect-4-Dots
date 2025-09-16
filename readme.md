# 🎮 Connect Four (C Project)

A terminal-based implementation of the classic **Connect Four** game written in **C**.  
This project demonstrates **clean modular design**, separation of logic/UI, and structured coding practices.

A simple terminal-based Connect 4 game implemented in C.

## Features

- Two-player gameplay
- Simple UI in the terminal
- Easy to build and run

## Getting Started

Clone the repository:

```bash
git clone https://github.com/your-username/Connect-4-Dots.git
cd Connect-4-Dots/src
```

## Build Instructions

Compile the game using gcc:

```bash
gcc -o connect4 main.c game.c ui.c
```

## Project Structure

```
Connect-4-Dots/
├── src/        # Source code files
│   ├── main.c
│   ├── game.c
│   ├── game.h
│   └── ui.c
├── assets/     # Images and other assets
│   └── image.png
└── readme.md
```

## Author

Sarthak Yeole

## Game Winning

- Win detection for horizontal, vertical, and diagonal lines.

## Example Gameplay

```
CONNECT 4 (Move 5)

⚫ ⚫ ⚫ ⚫ ⚫ ⚫ ⚫
⚫ ⚫ ⚫ ⚫ ⚫ ⚫ ⚫
⚫ ⚫ ⚫ ⚫ ⚫ ⚫ ⚫
⚫ ⚫ ⚫ ⚫ ⚫ ⚫ ⚫
⚫ ⚫ 🔴 ⚫ ⚫ ⚫ ⚫
⚫ 🟡 🔴 🟡 ⚫ ⚫ ⚫

PLAYER 1
Enter a column between 1 and 7:
```

⚫ ⚫ ⚫ ⚫ ⚫ ⚫ ⚫
⚫ ⚫ 🔴 ⚫ ⚫ ⚫ ⚫

---

PLAYER 1
Enter a column between 1 and 7:
