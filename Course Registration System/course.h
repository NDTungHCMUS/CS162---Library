#pragma once
#include "linkedList.h"
#include "student.h"


struct Session {
	string day;
	string period;
};

struct Course {
	string ID;
	string CourseName;
	string TeacherName;
	int NumbOfCredits;
	int MaxStudent = 50;
	Session s1;
	Session s2;
	LinkedList<Student> EnrollStudentList;
};

Course inputCourse();
void outputAllCourse(LinkedList<Course> ListCourse);
void removeCourse(LinkedList<Course> ListCourse);