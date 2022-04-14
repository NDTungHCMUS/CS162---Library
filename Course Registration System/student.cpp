#include "student.h"

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

void displayStudentMenu() {
	system("cls");
	cout << left << setw(10) << "No"
		<< left << setw(15) << "StudentID"
		<< left << setw(14) << "LastName"
		<< left << setw(14) << "FirstName"
		<< left << setw(12) << "Gender"
		<< left << setw(16) << "Date of Birth"
		<< left << setw(25) << "SocialID"
		<< endl;
}
void outputAllStudent(LinkedList<Student> ListStudent) {
	displayStudentMenu();
	displayAll(ListStudent, &outputStudent);
}

void outputStudentFile(Student s1, ofstream &foutList) {
	foutList << s1.No << ","
		<< s1.StudentID << ","
		<< s1.LastName << ","
		<< s1.FirstName << ","
		<< s1.Gender << ","
		<< s1.dob.day << "/" << s1.dob.month << "/" << s1.dob.year << ","
		<< s1.SocialID;
}

//Function to find a given Student in list of Student ID
//Student findStudent(ListYear.pHead->data.Listclass.pHead->data.listOffStudents)
// It will return the Student that hold the Student ID
Student findStudent(LinkedList<Student> ListStudent, int StudentID, bool &check) {
	Student a;
	int choice;
	Node<Student>* current = ListStudent.pHead;
	while (current != nullptr) {
		if (current->data.StudentID == StudentID) {
			a = current->data;
			break;
		}
		else {
			current = current->pNext;
		}
	}
	if ( current == nullptr)
    {
        check = false;
        return a;
    }
    else check = true;
	displayStudentMenu();
	outputStudent(a);
	cout << "Is this the right student?" << endl;
	cout << "1.YES" << endl;
	cout << "2.NO" << endl;
	cout << "Your choice: ";
	cin >> choice;
	if (choice == 1) {
		return a;
	}
	else {
		int ID;
		cout << "Type in Student ID: ";
		cin >> ID;
		findStudent(ListStudent, ID,check);
	}
}
