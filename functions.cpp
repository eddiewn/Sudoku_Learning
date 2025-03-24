#include <iostream>
#include <vector>
#include "functions.h"

// 1. Gör en funktion som kollar om varje rad + kolumn + 3x3 ruta går.
// 2. Inkorporera den i initializeSudokuMap
// 3. Blir functionen falsk, kör om loop tills den går







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

                //Assume row / column is valid
                bool valid = true;

                    for (int x = 0; x < j; x++)
                    {
                        if(ranNum == sudokuMap[i][x]){
                            valid = false; 
                            break;
                        }
                    }

                    for (int y = 0; y < i; y++)
                    {
                        if(ranNum == sudokuMap[y][j]){
                            valid = false; 
                            break;
                        }
                    }


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
        for (int j = 0; j < 9; j++) {
            std::cout << sudokuMap[i][j] << " ";  // Print each element in the grid
        }
        std::cout << std::endl;  // New line after each row
    }
}

