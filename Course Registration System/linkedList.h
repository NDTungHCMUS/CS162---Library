#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* pNext;
};

template <typename T>
struct LinkedList {
	Node<T>* pHead = nullptr;
	int eleNums = findEleNums(pHead, eleNums);
	int findEleNums(Node<T>* pHead, int &eleNums) {
		int count = 0;
		while (pHead != nullptr) {
			Node<T>* cur = pHead;
			count += 1;
			cur = cur->pNext;
		}
		return count;
	}
};

template <typename T> 
void add(Node<T>* pHead, T item) {
    Node<T>* node = new Node<T>;
    node->data = item;
    if (head == NULL) {
        pHead = node;
        cout << "Node added at head." << endl;
        return;
    }
    Node<T>* temp = pHead;
    while (temp->pNext != NULL) {
        temp = temp->pNext;
    }
    temp->pNext = node;
    cout << "Node added back." << endl;
}


