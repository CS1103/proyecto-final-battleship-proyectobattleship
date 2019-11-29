#ifndef BATTLESHIP_CPU_PLACEFLEET_H
#define BATTLESHIP_CPU_PLACEFLEET_H

#include "IncludeHeaders.h"
#include "sendCommands.h"


const int fila = 10;
const int columna = 10;
const int maxships = 10;
int board[fila][columna];

void clear(){
    for (auto & i : board){
        for (int & j : i){
            j = 0;
        }
    }
}

void show(){
    for (auto & i : board){
        for (int & j : i){
            cout << j << "   ";
        }
        cout << endl;
    }
}

void SetShips(){
    int s = 0; // current number of ships
    while(s < maxships){
        int x = rand()%10;
        int y = rand()%10;
        if (board[x][y] != 1){
            s++;
            board[x][y] = 1;
        }
    }
}





/*
void placefleet(int token, path &input_directory, path &temp_directory, path &output_directory, int scopeX, int scopeY){

    random_device device;
    mt19937 generator(device());
    uniform_int_distribution <int> distribution (1, 10);

    string message;

    char tipoNave;
    char orientacion;

    // prueba de la primera nave

    tipoNave = 'A';
    scopeX = distribution(generator);
    scopeY = distribution(generator);
    orientacion = 'H';

    message = tipoNave[0] + "-" + scopeX + scopeY + "-" + orientacion[0];
    sendCommand(token, "PLACEFLEET", message, input_directory, temp_directory);
}*/


#endif //BATTLESHIP_CPU_PLACEFLEET_H
