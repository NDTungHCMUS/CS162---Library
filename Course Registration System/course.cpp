#include "course.h"
using namespace std;

Course inputCourse() {
	Course a;
	cin.ignore(1000, '\n');
	cout << "Course ID: ";
	cin >> a.ID;
	cin.ignore(1000, '\n');
	cout << "Course Name: ";
	getline(cin, a.CourseName);
	cin.ignore(1000, '\n');
	cout << "Teacher Name: ";
	getline(cin, a.TeacherName);
	cin.ignore(1000, '\n');
	cout << "Available Session: MON, TUE, WED, THU, FRI, SAT." << endl;
	cout << "Available Time: S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)." << endl;
	cout << "First Session's Day: ";
	getline(cin, a.s1.day);
	cin.ignore(1000, '\n');
	cout << "Session Time: ";
	getline(cin, a.s1.period);
	cin.ignore(1000, '\n');
	cout << "Second Session's Day: ";
	getline(cin, a.s2.day);
	cin.ignore(1000, '\n');
	cout << "Session Time: ";
	getline(cin, a.s2.period);
	cin.ignore(1000, '\n');
}

//Function to add Course to a Semester
//addList(ListYear.ListSemester.pHead->data.ListCourse, &inputCourse);