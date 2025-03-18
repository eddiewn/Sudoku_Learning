#include <iostream>
#include "functions.h"

int main(){
    int gridSize;

    std::cout << "Welcome to Sudoku!! Enter grid size: ";
    std::cin >> gridSize;
    
    initializeSudokuMap(gridSize);
    printSudoku();

    return 0;
}