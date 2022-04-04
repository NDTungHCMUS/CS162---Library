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

