#ifndef SUDOKU_H
#define SUDOKU_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdio.h>

#define Size 9
int contador = 0;
bool solved = false;
bool logicCut = false;
std::vector <int> InicialPos; // primeira posição vazia
std::vector <int> FinalPos; // ultima posição vazia
std::vector <int> potatoSequence(Size); //123456789


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
        if(!InicialPos.empty())
            break;
    }
    for(int i = Size - 1; i >= 0; i--){
        for(int j = Size - 1; j >= 0; j--){
            if(Matrix[i][j] == ' '){
                FinalPos = {i,j};
                break;
            }
        }
        if(!FinalPos.empty())
            break;
    }
}

std::vector <int> posibilities(std::vector<int> currentPosition){
    if(logicCut)
        return potatoSequence; // substituir quando logic cut estiver pronto
    return potatoSequence;
}

std::vector<int> getBlockCase(std::vector<int> currentPosition){
    switch (currentPosition[0]) {
    case 0:
    case 1:
    case 2: switch (currentPosition[1]){
        case 0:
        case 1:
        case 2: return {1,1};
        break;
        case 3:
        case 4:
        case 5: return {1,4};
        break;
        default: return {1,7};
        break;
    }
    break;
    case 3:
    case 4:
    case 5: switch (currentPosition[1]){
        case 0:
        case 1:
        case 2: return {4,1};
        break;
        case 3:
        case 4:
        case 5: return {4,4};
        break;
        default: return {4,7};
        break;
    }
    default: switch (currentPosition[1]){
        case 0:
        case 1:
        case 2: return {7,1};
        break;
        case 3:
        case 4:
        case 5: return {7,4};
        break;
        default: return {7,7};
        break;
        }
    }
}

std::vector<int> getBlockIf(int Linha,int Coluna ){
    if(0 >= Coluna && Coluna <= 2){
        if(0 >= Linha && Linha <= 2)
            return {1,1};
        else if (3 >= Linha && Linha <= 5)
            return {4,1};
        else
            return {7,1};
    }else if (3 >= Coluna && Coluna <= 5) {
        if(0 >= Linha && Linha <= 2)
            return {1,4};
        else if (3 >= Linha && Linha <= 5)
            return {4,4};
        else
            return {7,4};
    }else {
        if(0 >= Linha && Linha <= 2)
            return {1,7};
        else if (3 >= Linha && Linha <= 5)
            return {4,7};
        else
            return {7,7};
    }
}

bool validSolved(){
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            if(Matrix[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool validPosition(std::vector<int> currentPosition, int value){
    std::vector<int> blockPosition = getBlockCase(currentPosition);

    for(int i =  blockPosition[0]-1 ; i <= blockPosition[0]+1 ; i++){
        for(int j = blockPosition[1]-1 ; j <= blockPosition[1]+1 ; j++){
            if(value+ '0' == Matrix[i][j])
                return false;
        }
    }
    for(int i = 0 ; i < Size ; i++){
        if(value+'0' == Matrix[i][currentPosition[1]] || value+'0' == Matrix[currentPosition[0]][i])
            return false;
    }
    return true;
}

std::vector<int> nextPosition(){
    std::vector<int> nextPosition;
    //std::cout << "currentP: "<< currentPosition[0] << "-" << currentPosition[1] << std::endl;
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            if(Matrix[i][j] == ' '){
                nextPosition = {i,j};
                std::cout << nextPosition[0] << " | " << nextPosition[1] << std::endl;
                return nextPosition;
            }
        }
    }
    return {-1,-1};
}

void configureAll(){
    setInicialFinalPos();
    iota(potatoSequence.begin(),potatoSequence.end(),1);
    std::cout << "potatoS: ";
    for(int i:potatoSequence){
        std::cout << i << "|";
    }
    std::cout<< std::endl;
}

void solver(){
    std::vector <int> currentPosition = nextPosition();
    for(auto a:currentPosition){
        std::cout<< a << "|";
    }
    std::cout<<std::endl;

    if(currentPosition[0] == -1 && currentPosition[1] == -1){
        solved = true;
        return;
    }
    for(int i:potatoSequence){
        if(validPosition(currentPosition, i)){
            Matrix[currentPosition[0]][currentPosition[1]] = i+'0';
            std::cout << "Matriz["<<currentPosition[0]<<"]["<<currentPosition[1]<<"] =" << Matrix[currentPosition[0]][currentPosition[1]] << std::endl;
            solver();
            std::cout<<"passei"<<std::endl;
            if(solved)
                return;
        }
    }
    Matrix[currentPosition[0]][currentPosition[1]] = ' ';
    return;
}
#endif // SUDOKU_H
