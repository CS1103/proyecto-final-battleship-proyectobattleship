#include <string>
using namespace std;
string formatcoordinates(int x, int y) {
	char lx;
	lx = x + 65;
	stringstream fc;
	fc << lx << y++;
	return fc.str();
}