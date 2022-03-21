#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "linkedList.h"
#include "class.h"

using namespace std;

struct Year {
	int yearStart;
	LinkedList<Class> Listclass;
};

void CreateYear(LinkedList<Year>& yearList);
Year inputYear();

