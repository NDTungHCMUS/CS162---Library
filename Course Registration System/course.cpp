#include "course.h"
using namespace std;

//Function to add Course to a Semester
//addList(ListYear.pHead->data.ListSemester.pHead->data.ListCourse, &inputCourse);
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

void outputCourseMenu() {
	cout << left << setw(15) << "Course ID"
		<< left << setw(15) << "Course Name"
		<< left << setw(20) << "Lecturer"
		<< left << setw(15) << "Credits"
		<< left << setw(20) << "Session 1"
		<< left << setw(20) << "Session 2"
		<< endl;
}

void outputAllCourse(LinkedList<Course> ListCourse) {
	outputCourseMenu();
	displayAll(ListCourse, &outputCourse);
}

void removeCourse(LinkedList<Course> ListCourse) {
	outputAllCourse(ListCourse);
	int temp;
	cout << "Please input the number of the Course you want to remove (From 1): ";
	cin >> temp;
	removeIndex(ListCourse, temp);
	system("cls");
	outputAllCourse(ListCourse);
}

bool checkSessionConflict(Session s1, Session s2) {
	if (s1.day == s2.day) {
		if (s1.period == s2.period)
			return true;
	}
	return false;
}

bool checkAvailable(Course a, Student s) {
	while (s.ListCourseData.pHead != nullptr) {
		if (checkSessionConflict(a.s1, s.ListCourseData.pHead->data.s1) || checkSessionConflict(a.s1, s.ListCourseData.pHead->data.s2) 
			|| checkSessionConflict(a.s2, s.ListCourseData.pHead->data.s1) || checkSessionConflict(a.s2, s.ListCourseData.pHead->data.s2))
			return false;
		else {
			s.ListCourseData.pHead = s.ListCourseData.pHead->pNext;
		}
	}
	return true;
}

CourseData addCourseData(Course a) {
	CourseData b;
	b.CourseName = a.CourseName;
	b.ID = a.ID;
	b.s1 = a.s1;
	b.s2 = a.s2;
	b.TeacherName = a.TeacherName;
	return b;
}

void enrollCourse(LinkedList<Course> &ListCourse, Student &a) {
	cout << "Choose the option: " << endl;
	cout << "1. Enroll Course" << endl;
	cout << "2. Exit" << endl;
	int numb;
	cin >> numb;
	if (numb == 1) {
		outputAllCourse(ListCourse);
		cout << "Enter the Course No you want to enroll: ";
		cin >> numb;
		Course temp;
		if (findIndex(ListCourse, numb, temp)) {
			if (checkAvailable(temp, a)) {
				add(ListCourse.pHead->data.EnrollStudentList, a);
				CourseData dtemp = addCourseData(temp);
				add(a.ListCourseData, dtemp);
				cout << "Enrolled Successfully.";
				system("pause");
			}
			else {
				cout << "Timetable conflicted. Please choose other courses.";
				enrollCourse(ListCourse, a);
			}
		}
	}
	else {
		return;
	}
}

void outputCourseData(Student a) {
	while (a.ListCourseData.pHead != nullptr) {
		cout << a.ListCourseData.pHead->data.CourseName << endl;
		a.ListCourseData.pHead = a.ListCourseData.pHead->pNext;
	}
}