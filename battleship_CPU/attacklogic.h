
#include<vector>
#include<string>
#include<random>

#include "validateattack.h"

using namespace std;
std::random_device rd;
std::mt19937 gen(rd());


void attacklogic(vector<pair<int, int>> &attackmemory, vector<pair<int, int>>& bufferx, vector<pair<int, int>>& buffery,
	int &ScopeX, int &ScopeY, int &attackX, int &attackY, string &message, int &searchingphase, int &token, path& input_directory,
	path& output_directory, path& temp_directory) {
	int currentScopeX = ScopeX;
	int currentScopeY = ScopeY;
	int phaseid;

	// begin or end boat search phase
	if (message == "DAMAGED" || searchingphase == 0) {
		searchingphase = 4;
		// setup current searching phase
		bufferx.push_back(pair<int, int>(attackX - 1, attackY));
		bufferx.push_back(pair<int, int>(attackX + 1, attackY));
		buffery.push_back(pair<int, int>(attackX, attackY - 1));
		buffery.push_back(pair<int, int>(attackX, attackY + 1));
	}
	if (message == "DESTROYED") searchingphase = 0;

	// generate attack coordinates
	if (searchingphase != 0) {
		do {
			// switch phases
			switch (searchingphase) {
			case 4:
				attackX = bufferx[1].first;
				attackY = bufferx[1].second;
				bufferx.pop_back();
			case 3:
				attackX = bufferx[0].first;
				attackY = bufferx[0].second;
				bufferx.pop_back();
			case 2:
				attackX = buffery[1].first;
				attackY = buffery[1].second;
				buffery.pop_back();
			case 1:
				attackX = buffery[0].first;
				attackY = buffery[0].second;
				buffery.pop_back();
			}
			phaseid = searchingphase;
			searchingphase--;
			// check if valid
			// check single and if valid send coordinates to server

		} while (validateattack(attackX, attackY, attackmemory) != true || searchingphase != 0);

	}
	else { // if not in searching phase, default to random attacks on empty coordinates
		do {
			std::uniform_int_distribution<int> randX(0, currentScopeX);
			std::uniform_int_distribution<int> randY(0, currentScopeY);
			attackX = randX(gen);
			attackY = randY(gen);
		} while (validateattack(attackX, attackY, attackmemory) != true);
		// format coordinates in CHAR-INT format
		string formattedcoordinates = formatcoordinates(attackX, attackY);

		// send coordinates
		sendCommand(token, "ATTACK", formattedcoordinates, input_directory, temp_directory);

		// read response
		checkOutput(command, status, token, message, user, output_directory, checkcount);

	}
}