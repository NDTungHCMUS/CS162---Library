#include "year.h"
#include "semester.h"

Semester inputSemester(Year y1) {
	Semester t;
	t.schoolyear = y1.yearStart;
	cout << "Input semester: ";
	cin >> t.SemesterNumb;
	cout << "Input start date: ";
	cin >> t.startDate.day >> t.startDate.month >> t.startDate.year;
	cout << "Input end date: ";
	cin >> t.endDate.day >> t.endDate.month >> t.endDate.year;
	return t;
}

void semester(Year y1) {
	system("cls");
	int choice;
	cout << "**** Semester Managing ****" << endl
		<< "1. Create a new semester." << endl
		<< "2. Create a course registration session." << endl
		<< "3. Add a course into semester." << endl
		<< "4. View list of current courses." << endl
		<< "5. Update a course information." << endl
		<< "6. Delete a course." << endl;
	cout << "Input choice (1 - 6): ";
	while (cin >> choice) {
		switch (choice)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		default:

			break;
		}
	}
}