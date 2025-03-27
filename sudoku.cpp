#include <iostream>
#include <vector>

#include "functions.h"

int main(){
    srand(time(0));

    std::cout << "Welcome to Sudoku!! " << std::endl << std::endl;
    
    //Sets sudokuMap to the vector
    std::vector<std::vector<int>> sudokuBoard = initializeSudokuMap();

    //Prints the original Sudokumap
    printSudokuBoard(sudokuBoard);

    std::vector<std::vector<int>> changedBoard = unsolvedSudokuBoard(sudokuBoard, 40);
    
    //Prints the changed unsolvedSudokuMap
    printSudokuBoard(changedBoard);
    
    bool gameActive = false;
    while(gameActive){

    }


    return 0;
}