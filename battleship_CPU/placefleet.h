#ifndef BATTLESHIP_CPU_PLACEFLEET_H
#define BATTLESHIP_CPU_PLACEFLEET_H

#include "IncludeHeaders.h"
#include "sendCommands.h"


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
    
}






#endif //BATTLESHIP_CPU_PLACEFLEET_H
