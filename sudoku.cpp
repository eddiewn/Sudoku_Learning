#include <iostream>
#include <vector>

#include "functions.h"

int main(){
    std::cout << "Welcome to Sudoku!! " << std::endl << std::endl;
    
    std::vector<std::vector<int>> sudokuMap = initializeSudokuMap();
    printSudokuBoard(sudokuMap);
    return 0;
}