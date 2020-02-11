#include "sudoku.h"
#include "interface.h"

int main()
{
    configureAll();
    displaySudoku();
    solver();
    displaySudoku();
    return 0;
}
