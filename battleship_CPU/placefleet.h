#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <random>
#include <vector>
#include "sendCommands.h"

using namespace std;

// functions
void clear(char &board) {
	for (auto& i : board) {
		for (int& j : i) {
			j = 0;
		}
	}
}

void shipSize(char &tipoNave, int &tam) {
	//metodo lectura, lee la primera letra 

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
	// message output: continue

}

void coords(int &placex, int &placey, int &ScopeX, int &ScopeY) {
	cout << "Ingrese eje x y eje y: ";
	cin >> placex >> placey;

	if (placex < 0 || placex > ScopeX) {
		cout << "Out of bounds" << endl;
		exit(1);
	}

	else {
		if (placey < 0 || placey > ScopeY) {
			cout << "Out of bounds" << endl;
			exit(1);
		}
		// message output: Accepted"
	}
}



void placefleet(int token, path& input_directory, path& temp_directory, path& output_directory, int &ScopeX, int &ScopeY) {
	const int bound = 0;
	char tipoNave;
	int scopex, scopey;
	int tam, cant;
	char orientacion;
	int placex, placey;

	char board[10][10];

	clear(board);
	shipSize(tipoNave, tam);
	coords(placex, placey, ScopeX, ScopeY);

	// metodo lecrura de orientación
	if (orientacion != 'H' && orientacion != 'V') {
		//message output: Not a valid orientation 
		exit(1);
	}
}


