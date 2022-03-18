#include "year.h"

void CreateYear(yearNode* &pHeadYear)
{
	yearNode* current = pHeadYear;
	if (pHeadYear == nullptr) {
		pHeadYear = new node;
		pHeadYear->pNext = nullptr;
		current = pHeadYear;
	}
	else {

	}

}
