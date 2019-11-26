using namespace std;
using path = std::filesystem::path;

void getSettings(string& user, string& username, path& server_directory) {
	ifstream input("game_settings.txt");
	getline(input, user);
	getline(input, username);
	string direc;
	getline(input, direc);
	server_directory = direc;

	input.close();
}