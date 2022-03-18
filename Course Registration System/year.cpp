#include "year.h"

void CreateYear(Node<Year>* &pHeadYear)
{
	Node<Year>* current = pHeadYear;
	int temp;
	cout << "Type in Year Start: ";
	cin >> temp;
	if (pHeadYear == nullptr) {
		pHeadYear = new Node<Year>;
		current = pHeadYear;
	}
	else {
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<Year>;
		current = current->pNext;
	}
	current->data.yearStart = temp;
}