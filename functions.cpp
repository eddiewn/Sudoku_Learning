#include <iostream>
#include <vector>
#include <cstdlib>
#include "functions.h"



//Function to takes the 1. The Sudoku board, 2. Current Row, 3. Current Column
// and 4. The Number it wants to place to verify if its valid placement within sudoku rules.
bool validNumberVerifier(std::vector<std::vector<int>>board, int row, int column, int numberPlaced){
    //Assume row / column is valid
    bool valid = true;

    //Checks the row
    for (int x = 0; x < column; x++)
    {
        if(numberPlaced == board[row][x]){
            valid = false; 
            break;
        }
    }
    // Checks the column
    for (int y = 0; y < row; y++)
    {
        if(numberPlaced == board[y][column]){
            valid = false; 
            break;
        }
    }

    // Indicated where the 3x3 row is
    int starterRow = row - row % 3;
    int starterColumn = column - column % 3;

    // Checks each 3x3 grid
    for (int i = starterRow; i < starterRow + 3; i++){
        for(int j = starterColumn; j < starterColumn + 3; j++){
            if(numberPlaced == board[i][j]){
                valid = false;
                break;
            }
        }
    }

    // Returns if number is valid or not.
    return valid;
}

std::vector<std::vector<int>> initializeSudokuMap(){
    
    std::vector<std::vector<int>> sudokuMap(9, std::vector<int>(9, 0)); // 9x9 grid, filled with 0s
    srand(time(0));

    // Loops through first row
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //If cleanRow true = valid row with unique numbers
            bool validNumber = false;
            int attempts = 0;

            //While loop to check until the row is valid
            while(!validNumber)
            {  
                //Randomize number
                int ranNum = (rand() % 9)+1;

                //Calls function to see if number is valid to place
                bool valid = validNumberVerifier(sudokuMap, i, j, ranNum);

                    if(valid){
                        sudokuMap[i][j] = ranNum;
                        valid = true;
                        break;
                    }

                    //If row takes too long, reset the row and start over
                    attempts++;
                    if(attempts > 100){
                        for (int x = 0; x < 9; x++){
                            sudokuMap[i][x] = 0;
                        } 
                        j = -1;
                        break;
                    }
            }
        }
        
    }

    return sudokuMap;
}


void printSudokuBoard(const std::vector<std::vector<int>>& board){
        // This prints the sudoku board after its created in vector.
        for (int i = 0; i < 9; i++) {
            // Each third row prints a separator
            if(i % 3 == 0 && i != 0){
                std::cout << "-------------------------\n";
                std::cout << i + 1 << " | ";
            }else{
                std::cout << i + 1 << " | ";
            }
    
            for (int j = 0; j < 9; j++) {
                //Each third column prints a separator
                if(j % 3 == 0 && j != 0){
                    std::cout << "| ";
                }
    
                //Prints the board
                std::cout << board[i][j] << " ";  // Print each element in the grid
            }
            std::cout << std::endl;  // New line after each row
        }
        //"UX?" for improved user experience
        std::cout << "-------------------------" << "\n";
        std::cout << "X | A|B|C | D|E|F | G|H|I" << "\n";
}

std::vector<std::vector<int>> unsolvedSudokuBoard(std::vector<std::vector<int>>& board, int removeAmount){

    for (int i = 0; i < removeAmount;)
    {
        int ranRow = (rand() % 9);
        int ranColumn = (rand() % 9);
    
        if(board[ranRow][ranColumn] != 0){
            board[ranRow][ranColumn] = 0;
            i++;
        }
    } 

    return board;
}

int sudokuSolver(std::vector<std<int>>board){
    int amountOfSolutions = 0; 

    if(amountOfSolutions > 1){
        return amountOfSolutions;
    }

    for (int i = 0; i == 2; i++)
    {
        


    }
    


    return amountOfSolutions;

}