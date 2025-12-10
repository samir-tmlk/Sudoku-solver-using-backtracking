# Sudoku-solver-using-backtracking
This program takes an unsolved Sudoku grid as input and fills in the missing numbers using a recursive backtracking approach. It checks for constraints (row, column, and 3x3 subgrid validity) to ensure the solution adheres to standard Sudoku rules.

# 🧩 Sudoku Solver (C Implementation)

A lightweight, efficient Sudoku solver written in C. This project reads Sudoku puzzles from text files and solves them using the Recursive Backtracking Algorithm.

## 📖 How It Works

This program uses a "Brute Force with Pruning" approach known as Backtracking.

### The Algorithm Logic

1.  Find Empty: The program scans the 9x9 grid to find the first empty cell (represented by `0`).
2.  Guess: It tentatively places a number (`1` through `9`) in that cell.
3.  Validate: It checks if the number is valid according to Sudoku rules:
      * Row Check: Is the number already in the current row?
      * Column Check: Is the number already in the current column?
      * Box Check: Is the number already in the current 3x3 sub-grid?
4.  Recurse:
      * If the number is valid, the function calls itself recursively to solve the next empty cell.
      * If the recursive call returns `true`, the puzzle is solved.
5.  Backtrack:
      * If the number leads to a dead end (no solution found for subsequent cells), the program resets the current cell to `0` (backtracks) and tries the next number.

-----

## 📂 Project Structure

  * `sudoku_solver.c`: The main source code containing the logic and entry point.
  * `Makefile`: Automation script to compile and run the project easily.
  * `sudoku.txt`: A text file containing the input puzzle to be solved.

-----

## ⚙️ Setup & Compilation

### Prerequisites

You need a C compiler (like `gcc`) and `make` installed.

  * Mac: Run `xcode-select --install` if you don't have them.
  * Linux: Usually installed by default (or install `build-essential`).
  * Windows: Use WSL, MinGW, or Cygwin.

### Compilation

To compile the project, simply open your terminal in the project folder and run:

```bash
make
```

This will generate an executable file named `sudoku_solver`.

-----

## 🚀 How to Test & Run

There are two ways to run the solver.

### Method 1: Automatic Run (Recommended)

We have configured the Makefile to compile and run the code with the default `sudoku.txt` file in one command:

```bash
make run
```
-----

## 📝 Input File Format

To test your own grids, edit the `sudoku.txt` file.
The format must consist of integers separated by commas, where `0` represents an empty cell.

Example content of `sudoku.txt`:

```text
5, 3, 0, 0, 7, 0, 0, 0, 0
6, 0, 0, 1, 9, 5, 0, 0, 0
0, 9, 8, 0, 0, 0, 0, 6, 0
8, 0, 0, 0, 6, 0, 0, 0, 3
4, 0, 0, 8, 0, 3, 0, 0, 1
7, 0, 0, 0, 2, 0, 0, 0, 6
0, 6, 0, 0, 0, 0, 2, 8, 0
0, 0, 0, 4, 1, 9, 0, 0, 5
0, 0, 0, 0, 8, 0, 0, 7, 9
```

-----

## 🧹 Cleaning Up

To remove the compiled executable (for example, if you want to force a fresh recompilation), run:

```bash
make clean
```
