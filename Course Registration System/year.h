#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "linkedList.h"
#include "class.h"
#include "semester.h"

using namespace std;

struct Year {
	int yearStart;
	LinkedList<Semester> ListSemester;
	LinkedList<Class> Listclass;
};

void CreateYear(LinkedList<Year>& yearList);
void inputStudentCSV(LinkedList<Year> &ListYear, string &className);

Year inputYear();
