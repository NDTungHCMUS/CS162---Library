#include "year.h"
#include "login.h"
using namespace std; 

int main() {
	/*login();*/
	LinkedList<Student> ListStudent;
	LinkedList<Course> ListCourse;
	addList(ListCourse, &inputCourse);
	addList(ListStudent, &AddStudent);
	string ID;
	cin.ignore(1000, '\n');
	getline(cin, ID);
	student(ID, ListCourse, ListStudent);

}

