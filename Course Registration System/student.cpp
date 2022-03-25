
#include "student.h"
#include "linkedList.h"
#include "fstream"
#include <string.h>
#include <sstream>
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
	cout << "Student Gender (1 is Male, 2 is Female): ";
	cin >> a.Gender;
	cout << "Student Date Of Birth (DD/MM/YYYY): ";
	cin >> a.dob.day >> a.dob.month >> a.dob.year;
	cout << "Student Social ID: ";
	cin >> a.SocialID;
	return a;
}
void inputStudentCSV(LinkedList<Student> &s) {
	Node<Student> dummy;
	Node<Student>* temp = &dummy;
	ifstream fin;
	fin.open("Student.csv");
	string line;
	while (getline(fin, line)) {
		temp->pNext = new Node<Student>;
		temp = temp->pNext;
		string sNo;
		string sID;
		string sGender;
		string sDay, sMonth, sYear;
		string sSocial;
		string dob;
		stringstream inputstream;
		inputstream.str(line);
		/*getline(inputstream, sNo, ',');
		temp->data.No = stoi(sNo);*/
		inputstream >> temp->data.No;
		/*getline(inputstream, sID, ',');
		temp->data.StudentID = stoi(sID);*/
		inputstream >> temp->data.StudentID;
		getline(inputstream, temp->data.FirstName, ',');
		getline(inputstream, temp->data.LastName, ',');
		/*getline(inputstream, sGender, ',');
		temp->data.Gender = stoi(sGender);*/
		inputstream >> temp->data.Gender;
		getline(inputstream, dob, ',');
		stringstream dobstream;
		dobstream.str(dob);
		/*getline(dobstream, sDay, '/');
		temp->data.dob.day = stoi(sDay);*/
		dobstream >> temp->data.dob.day;
		/*getline(inputstream, sMonth, '/');
		temp->data.dob.month = stoi(sMonth);*/
		dobstream >> temp->data.dob.month;
		//getline(inputstream, sYear, '/');
		//temp->data.dob.year = stoi(sYear);
		dobstream >> temp->data.dob.year;
		inputstream >> temp->data.SocialID;
		//temp->data.SocialID = stoi(sSocial);
		/*temp = temp->pNext;*/
	}
	s.pHead = dummy.pNext;
	s.pTail = temp;
}
//Format for Adding students to class function
//LinkedList StudentList;
//addList(Class.listOfStudents, &AddStudent);

void inputStudentFile(Student &s1, string line) {
	string date;
	stringstream sline;
	sline.str(line);
	sline >> s1.No;
	sline.ignore( 1, ',' );
	sline >> s1.StudentID;
	sline.ignore(1, ',');
	getline(sline, s1.FirstName, ',');
	getline(sline, s1.LastName, ',');
	sline >> s1.Gender;
	sline.ignore(1, ',');
	getline(sline, date, ',');
	stringstream sdate;
	sdate.str(date);
	sdate >> s1.dob.day;
	sdate.ignore(1, '/');
	sdate >> s1.dob.month;
	sdate.ignore(1, '/');
	sdate >> s1.dob.year;
	sline >> s1.SocialID;
}

void outputStudent(Student s1) {
	cout << left << setw(10) << s1.No
		<< left << setw(15) << s1.StudentID
		<< left << setw(14) << s1.LastName 
		<< left << setw(14) << s1.FirstName
		<< left << setw(12) << ((s1.Gender == 1) ? "Male" : "Famale")
		<< ((s1.dob.day < 10) ? "0" : "") << s1.dob.day << "/" 
		<< ((s1.dob.month < 10) ? "0" : "") << s1.dob.month << "/"
		<< left << setw(10) << s1.dob.year 
		<< left << setw(25) << s1.SocialID
		<< endl;
}

void outputAllStudent(LinkedList<Student> ListStudent) {
	system("cls");
	cout << left << setw(10) << "No"
		<< left << setw(15) << "StudentID"
		<< left << setw(14) << "LastName"
		<< left << setw(14) << "FirstName"
		<< left << setw(12) << "Gender"
		<< left << setw(16) << "Date of Birth"
		<< left << setw(25) << "SocialID"
		<< endl;
	displayAll(ListStudent, &outputStudent);
}