#include "IncludeHeaders.h"
#include"game_setup.h"
#include"handshakephase.h"
#include "attackphase.h"
#include<filesystem>
#include "placefleet.h"
using namespace std;

using path = std::filesystem::path;


int main() {
	string user, username;
	path input_directory, output_directory, temp_directory;
	int token;
	int ScopeX;
	int ScopeY;
	int checkcount = 0;

	//pre-setup
	game_setup(user, username, input_directory, output_directory, temp_directory);
	cout << "GAME SETTINGS"<< username << endl<<input_directory << endl<<output_directory << endl<<temp_directory<<endl;
	
	//program begins
	//handshake 

	handshake(token, ScopeX, ScopeY, user, username, input_directory, output_directory, temp_directory, checkcount);

	//if handshake successful, begin placefleet phase
	//placefleet(token, input_directory, temp_directory, output_directory, ScopeX, ScopeY);

	//when placefleet completes, proceed to attack phase until win, loss or tie

	attackuntilend(token, ScopeX, ScopeY, user, input_directory, output_directory, temp_directory, checkcount);


	//clear();
	//show();
}