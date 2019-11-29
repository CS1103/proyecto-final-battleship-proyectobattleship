#include<sstream>
using namespace std;

void parseScope(string &scope, int &x, int& y) {
	char lx;
	replace(scope.begin(), scope.end(), '-', ' ');
	stringstream sc(scope);
	sc >> lx >> y;
	x = lx - 65;
	y--;
}
