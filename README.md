# 24-Puzzle Game 

A console-based implementation of the classic **24-Puzzle Game** using C++. Built with C++ standard libraries, this game challenges players to arrange a shuffled 5x5 grid of numbered tiles (1–24) into the correct sequence by sliding tiles into an empty space.

---

## 🕹️ How to Play

- The game starts with a random shuffled board.
- The goal is to arrange the tiles in order from 1 to 24, with the last cell empty (0).
- Use the following keys to move the empty space (0):
  - `u` → Move Up
  - `d` → Move Down
  - `l` → Move Left
  - `r` → Move Right

Legal moves are displayed before each turn.

---

## 🧠 Game Features

- Random and solvable board generation
- Move counter saved and loaded from `movesplayed.txt`
- Clear UI rendered in the console using ASCII characters
- Color-coded console text (Windows only)
- Credits screen and main menu

---

## 📂 File Structure

```bash
24-puzzle/
│
├── main.cpp          # Complete C++ source code
├── movesplayed.txt   # Stores move count from the last session
└── README.md         # This file
