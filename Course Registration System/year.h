#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "class.h"
#include "semester.h"

using namespace std;

struct Year {
	int yearStart;
	LinkedList<Semester> ListSemester;
	LinkedList<Class> Listclass;
};

void CreateYear(LinkedList<Year>& yearList);
Year inputYear();