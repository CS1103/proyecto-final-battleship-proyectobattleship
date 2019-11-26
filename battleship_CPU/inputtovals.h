using namespace std;
void getSettings(string& user, string& username, path& server_directory) {
	ifstream input("game_settings.txt");
	getline(input, user);
	getline(input, username);
	string direc;
	getline(input, direc);


	input.close();
}