#include "student.h"
#include "linkedList.h"
using namespace std;

Student AddStudent() {
	Student a;
	cout << "Student No: ";
	cin >> a.No;
	cout << "Student ID: ";
	cin >> a.StudentID;
	cout << "Student First Name: ";
	cin >> a.FirstName;
	cout << "Student Last Name: ";
	cin >> a.LastName;
	cout << "Student Gender: ";
	cin >> a.Gender;
	cout << "Student Date Of Birth (DD/MM/YYYY): ";
	cin >> a.dob.day >> a.dob.month >> a.dob.year;
	cout << "Student Social ID: ";
	cin >> a.SocialID;
	return a;
}

//Format for Adding students to class function
//LinkedList StudentList;
//addList(Class.listOfStudents, &AddStudent);