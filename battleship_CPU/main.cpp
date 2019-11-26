#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include"game_setup.h"
#include"handshakephase.h"
using namespace std;
using path = std::filesystem::path;

int main() {
	string username, input_directory, output_directory, temp_directory;
	int token;
	char ScopeX;
	int ScopeY;

	//pre-setup
	game_setup(username, input_directory, output_directory, temp_directory);
	
	//program begins
	//handshake phase
	handshake(username, input_directory, output_directory, temp_directory);

	//if handshake successful, begin placefleet phase
	placefleet();

	//when placefleet completes, proceed to attack phase until win, loss or tie

	attackuntilend();


}