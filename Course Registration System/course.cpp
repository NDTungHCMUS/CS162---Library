#include "course.h"
using namespace std;

//Function to add Course to a Semester
//addList(ListYear.ListSemester.pHead->data.ListCourse, &inputCourse);
Course inputCourse() {
	Course a;
	cin.ignore(1000, '\n');
	cout << "Course ID: ";
	getline(cin, a.ID);
	//cin.ignore(1000, '\n');
	cout << "Course Name: ";
	getline(cin, a.CourseName);
	//cin.ignore(1000, '\n');
	cout << "Teacher Name: ";
	getline(cin, a.TeacherName);
	//cin.ignore(1000, '\n');
	cout << "Number Of Credits: ";
	cin >> a.NumbOfCredits;
	cin.ignore(1000, '\n');
	cout << "Available Session: MON, TUE, WED, THU, FRI, SAT." << endl;
	cout << "Available Time: S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)." << endl;
	cout << "First Session's Day: ";
	getline(cin, a.s1.day);
	//cin.ignore(1000, '\n');
	cout << "Session Time: ";
	getline(cin, a.s1.period);
	//cin.ignore(1000, '\n');
	cout << "Second Session's Day: ";
	getline(cin, a.s2.day);
	//cin.ignore(1000, '\n');
	cout << "Session Time: ";
	getline(cin, a.s2.period);
	//cin.ignore(1000, '\n');
	return a;
}

// To display the list of courses, use the void displayAll() functions
// Pass in the outputCourse as a function parameter
void outputCourse(Course c1) {
	
	cout << left << setw(15) << c1.ID
		 << left << setw(15) << c1.CourseName
		 << left << setw(20) << c1.TeacherName
		 << left << setw(15) << c1.NumbOfCredits
		 << left << setw(20) << (c1.s1.day + " - " + c1.s1.period)
		 << left << setw(20) << (c1.s2.day + " - " + c1.s2.period)
		 << endl;
}

void outputAllCourse(LinkedList<Course> ListCourse) {
	cout << left << setw(15) << "Course ID"
		<< left << setw(15) << "Course Name"
		<< left << setw(20) << "Lecturer"
		<< left << setw(15) << "Credits"
		<< left << setw(20) << "Session 1"
		<< left << setw(20) << "Session 2"
		<< endl;
	displayAll(ListCourse, &outputCourse);
}