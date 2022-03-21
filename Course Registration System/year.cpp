#include "year.h"
using namespace std;

void CreateYear(LinkedList<Year>& yearList) {
	Node<Year>* current = yearList.pHead;
	int temp;
	cout << "Type in Year Start: ";
	cin >> temp;
	if (yearList.pHead == nullptr) {
		yearList.pHead = new Node<Year>;
		yearList.pTail = yearList.pHead;
		current = yearList.pHead;
	}
	else {
		yearList.pTail->pNext = new Node<Year>;
		yearList.pTail = yearList.pTail->pNext;
		yearList.pTail->data.yearStart = temp;
	}
}

Year inputYear() {
	Year res{0, nullptr};
	cout << "input year start: ";
	cin >> res.yearStart;
	return res;
}