#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "student.h"

using namespace std;

struct Class {
	string classname = "";
	LinkedList<Student> listOfStudents;
};

Class inputClass();
void outputClass(Class c1);
void outputListClass(LinkedList <Class> ListClass);
void outputStuListFile(Class c1);