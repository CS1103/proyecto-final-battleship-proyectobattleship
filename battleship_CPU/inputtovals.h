using namespace std;
void getSettings(string& user, string& username, string& server_directory) {
	ifstream input("game_settings.txt");
	getline(input, user);
	getline(input, username);
	getline(input, server_directory);
	input.close();
}