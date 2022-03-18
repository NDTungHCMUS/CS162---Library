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
	string Gender;
	Date dob;
	int SocialID;
	Student* pNext;
};