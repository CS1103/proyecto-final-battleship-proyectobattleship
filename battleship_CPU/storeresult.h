#include <vector>
using namespace std;

void storeresult(vector<pair<int, int>>& hitmemory, vector<pair<int, int>>& missmemory, string message, int attackX, int attackY) {
	if(message == "DAMAGED" || message == "DESTROYED")
		hitmemory.push_back(pair<int, int>(attackX, attackY));

	if(message == "FAILED")
		missmemory.push_back(pair<int, int>(attackX, attackY));
}