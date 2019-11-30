#include "formatcoordinates.h"
#include "attacklogic.h"
#include "storeresult.h"

//#include "sendCommands.h"
#include <vector>
using namespace std;

void attackuntilend(int& token, int& ScopeX, int& ScopeY, string& user, path& input_directory,
	path& output_directory, path& temp_directory, int& checkcount) {
	string command, status, message;
	int attackX, attackY;
	int searchingphase = 4;
	// vector of pairs to store already attacked coordinates, hits and misses
	vector<pair<int, int>> attackmemory;
	vector<pair<int, int>> bufferx;
	vector<pair<int, int>> buffery;

	do {
		// generate attack coordinates based on already attacked spots and 
		// latest status/messages
		attacklogic(attackmemory, bufferx, buffery, ScopeX, ScopeY, attackX, attackY, message, searchingphase);

		// format coordinates in CHAR-INT format
		string formattedcoordinates = formatcoordinates(attackX, attackY);

		// send coordinates
		sendCommand(token, "ATTACK", formattedcoordinates, input_directory, temp_directory);

		// read response
		checkOutput(command, status, token, message, user, output_directory, checkcount);
		
		// store hits and misses
		//storeresult(hitmemory, missmemory, message, attackX, attackY);
		

		//loop until game ends
	} while (message != "GAMEOVER" || message != "WINNER");

}