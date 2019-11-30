#ifndef BATTLESHIP_CPU_PLACEFLEET_H
#define BATTLESHIP_CPU_PLACEFLEET_H

#include "IncludeHeaders.h"
#include "sendCommands.h"


char tipoNave;
int scopex; int scopey;
int tam, cant;
char orientacion;

const int fil = 10;
const int col = 10;
const int bound = 0;
char board [fil][col];

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

int shipSize(){

    cout << "Inserte el tipo de nave que deseea: ";
    cin >> tipoNave;

    if (tipoNave != 'A' && tipoNave != 'B' && tipoNave != 'S' && tipoNave != 'T') {
        cout << "Not in parameters " << endl;
        exit(1);
    }

    if (tipoNave == 'A') {
        tam = 4;
    }

    if (tipoNave == 'B') {
        tam = 3;
    }

    if (tipoNave == 'S') {
        tam = 2;
    }

    if (tipoNave == 'T') {
        tam = 1;
    }

    else cout << "Message: Continue" << endl;

    return tam ;
}

int shipNumber(){

}

void coords(){
    cout << "Ingrese eje x y eje y: ";
    cin >> scopex >> scopey;

    if (scopex < bound || scopex > fil){
        cout << "Out of bounds" << endl;
        exit (1);
    }
    else {
        if (scopey < bound || scopey > col) {
            cout << "Out of bounds" << endl;
            exit(1);
        }
    }
    cout << "Accepted" << endl;
}


void placefleet(){

    clear();
    shipSize();
    coords();
    cout << "ingrese la orientacion: ";
    cin >> orientacion;

    if(orientacion != 'H' && orientacion != 'V'){
        cout << "Not a valid orientation" << endl;
        exit (1);
    }





}

#endif //BATTLESHIP_CPU_PLACEFLEET_H
