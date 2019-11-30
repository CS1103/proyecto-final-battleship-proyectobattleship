#include <sstream>
#include "parseOutput.h"
using namespace std;
using path = std::filesystem::path;

void checkOutput(string& command, string& status, int &token, string& message, string& user, path& output_directory, int &checkcount) {
	checkcount++;
	stringstream currentfile;
	if (user == "first") {
		currentfile<< "First";
	} else { currentfile<< "Second"; }
	currentfile << "Player" << checkcount << ".out";
	cout << endl<<currentfile.str()<<endl<<endl;	

	ifstream input(output_directory / currentfile.str());
	getline(input, command);
	//cout << command<<endl;
	string cmd, msg;

	do {
		parse(input, cmd, msg);
		//cout << cmd << endl << msg<<endl;
		if (cmd == "STATUS") status = msg;
		if (cmd == "TOKEN") token = stoi(msg);
		if (cmd == "SCOPE" || cmd =="MESSAGE") message = msg;
	} while (cmd != "SCOPE" && cmd != "MESSAGE");

	cout << command << endl << status << endl << token << endl << message << endl;
	input.close();
}