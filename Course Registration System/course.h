#pragma once
#include "linkedList.h"
#include "student.h"

struct Regis {
	Date start;
	Date end;
};

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

void importScoreboard(LinkedList<Course> &ListCourse);
void outputScoreBoardMenu();
void outputScoreBoard(Score s1);
void viewScoreBoardOfCourse(LinkedList<Course> &ListCourse);
void updateAStudent(LinkedList<Course> &ListCourse);

void outputStudentInCourse(LinkedList<Course> ListCourse);
void viewEnrollCourse(Student s1);
void removeCourseFromEnrollList(Student s1);

// view scoreboard of stu
bool checkIfStudentInCourse(Course c1, Student s1);
bool checkIfStudentInListCourse(LinkedList<Course> listCourse, Student s);
Score inputScore();
void scoreBoardMenu();
void outputScore(Node<Course>* c1, Student s);
void viewScoreBoard(LinkedList<Course> ListCourse, Student s1);
void student(string ID, LinkedList <Course> ListCourse);