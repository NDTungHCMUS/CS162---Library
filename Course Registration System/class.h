#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "linkedList.h"
#include "student.h"

using namespace std;

struct Class {
	string classname = "";
	LinkedList<Student> listOfStudents;
};

bool checkExistClass(LinkedList<Class> ListClass, string check);
void outputClass(Class c1);
void outputListClass(LinkedList <Class> ListClass);
void outputStuListFile(Class c1);
