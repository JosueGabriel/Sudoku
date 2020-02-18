#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "sudoku.h"

void displaySudoku(){
    std::cout << "  || A | B | C | D | E | F | G | H | I |" << std::endl;
    for (size_t var1 = 0; var1 < Size; var1++) {
        std::cout << var1 + 1 << " || ";
        for (size_t var = 0; var < Size; var++){
            if(Matrix[var1][var] == 0)
                std::cout << "  | ";
            else
                std::cout << Matrix[var1][var] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void interfaceMenu(){
    std::cout<<" 1 - logicCut = TRUE" << std::endl << " 2 - logicCut = FALSE" << std::endl;
}

#endif // INTERFACE_H
