#pragma once
#include "course.h"

struct Semester {
	int SemesterNumb;
	int schoolyear;
	Date startDate;
	Date endDate;
	LinkedList<Course> ListCourse;
};
Semester inputSemester();