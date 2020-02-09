#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define Size 9

bool solved = false;
bool logicCut = false;
std::vector <int> InicialPos; // primeira posição vazia
std::vector <int> FinalPos; // ultima posição vazia
std::vector <int> potatoSequence; //123456789


char Matrix[Size][Size] = {{' ','5','2','8',' ','6','4','3',' '},
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

std::vector<int> nextPosition(std::vector<int> currentPosition){
    for(int i = currentPosition[0]; i < Size; i++){
        for(int j = currentPosition[1]; j < Size; j++){
            if(Matrix[i][j] == ' '){
                currentPosition = {i,j};
                return currentPosition;
            }
        }
    }
    return currentPosition;
}

void configureAll(){
    setInicialFinalPos();
    iota(potatoSequence.begin(),potatoSequence.end(),1);
}

void solver(std::vector <int> currentPosition = InicialPos){
    for(int i:Posibilities(currentPosition[0], currentPosition[1])){
        if(validPosition(currentPosition[0], currentPosition[1], i)){
            Matrix[currentPosition[0]][currentPosition[1]] = i;
            if(!(currentPosition[0] == FinalPos[0] and currentPosition[1] == FinalPos[1]))
                solver(nextPosition(currentPosition));
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
