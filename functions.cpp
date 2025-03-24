#include <iostream>
#include <vector>
#include "functions.h"

// 1. Gör en funktion som kollar om varje rad + kolumn + 3x3 ruta går.
// 2. Inkorporera den i initializeSudokuMap
// 3. Blir functionen falsk, kör om loop tills den går



bool validNumberVerifier(std::vector<std::vector<int>>board, int row, int column, int numberPlaced){



    //Assume row / column is valid
    bool valid = true;

    for (int x = 0; x < column; x++)
    {
        if(numberPlaced == board[row][x]){
            valid = false; 
            break;
        }
    }

    for (int y = 0; y < row; y++)
    {
        if(numberPlaced == board[y][column]){
            valid = false; 
            break;
        }
    }

    int starterRow = row - row % 3;
    int starterColumn = column - column % 3;

    for (int XD = starterColumn; XD < starterColumn+3; XD++)
    {
        if(numberPlaced == board[starterRow][XD]){
            valid = false;
            break;
        }
    }

    for (int XDD = starterRow; XDD < starterRow+3; XDD++){
        if(numberPlaced == board[XDD][starterColumn]){
            valid = false;
            break;
        }
    }
    
    for (int i = starterRow; i < starterRow + 3; i++){
        for(int j = starterColumn; j < starterColumn + 3; j++){
            if(numberPlaced == board[i][j]){
                valid = false;
                break;
            }
        }
    }

    return valid;
}



void initializeSudokuMap(){


    std::vector<std::vector<int>> sudokuMap(9, std::vector<int>(9, 0)); // 9x9 grid, filled with 0s

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

                   bool valid = validNumberVerifier(sudokuMap, i, j, ranNum);



                    if(valid){
                        sudokuMap[i][j] = ranNum;
                        valid = true;
                        break;
                    }

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

    for (int i = 0; i < 9; i++) {


        if(i % 3 == 0){
            std::cout << "---------------------\n";
        }
        for (int j = 0; j < 9; j++) {
            if(j % 3 == 0 && j != 0){
                std::cout << "| ";
            }

            std::cout << sudokuMap[i][j] << " ";  // Print each element in the grid
        }

        
        std::cout << std::endl;  // New line after each row
    }
}

