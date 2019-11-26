#include "sendCommands.h"
#include "checkOutputs.h"

using path = std::filesystem::path;
using namespace std;

void handshake(int &token, int &ScopeX, int &ScopeY, string &user, string& username, path& input_directory, 
				path& output_directory, path& temp_directory){
	string command, message, status, scope;
	//step 1: send handshake command
	sendCommand(0, "HANDSHAKE", username, input_directory, temp_directory);

	//step2: wait and check output
	_sleep(0.5);
	checkOutput(command, status, token, scope, user, output_directory);

	//continue if true, terminate if false
	//if 


}