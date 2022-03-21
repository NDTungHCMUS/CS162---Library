#include "class.h"
using namespace std;

Class inputClass() {
	Class res;
	cin.ignore(1000, '\n');
	cout << "Input classcode (e.g: 21CTT1): ";
	getline(cin, res.classname, '\n');
	return res;
}