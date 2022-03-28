#pragma once
#include "linkedList.h"
#include "student.h"

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
void outputCourseMenu();
bool checkAvailable(Course a, Student s);
void enrollCourse(LinkedList<Course> &ListCourse, Student &a);
bool checkSessionConflict(Session s1, Session s2);
CourseData addCourseData(Course a);
void outputCourseData(Student a);