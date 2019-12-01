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
        //message: Not in parameters
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

    else 
        // Message: Continue

    return tam ;
}

int shipNumber(){

}

void coords(){
    cout << "Ingrese eje x y eje y: ";
    cin >> scopex >> scopey;

    if (scopex < bound || scopex > fil){
        //output message: out of bounds;
        exit (1);
    }
    else {
        if (scopey < bound || scopey > col) {
            //output message: out of bounds;
            exit(1);
        }
    }
    //message: Accepted
}


void placefleet(token, input_directory, temp_directory, output_directory, ScopeX, ScopeY){

    clear();
    shipSize();
    coords();
    //output message
    
    if(orientacion != 'H' && orientacion != 'V'){
       //messgae: Not a valid orientation"
        exit (1);
    }


   



}

#endif //BATTLESHIP_CPU_PLACEFLEET_H
