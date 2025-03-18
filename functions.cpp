#include <iostream>
#include <vector>
#include "functions.h"

void initializeSudokuMap(){



    std::vector<std::vector<int>> sudokuMap(9, std::vector<int>(9, 0)); // 9x9 grid, filled with 0s

    for (int i = 0; i < 9; i++)
    {
        int RanNum = (rand() % 9)+1;
        for (int j = 0; j < 9; j++)
        {
            int RanNum = (rand() % 9)+1;
            sudokuMap[i][j] = RanNum;
        }
        
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudokuMap[i][j] << " ";  // Print each element in the grid
        }
        std::cout << std::endl;  // New line after each row
    }
}

