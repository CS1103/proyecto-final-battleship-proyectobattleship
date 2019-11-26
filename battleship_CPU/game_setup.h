#include "inputtovals.h"
using namespace std;
using path = std::filesystem::path;
void game_setup(string& username, path& input_directory, path& output_directory, path& temp_directory) {

	//cargar settings de game_settings.txt
	string user;
	path server_directory;
	getSettings(user, username, server_directory);
	//cout << server_directory;

	//definir las carpetas de in/out
	server_directory += user;
	input_directory = server_directory / "in";
	output_directory = server_directory / "out";

	//directorio temporal (se moverá el archivo una vez finalizada la escritura)
	temp_directory = filesystem::current_path();

}