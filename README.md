# 15-Puzzle — Console Sliding Tile Game in C

A classic **15-puzzle** built in C as a terminal game. Sixteen tiles sit on a 4×4 board: numbered 1 through 15, plus one empty space. Shuffle the board, then slide tiles until every number is in order from top-left to bottom-right, with the blank in the bottom-right corner.

This is my first C project — about a week into learning the language — and a fun way to practice arrays, loops, and user input in the terminal.

## How to Play

Slide tiles by moving the blank space with **WASD**:

| Key | Action |
|-----|--------|
| `W` | Move blank up |
| `S` | Move blank down |
| `A` | Move blank left |
| `D` | Move blank right |
| `Q` | Quit |

The game tracks your move count and prints **YOU WON** when the board matches the solved layout.

## Build & Run

```bash
cd code
gcc c-program.c -o slide-puzzle
./slide-puzzle
```

On Windows:

```bash
cd code
gcc c-program.c -o slide-puzzle.exe
slide-puzzle.exe
```

## License

MIT — see [LICENSE](LICENSE).
