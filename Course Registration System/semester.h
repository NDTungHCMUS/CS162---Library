#pragma once
#include "linkedList.h"
#include "student.h"
#include "course.h"

struct Semester {
	int SemesterNumb;
	LinkedList<Course> ListCourse;
};
