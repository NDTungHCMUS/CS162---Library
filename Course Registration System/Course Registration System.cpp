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
	/*LinkedList<Year> listYear;
	Year y1{ 2020 };
	Year y2{ 2021 };
	Year y3{ 2022 };
	add(listYear, y1);
	add(listYear, y2);
	addFront(listYear, y3);
	cout << length(listYear) << endl;
	addList(listYear.pHead->data.Listclass, &inputClass);
	deallocateAll(listYear);*/

	/*LinkedList<Course> ListCourse;
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
	//inputFile(ListStudent, &inputStudentFile);
	//displayAll(ListStudent, &outputStudent);


	LinkedList<Course> ListCourse;
	addList(ListCourse, &inputCourse);
	removeCourse(ListCourse);
	return 0;
}


