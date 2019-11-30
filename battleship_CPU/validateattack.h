#include <vector>

using namespace std;

bool validateattack(int& x, int& y, vector<pair<int, int>>& attackmemory) {

	for (auto& i = attackmemory.begin(); i != attackmemory.end(); i++) {
		if (*i == pair<int, int>(x, y)) {
			return false;
			break;
		}
	}
	attackmemory.push_back(pair<int, int>(x, y));
	return true;

}