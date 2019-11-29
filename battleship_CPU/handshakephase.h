#include "sendCommands.h"
#include "checkOutputs.h"
#include "parseScope.h"

using path = std::filesystem::path;
using namespace std;

void handshake(int &token, int &ScopeX, int &ScopeY, string &user, string& username, path& input_directory, 
				path& output_directory, path& temp_directory, int &checkcount){
	string command, status, scope;
	//step 1: send handshake command
	sendCommand(0, "HANDSHAKE", username, input_directory, temp_directory);

	//step2: wait and check output
	_sleep(0.5);
	checkOutput(command, status, token, scope, user, output_directory, checkcount);
	if (command == "HANDSHAKE" && status == "ACCEPTED") {
		cout << endl<<"token and scope accepted"<<endl;
		parseScope(scope, ScopeX, ScopeY);
		cout << "token: " << token<<endl;
		cout << "dimensions: 0-" << ScopeX << ", 0-" << ScopeY << endl;

	} else cout << "status rejected or command isn't handshake"<<endl;
}