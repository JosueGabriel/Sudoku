#include "sudoku.h"
#include "interface.h"

int main()
{
    configureAll();
    displaySudoku();
    solver();
    displaySudoku();
    std::cout<<contador;
    return 0;
}
