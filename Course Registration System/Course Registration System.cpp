#include <iostream>
#include "class.h"
#include "login.h"
#include "year.h"
#include "student.h"
#include "linkedList.h"

using namespace std;

int main()
{
	LinkedList<Year> listYear;
	Year y1{ 2020 };
	Year y2{ 2021 };
	Year y3{ 2022 };
	add(listYear, y1);
	add(listYear, y2);
	addFront(listYear, y3);
	cout << length(listYear) << endl;
	addList(listYear, &inputYear);
	addList(listYear.pHead->data.Listclass, &inputClass);
	deallocateAll(listYear);
	return 0;
}


