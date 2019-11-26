#include "sendCommands.h"

using namespace std;
void handshake(string& username, string& input_directory, 
				string& output_directory, string& temp_directory)
{
	//step 1: send handshake command
	sendCommand(0, "HANDSHAKE", username, input_directory, temp_directory);

	//step2: wait and check output
	_sleep(0.5);
	checkOutput();

	//continue if true, terminate if false
	if 


}