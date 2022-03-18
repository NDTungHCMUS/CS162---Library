#pragma once
#include <iostream>
#include <string.h>
#include "linkedList.h"
using namespace std;
struct yearNode {
	int yearStart;
	Node<Class>* pHeadClass = NULL;
	yearNode* pNext = NULL;
};

void CreateYear(yearNode* &pHeadYear);
void CreateClasses(Node<Class>* &pHeadClass);
bool checkClass(Node<Class>* pHeadClass, string ClassName);


