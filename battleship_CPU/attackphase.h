#include "formatcoordinates.h"
//#include "attacklogic.h"
#include "storeresult.h"
#include "validateattack.h"
#include "quickinout.h"
#include "inbounds.h"
#include "snake.h"

//#include "sendCommands.h"
#include <vector>
using namespace std;
std::random_device rd;
std::mt19937 gen(rd());


void attackuntilend(int& token, int& ScopeX, int& ScopeY, string& user, path& input_directory,
	path& output_directory, path& temp_directory, int& checkcount) {
	string command, status, message;
	int attackX, attackY;
	int searchingphase = 0;
	// vector of pairs to store already attacked coordinates, hits and misses
	vector<pair<int, int>> attackmemory;
	vector<pair<int, int>> bufferx;
	vector<pair<int, int>> buffery;

	do {
		// generate attack coordinates based on already attacked spots and 
		// latest status/messages
		
		int currentScopeX = ScopeX;
		int currentScopeY = ScopeY;
		int phaseid;

		// begin or end boat search phase
		if (message == "DAMAGED" && searchingphase == 0) {
			searchingphase = 4;
			// setup current searching phase
			bufferx.clear();
			buffery.clear();
			bufferx.push_back(pair<int, int>(attackX - 1, attackY));
			bufferx.push_back(pair<int, int>(attackX + 1, attackY));
			buffery.push_back(pair<int, int>(attackX, attackY - 1));
			buffery.push_back(pair<int, int>(attackX, attackY + 1));
		}
		if (message == "DESTROYED") searchingphase = 0;

		// generate attack coordinates
		if (searchingphase != 0) {
			do {
				searchingphase--;
				// switch phases
				switch (searchingphase) {
				case 3: // right
					attackX = bufferx[1].first;
					attackY = bufferx[1].second;
					bufferx.pop_back();
					break;
				case 2: // left
					attackX = bufferx[0].first;
					attackY = bufferx[0].second;
					bufferx.pop_back();
					break;
				case 1: // up
					attackX = buffery[1].first;
					attackY = buffery[1].second;
					buffery.pop_back();
					break;
				case 0: // down
					attackX = buffery[0].first;
					attackY = buffery[0].second;
					buffery.pop_back();
					break;
				}
				//phaseid = searchingphase;
				
				// check if valid
				// check single and if valid send coordinates to server
			} while (~(inbounds(attackX, attackY, currentScopeX, currentScopeY)) & validateattack(attackX, attackY, attackmemory) & searchingphase != 0);

			if (searchingphase != 0) {
				// send coordinates if valid state
				quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);

				// try path
				if (message == "DAMAGED") {
					if (searchingphase == 3) { // try to the right
						snakeX(attackX, attackY, 1, currentScopeX, currentScopeY, attackmemory, token, input_directory,
							output_directory, temp_directory, command, status, message, user, checkcount, searchingphase);
					}
					else if (searchingphase == 2) { // try to the left
						snakeX(attackX, attackY, -1, currentScopeX, currentScopeY, attackmemory, token, input_directory,
							output_directory, temp_directory, command, status, message, user, checkcount, searchingphase);
					}
					else if (searchingphase == 1) { // try up
						snakeY(attackX, attackY, 1, currentScopeX, currentScopeY, attackmemory, token, input_directory,
							output_directory, temp_directory, command, status, message, user, checkcount, searchingphase);
					}
					else if (searchingphase == 0) { // try down
						snakeY(attackX, attackY, -1, currentScopeX, currentScopeY, attackmemory, token, input_directory,
							output_directory, temp_directory, command, status, message, user, checkcount, searchingphase);
					}
					//searchingphase++;
				}
				//else searchingphase = 0;
			}//else message = "" (?)

		}
		else { // if not in searching phase or miss after random, default to random attacks on empty coordinates

			// void sendrandomcoordinates()
			do {
				std::uniform_int_distribution<int> randX(0, currentScopeX);
				std::uniform_int_distribution<int> randY(0, currentScopeY);
				attackX = randX(gen);
				attackY = randY(gen);
			} while (validateattack(attackX, attackY, attackmemory) != true);
			quickinout(attackX, attackY, token, "ATTACK", input_directory, output_directory, temp_directory, command, status, message, user, checkcount);
		}

		//loop until game ends
	} while (message != "WINNER" && message !="GAMEOVER");
	
	if (message == "WINNER")	exit(1);
	else exit(0);
}