#ifndef BATTLESHIP_CPU_PLACEFLEET_H
#define BATTLESHIP_CPU_PLACEFLEET_H

#include "IncludeHeaders.h"
#include "sendCommands.h"


void placefleet(){

    random_device device;
    mt19937 generator(device());
    uniform_int_distribution <int> distribution (1, 10);
    string message;

    char tipoNave;
    int x;
    int y;
    char orientacion;

    //primera nave

    tipoNave = 'A';
    x = distribution(generator);
    y = distribution(generator);
    orientacion = 'H';

    sendCommand();

}






#endif //BATTLESHIP_CPU_PLACEFLEET_H
