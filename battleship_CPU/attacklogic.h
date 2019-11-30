
#include<vector>
#include<string>
#include<random>

#include "validateattack.h"

using namespace std;
std::random_device rd;
std::mt19937 gen(rd());


void attacklogic(vector<pair<int, int>> &attackmemory, vector<pair<int, int>>& bufferx, vector<pair<int, int>>& buffery,
	int &ScopeX, int &ScopeY, int &attackX, int &attackY, string &message, int &searchingphase) {
	int currentScopeX = ScopeX;
	int currentScopeY = ScopeY;

	// begin or end boat search phase
	if (message == "DAMAGED") {
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
		// check if valid
		// check single and if valid send coordinates to server

	}
	else { // if not in searching phase, default to random attacks on empty coordinates
		do {
			std::uniform_int_distribution<int> randX(0, currentScopeX);
			std::uniform_int_distribution<int> randY(0, currentScopeY);
			attackX = randX(gen);
			attackY = randY(gen);
		} while (validateattack(attackX, attackY, attackmemory) != true);
	}
}