#include "sudoku.h"
#include "interface.h"
#include <time.h>

int main()
{
    estruturaStatic(99);
    geradorSudoku(60);
    displaySudoku();
    configureAll();
    solver();
    displaySudoku();

    /*
    interfaceMenu();
    int L;
    std::cin >> L;
    if(L == 2){
        logicCut = !logicCut;
    }
    system("cls");

    clock_t end,start;

    start = clock();

    configureAll();
    displaySudoku();

    solver();
    displaySudoku();
    std::cout<< contador <<" - " << logicCut << std::endl;

    end = clock();

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    */
    return 0;
}
