#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>

#define Size 9

bool solved = false;
bool logicCut = false;
std::vector <int> InicialPos; // primeira posição vazia
std::vector <int> FinalPos; // ultima posição vazia
std::vector <int> potatoSequence; //123456789


std::vector<vector<char>> Matrix = {{' ','5','2','8',' ','6','4','3',' '},
                                {' ','9','3',' ',' ',' ',' ','1','7'},
                                {'6',' ',' ',' ','7','9','2',' ',' '},
                                {'2',' ',' ','4','5',' ',' ','6',' '},
                                {'3',' ','6','2',' ',' ','5','8',' '},
                                {' ',' ',' ',' ',' ',' ','7','9',' '},
                                {' ','6',' ',' ',' ',' ',' ','2','1'},
                                {' ',' ',' ','6','3','4',' ','7',' '},
                                {'5','3','7',' ',' ',' ',' ',' ',' '}};

void setInicialFinalPos(){
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            if(Matrix[i][j] == ' '){
                InicialPos = {i,j};
                break;
            }
        }
    }
    for(int i = Size - 1; i >= 0; i--){
        for(int j = Size - 1; j >= 0; j--){
            if(Matrix[i][j] == ' '){
                FinalPos = {i,j};
                break;
            }
        }
    }
}

std::vector <int> Posibilities(int pos0, int pos1){
    if(logicCut)
        return potatoSequence; // substituir quando logic cut estiver pronto
    return potatoSequence;
}

bool validPosition(int pos0, int pos1, int value){
    // achar uma forma de verificar o quadrante da posição ; linha horizontal e vertical é tranquilo
}

void configureAll(){
    setInicialFinalPos();
    std::iota (potatoSequence.begin(),potatoSequence.end(),1);
}

void solver(int pos0, int pos1){
    for(int i:Posibilities(pos0, pos1)){
        if(validPosition(pos0, pos1, i)){
            Matrix[pos0][pos1] = i;
            if(!(pos0 == FinalPos[0] and pos1 == FinalPos[1])){
                solver(NextPosition) // implementar algo para ir para proxima posição
            }
            else{
                solved = true;
                return;
            }
            if(solved)
                return;
        }
    }
}
#endif // SUDOKU_H
