#pragma once
#include "linkedList.h"
using namespace std;


struct Date {
	int day;
	int month;
	int year;
};

struct Student {
	int No;
	int StudentID;
	string FirstName;
	string LastName;
	int Gender; //1 is Male, 2 is Female
	Date dob;
	int SocialID;
};

Student AddStudent();
void inputStudentFile(Student& s1, string line);
void outputStudent(Student s1);
void outputAllStudent(LinkedList<Student> ListStudent);
void outputStudentFile(Student s1, ofstream& foutList);
Student findStudent(LinkedList<Student> ListStudent);