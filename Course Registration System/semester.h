#pragma once
#include "linkedList.h"
#include "student.h"

struct Semester {
	int SemesterNumb;
	LinkedList<Course> ListCourse;
};