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
	cout << "Student Gender: ";
	cin >> a.Gender;
	cout << "Student Date Of Birth (DD/MM/YYYY): ";
	cin >> a.dob.day >> a.dob.month >> a.dob.year;
	cout << "Student Social ID: ";
	cin >> a.SocialID;
	return a;
}
void inputStudentCSV(LinkedList<Student> &s) {
	Node<Student>* temp = s.pHead;
	ifstream fin;
	fin.open("Student.csv");
	string line;
	while (getline(fin, line)) {
		/*temp->data.No = (int)line[0];
		temp->data.StudentID = (int)line[1];
		temp->data.SocialID = (int)line[2];
		cout << temp->data.No << " " << temp->data.StudentID << " " << temp->data.SocialID << endl;
		temp = temp->pNext;*/
		string sNo;
		string sID;
		string sGender;
		string sDay, sMonth, sYear;
		string sSocial;
		stringstream inputstream;
		inputstream.str(line);
		getline(inputstream, sNo, ',');
		temp->data.No = stoi(sNo);
		getline(inputstream, sID, ',');
		temp->data.StudentID = stoi(sID);
		getline(inputstream, temp->data.FirstName, ',');
		getline(inputstream, temp->data.LastName, ',');
		getline(inputstream, sGender, ',');
		temp->data.Gender = stoi(sGender);
		getline(inputstream, sDay, '/');
		temp->data.dob.day = stoi(sDay);
		getline(inputstream, sMonth, '/');
		temp->data.dob.month = stoi(sMonth);
		getline(inputstream, sYear, '/');
		temp->data.dob.year = stoi(sYear);
		getline(inputstream, sSocial, ',');
		temp->data.SocialID = stoi(sSocial);
		temp = temp->pNext;
	}
}
//Format for Adding students to class function
//LinkedList StudentList;
//addList(Class.listOfStudents, &AddStudent);