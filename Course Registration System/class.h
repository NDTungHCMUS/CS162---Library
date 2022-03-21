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

Class inputClass();