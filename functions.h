#include <iostream>
#include <vector>

// Creates a filled 9x9 sudoku board
std::vector<std::vector<int>> initializeSudokuMap();

// Prints out the sudoku board to terminal
void printSudokuBoard(const std::vector<std::vector<int>>& sudokuMap);

std::vector<std::vector<int>> unsolvedSudokuBoard(std::vector<std::vector<int>>& sudokuMap, int removeAmount);