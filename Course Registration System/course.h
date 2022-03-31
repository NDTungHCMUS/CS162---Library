#pragma once
#include "linkedList.h"
#include "student.h"

struct Score
{
    int no;
    int ID;
    string fullname;
    float totalMark, finalMark, midtermMark, otherMark;
};

struct Course {
	string ID;
	string CourseName;
	string TeacherName;
	int NumbOfCredits;
	int MaxStudent = 50;
	int NumbOfStudent = 0;
	Session s1;
	Session s2;
	LinkedList<Student> EnrollStudentList;
	LinkedList<Score> scoreBoard;
};


Course inputCourse();
void outputAllCourse(LinkedList<Course> ListCourse);
void removeCourse(LinkedList<Course> ListCourse);
void outputCourseMenu();
bool checkAvailable(Course a, Student s);
void enrollCourse(LinkedList<Course> &ListCourse, Student &a);
bool checkSessionConflict(Session s1, Session s2);
CourseData addCourseData(Course a); //of a student
void outputCourseData(Student a);
void importScoreboard(Course &a);

void outputStudentInCourse(LinkedList<Course> ListCourse);
void viewEnrollCourse(Student s1);
void removeCourseFromEnrollList(Student s1);