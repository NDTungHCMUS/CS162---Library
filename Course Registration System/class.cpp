#include "class.h"
using namespace std;

Class inputClass() {
	Class res;
	cin.ignore(1000, '\n');
	cout << "Input classcode (e.g: 21CTT1): ";
	getline(cin, res.classname, '\n');
	return res;
}

bool checkExistClass(LinkedList<Class> ListClass, Class check) {
	Node<Class>* temp = ListClass.pHead;
	while (temp != NULL) {
		if (temp->data.classname == check.classname) {
			return true;
		}
	}
	return false;
}

void outputClass(Class c1) {
	cout << c1.classname << endl;
}

void outputListClass(LinkedList <Class> ListClass) {
	system("cls");
	if (ListClass.pHead == nullptr) cout << "No class here";
	else {
		cout << "All Class Name showed below: " << endl;
		displayAll(ListClass, &outputClass);
	}
}

void outputStuListFile(Class c1) {
	string filename = c1.classname + "OutputCSV.csv";
	ofstream foutList;
	foutList.open(filename);
	outputListFile(c1.listOfStudents, foutList, &outputStudentFile);
	foutList.close();
}
