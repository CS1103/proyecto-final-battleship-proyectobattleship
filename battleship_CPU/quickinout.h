
using namespace std;
void quickinout(int &attackX, int &attackY, int &token, string action, path &input_directory, 
	path &output_directory, path &temp_directory, string &command, string &status, string &message, 
	string &user, int &checkcount) {

	// format coordinates in CHAR-INT format
	string formattedcoordinates = formatcoordinates(attackX, attackY);

	// send coordinates
	sendCommand(token, action, formattedcoordinates, input_directory, temp_directory);

	// read response
	checkOutput(command, status, token, message, user, output_directory, checkcount);
}