using namespace std;
using path = std::filesystem::path;

void sendCommand(int token, string command, string &content, 
					path &input_directory, path &temp_directory) {
	
	ofstream output(temp_directory / "Player.in");

	if (token != 0) {
		output << "TOKEN=" << token<<endl;
	}
	output << command<<"="<<content;
	output.close();
		try {
			std::filesystem::rename(temp_directory / "Player.in", input_directory / "Player.in");
		}
		catch (std::filesystem::filesystem_error& e) {
			std::cout << e.what() << '\n';
		}
}