#pragma once
#include "course.h"

struct Semester {
	int SemesterNumb;
	LinkedList<Course> ListCourse;
};
Semester inputSemester();