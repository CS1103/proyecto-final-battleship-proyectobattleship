#include "sendCommands.h"
using path = std::filesystem::path;
using namespace std;

void handshake(string& username, path& input_directory, 
				path& output_directory, path& temp_directory)
{
	//step 1: send handshake command
	sendCommand(0, "HANDSHAKE", username, input_directory, temp_directory);

	//step2: wait and check output
	_sleep(0.5);
	checkOutput(output_directory, status, toke, );

	//continue if true, terminate if false
	if 


}