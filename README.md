# Conway's Game of Life Simulation

## Introduction
This C++ program implements Conway's Game of Life, a cellular automaton devised by mathematician John Conway. The Game of Life is a zero-player game known for its ability to generate complex patterns and behaviors from simple rules.

## Features
- **Random and Manual Initialization:** Fill the matrix randomly or manually with 0s and 1s.
- **Stabilization Patterns:** Visualize stabilization matrices for predefined patterns such as bloc, tube, bateau, ruche, and homefone.
- **Game of Life Simulation:** Simulate the evolution of the matrix based on Conway's rules for a specified number of generations.
- **Stability Check:** Check for stability by comparing the current state with a previously backed-up state.
- **Windows Console Color Setting:** Utilizes the `termcolor` library for console color management.

## Usage
1. Choose an option:
   - Fill the matrix randomly (specify the percentage of cells to fill).
   - Manually fill the matrix.
   - Visualize stabilization matrices for predefined patterns.
   - Exit the program.

2. If simulating the Game of Life:
   - Specify the number of generations.
   - Watch the evolution of the matrix.

3. Additional options allow you to visualize stabilization for specific patterns over a specified number of generations.

## How to Run
1. Compile the C++ code.
   ```bash
   g++ -o game_of_life game_of_life.cpp -std=c++11 -ltermcolor
   ./game_of_life

Example
To fill the matrix randomly:
Please choose your option:
1 - Fill the matrix randomly
2 - Fill the matrix manually
3 - Show stabilization matrices
0 - Exit
> 1
How much do you want to fill? (Enter percentage)
> 30
Enter the number of generations:
> 10
...

## License
This project is licensed under the MIT License.

## Acknowledgments
 - The termcolor library used for console color management.
 - Inspired by Conway's Game of Life.

