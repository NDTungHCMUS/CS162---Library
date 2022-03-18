#pragma once
#include <iostream>
#include <string.h>
#include "linkedList.h"
#include "student.h"
#include "class.h"
using namespace std;
struct Year {
	int yearStart;
	Node<Class>* pHeadClass = NULL;
};

void CreateYear(Node<Year>* &pHeadYear);
void CreateClasses(Node<Class>* &pHeadClass);
bool checkClass(Node<Class>* pHeadClass, string ClassName);
