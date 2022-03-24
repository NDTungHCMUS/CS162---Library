

#include "class.h"
using namespace std;

Class inputClass() {
	Class res;
	cin.ignore(1000, '\n');
	cout << "Input classcode (e.g: 21CTT1): ";
	getline(cin, res.classname, '\n');
	return res;
}
void outputClass(Class c1) {
	cout << c1.classname << endl;
}
void outputListClass(LinkedList <Class> ListClass) {
	if (ListClass.pHead == nullptr) cout << "No class here";
	else {
		cout << "All Class Name showed below: " << endl;
		displayAll(ListClass, &outputClass);
	}
}