#include "login.h"
#include"year.h"
using namespace std;
int main()
{
	/*login();*/
	/*Date d1{ 23,01,2003 };
	LinkedList<CourseData> cd1;
	Student s1{ 1,21125078,"phong","vuong",1,d1,12345,cd1 };
	LinkedList<Course> list;
	addList(list, &inputCourse);
	Node<Course>* here = list.pHead;
	while (here) {
		addList(here->data.EnrollStudentList, &AddStudent);
		here = here->pNext;
	}
	Node<Course>* tmp = list.pHead;
	while (tmp) {
		addList(tmp->data.scoreBoard, &inputScore);
		tmp = tmp->pNext;
	}
	viewScoreBoard(list, s1);
	deallocateAll(cd1);
	deallocateAll(list);
	return 0;*/

	LinkedList<Year> listYear;
	addList(listYear, &inputYear);
	Node <Year>* temp = listYear.pHead;
	while (temp) {
		addList(temp->data.ListSemester, &inputSemester);
		temp = temp->pNext;
	}
	Course cur = inputCourse();
	addList(listYear.pHead->data.ListSemester.pHead->data.ListCourse, &inputCourse);
	viewListCoursethisSemester(listYear);

}
