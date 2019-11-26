#include "IncludeHeaders.h"
#include"game_setup.h"
#include"handshakephase.h"
#include "placefleet.h"
using namespace std;

using path = std::filesystem::path;

int main() {
	string username;
	path input_directory, output_directory, temp_directory;
	int token;
	int ScopeX;
	int ScopeY;

	//pre-setup
	game_setup(username, input_directory, output_directory, temp_directory);
	//cout << username << endl<<input_directory << endl<<output_directory << endl<<temp_directory;
	//program begins
	//handshake phase
	handshake(token, ScopeX, ScopeY, username, input_directory, output_directory, temp_directory);

	//if handshake successful, begin placefleet phase
	placefleet(token, input_directory, temp_directory, output_directory, ScopeX, ScopeY);

	//when placefleet completes, proceed to attack phase until win, loss or tie

	//attackuntilend();


}