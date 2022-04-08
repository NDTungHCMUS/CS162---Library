#include "year.h"
#include<sstream>
using namespace std;

void CreateYear(LinkedList<Year>& yearList) {
	Node<Year>* current = yearList.pHead;
	int temp;
	cout << "Type in Year Start: ";
	cin >> temp;
	if (yearList.pHead == nullptr) {
		yearList.pHead = new Node<Year>;
		yearList.pTail = yearList.pHead;
		current = yearList.pHead;
	}
	else {
		yearList.pTail->pNext = new Node<Year>;
		yearList.pTail = yearList.pTail->pNext;
		yearList.pTail->data.yearStart = temp;
	}
}

void inputStudentCSV(LinkedList<Year> &ListYear, string &className) {
   // ListYear.pHead->data.Listclass.pHead->data.listOfStudents

  //  Node<Class> *current = ListYear.pHead->data.Listclass.pHead;
    LinkedList<Student> s;
   /* bool check = false;
    while (current != nullptr)
    {
        if (current->data.classname == className)
            {
                s = current->data.listOfStudents;
                check = true;
                break;
            }
            current = current->pNext;
    }
    if (check == false)
    {
        cout << "Can not find this class, please try again!" << endl;
        return;
    }*/
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
		inputstream >> temp->data.No;
		inputstream >> temp->data.StudentID;
		cout << temp->data.No << ' ' << temp->data.StudentID<<endl;
		system("pause");
		getline(inputstream, temp->data.FirstName, ',');
		getline(inputstream, temp->data.LastName, ',');
		inputstream >> temp->data.Gender;
		getline(inputstream, dob, ',');
		stringstream dobstream;
		dobstream.str(dob);
		dobstream >> temp->data.dob.day;
		dobstream >> temp->data.dob.month;
		dobstream >> temp->data.dob.year;
		inputstream >> temp->data.SocialID;
	}
	s.pHead = dummy.pNext;
	s.pTail = temp;
    outputAllStudent(s);
    //cout << endl;
/*	current = ListYear.pHead->data.Listclass.pHead;
	while (current != nullptr)
    {
        if (current->data.classname == className)
            {
                current->data.listOfStudents = s;
                break;
            }
            current = current->pNext;
    }
   // outputAllStudent()
*/
}
//Format for Adding students to class function
//LinkedList StudentList;
//addList(Class.listOfStudents, &AddStudent);
Year inputYear() {
	Year res{ 0, nullptr };
	cout << "input year start: ";
	cin >> res.yearStart;
	return res;
}
void displayYear(LinkedList<Year>yearList) {
	Node<Year>* temp = yearList.pHead;
	if (yearList.pHead == nullptr) return;
	cout << "All years shown below: " << endl;
	while (temp) {
		cout << temp->data.yearStart << endl;
		temp = temp->pNext;
	}
}
void viewListCoursethisSemester(LinkedList<Year> listYear) {
	displayYear(listYear);
	cout << "Input Year: ";
	int year;
	cin >> year;
	Node<Year>* cur = listYear.pHead;
	while (cur) {
		if (cur->data.yearStart == year) break;
		cur = cur->pNext;
	}
	cout << "Input semester (from 1 to 3) in " << year << " you want to view list courses: ";
	int n;
	cin >> n;
	while (n <= 0 || n >= 4) {
		cout << "Please choose semester again: ";
		cin >> n;
	}
	if (n >= 1 && n <= 3) {
		cout << "All courses in semester " << n << " of year " << cur->data.yearStart << " shown as below: " << endl;
		Node <Semester>* temp = cur->data.ListSemester.pHead;
		int count = n - 1;
		int count2 = 0;
		while (count2 < count) {
			temp = temp->pNext;
			count2++;
		}
		outputAllCourse(temp->data.ListCourse);
	}
}