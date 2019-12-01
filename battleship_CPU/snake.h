
#include <vector>
#include <string>
//#include"inbounds.h"
//#include "validateattack.h"
//#include "quickinout.h"

using namespace std;


void snakeX(int &attackX, int &attackY, int direction, int &currentScopeX, int &currentScopeY, vector<pair<int,int>> &attackmemory, int &token, path &input_directory, 
	path &output_directory, path &temp_directory, string &command, string &status, string &message, string &user, int &checkcount, int &searchingphase) {
	do {
		attackX += direction;
		if (inbounds(attackX, attackY, currentScopeX, currentScopeY) & validateattack(attackX, attackY, attackmemory))
			quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);
		else break;
	} while (message == "DAMAGED");
	if (message == "MISS" || message == "DAMAGED") {
		do {
			attackX -= direction;
			if (validateattack(attackX, attackY, attackmemory)) {
				quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);
			}
		} while (message != "DESTROYED");
	}
	if (message == "DESTROYED") {
		searchingphase = 0;
	}
}

void snakeY(int& attackX, int& attackY, int direction, int& currentScopeX, int& currentScopeY, vector<pair<int, int>>& attackmemory, int& token, path& input_directory,
	path& output_directory, path& temp_directory, string& command, string& status, string& message, string& user, int& checkcount, int& searchingphase) {
	do {
		attackY += direction;
		if (inbounds(attackX, attackY, currentScopeX, currentScopeY) & validateattack(attackX, attackY, attackmemory))
			quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);
		else break;
	} while (message == "DAMAGED");
	if (message == "MISS" || message == "DAMAGED") {
		do {
			attackY -= direction;
			if (validateattack(attackX, attackY, attackmemory)) {
				quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);
			}
		} while (status != "DESTROYED");
	}
	if (message == "DESTROYED") {
		searchingphase = 0;
	}
}