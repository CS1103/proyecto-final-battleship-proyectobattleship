#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include"game_setup.h"
#include"handshakephase.h"
using namespace std;

using path = std::filesystem::path;

int main() {
	string user, username;
	path input_directory, output_directory, temp_directory;
	int token;
	int ScopeX;
	int ScopeY;

	//pre-setup
	game_setup(user, username, input_directory, output_directory, temp_directory);
	//cout << username << endl<<input_directory << endl<<output_directory << endl<<temp_directory;
	//program begins
	//handshake phase
	handshake(token, ScopeX, ScopeY, user, username, input_directory, output_directory, temp_directory);

	//if handshake successful, begin placefleet phase
	//placefleet();

	//when placefleet completes, proceed to attack phase until win, loss or tie

	//attackuntilend();


}