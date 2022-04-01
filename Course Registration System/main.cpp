#include <iostream>
#include "course.h"
#include "class.h"
#include "login.h"
#include "year.h"
#include "student.h"
#include "linkedList.h"

using namespace std;

int main()
{
/*
    //example to use function : import Score board,	view Score Board Of a Course  ,and update A Student's result;

    LinkedList<Course> ListCourse;
    addList(ListCourse, &inputCourse);
	outputAllCourse(ListCourse);
	Student a;
	a.dob = {17,07,2003};
	a.FirstName = "QUOC";
	a.Gender = 1;
	a.LastName = "Tran";
	a.No = 1;
	a.StudentID  = 21125093;
	a.SocialID  = 5;

	Student b;
	b.dob = {17,07,2003};
	b.FirstName = "Nguye Nam";
	b.Gender = 2;
	b.LastName = "Le";
	b.No = 2;
	b.StudentID  = 21125094;
	b.SocialID  = 6;

	Student c;
	b.dob = {18,07,2003};
	b.FirstName = "Nguye Van";
	b.Gender = 2;
	b.LastName = "Le";
	b.No = 3;
	b.StudentID  = 21125097;
	b.SocialID  = 7;

	add(ListCourse.pHead->data.EnrollStudentList, a);
	ListCourse.pHead->data.NumbOfStudent++;
	add(ListCourse.pHead->data.EnrollStudentList, b);
	ListCourse.pHead->data.NumbOfStudent++;
	add(ListCourse.pHead->data.EnrollStudentList, c);
	ListCourse.pHead->data.NumbOfStudent++;

	importScoreboard(ListCourse);
	viewScoreBoardOfCourse(ListCourse);
	updateAStudent(ListCourse);
	viewScoreBoardOfCourse(ListCourse);


//	end example~~~

*/

	/*LinkedList<Year> listYear;
	Year y1{ 2020 };
	Year y2{ 2021 };
	Year y3{ 2022 };
	add(listYear, y1);
	add(listYear, y2);
	addFront(listYear, y3);
	cout << length(listYear) << endl;
	addList(listYear.pHead->data.Listclass, &inputClass);
	deallocateAll(listYear);

	CreateYear(listYear);

	LinkedList<Course> ListCourse;
	addList(ListCourse, &inputCourse);
	outputAllCourse(ListCourse);
	updateIndex(ListCourse, 1, inputCourse);
	outputAllCourse(ListCourse);
	deallocateAll(ListCourse);
	LinkedList<Student> ListStudent;
	inputStudentCSV(ListStudent);
	cout << ListStudent.pHead->data.No << endl;
	deallocateAll(ListStudent);*/


	//LinkedList<Student> ListStudent;
//	inputFile(ListStudent, &inputStudentFile);
//	Student s1 = findStudent(ListStudent);
	//outputStudent(s1);
	//////displayAll(ListStudent, &outputStudent);
	//addList(ListStudent, &AddStudent);
	//outputAllStudent(ListStudent);


	/*LinkedList<Course> ListCourse;
	addList(ListCourse, &inputCourse);
	removeCourse(ListCourse);*/


	/*LinkedList<Class> listClass;
	addList(listClass, &inputClass);
	outputListClass(listClass);
	return 0;*/

	/*Class c1{ "21CTT1", nullptr };
	addList(c1.listOfStudents, &AddStudent);
	outputStuListFile(c1);*/

	/*int index;
	LinkedList<Course> c1;
	addList(c1, &inputCourse);
	cout << "input index";
	cin >> index;
	Course c2;
	findIndex(c1, index, c2);
	cout << c2.CourseName;

	LinkedList <Course> ListCourse;
	addList(ListCourse, &inputCourse);
	Node<Course>* c;
	c = ListCourse.pHead;
	addList(c->data.EnrollStudentList, &AddStudent);
	outputStudentInCourse(ListCourse);*/
}
/*
1
CS162
introduce to CS1
Dinh Ba Tien
4
MON
S1
TUE
S2
1
CM101
comunication M
Duong Nguyen Vu
4
MON
S3
TUE
S4
2
*/
