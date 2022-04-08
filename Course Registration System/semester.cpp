#include "year.h"
#include "semester.h"
Semester inputSemester() {
	Semester t;
	cout << "Input semester: ";
	cin >> t.SemesterNumb;
	return t;
}