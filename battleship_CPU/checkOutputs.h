using namespace std;
using path = std::filesystem::path;

void checkOutput(string& command, string& status, int token, string& message, string& user, path& output_directory, int &checkcount) {
	string currentfile;
	if (user == "first") {
		currentfile = "First";
	} else { currentfile = "Second"; }

	currentfile += "Player" + checkcount;
	//currentfile += '.out';
	cout << currentfile;
	//ifstream input(output_directory / currentfile);

}