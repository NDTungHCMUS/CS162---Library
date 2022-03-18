#include "year.h"

void CreateYear(yearNode* &pHeadYear)
{
	int temp;
	cout << "Type in Year Start: ";
	cin >> temp;
	yearNode* current = new yearNode;
	current = pHeadYear;
	if (pHeadYear == nullptr) {
		pHeadYear = new yearNode;
		current = pHeadYear;
	}
	else {
		current->pNext = new yearNode;
		current = current->pNext;
	}
	current->yearStart = temp;
}
