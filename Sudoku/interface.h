#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "sudoku.h"

void displaySudoku(){
    std::cout << "  || A | B | C | D | E | F | G | H | I |" << std::endl;
    for (auto var1 = 0; var1 < Size; var1++) {
        std::cout << var1 + 1 << " || ";
        for (auto var = 0; var < Size; var++){
            std::cout << Matrix[var1][var] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif // INTERFACE_H
