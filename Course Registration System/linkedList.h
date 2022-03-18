#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* pNext;
};

template <typename T>
struct LinkedList {
	Node<T>* pHead = NULL;
    Node<T>* pTail = NULL;
};

// add element behind the list
template <typename T> 
void add(LinkedList<T> &l1, T item) {
    Node<T>* node = new Node<T>;
    node->data = item;
    if (l1.pHead == NULL) {
        l1.pHead = node;
        l1.pTail = l1.pHead;
        cout << "Node added at head." << endl;
        return;
    }
    l1.pTail->pNext = node;
    l1.pTail = l1.pTail->pNext;
    cout << "Node added back." << endl;
}

// add element before the list
template<typename T>
void addFront(LinkedList<T> &l1, T item) {
    Node<T>* node = new Node<T>;
    node->data = item;
    if (l1.pHead == NULL) {
        l1.pHead = node;
        l1.pTail = l1.pHead;
        cout << "First node added" << endl;
        return;
    }
    node->next = l1.pHead;
    l1.pHead = node;
    cout << "Added at head" << endl;
}

// count number of elements
template <typename T>
int length(LinkedList<T> l1) {
    int len = 0;
    Node<T>* temp = l1.pHead;
    while (temp != NULL) {
        len++;
        temp = temp->pNext;
    }
    return len;
}

// add to index of the list
template <typename T>
void addIndex(LinkedList<T> &l1, T item, int index) {
    if (index > length(l1) || index < 0) {
        cout << "Invalid" << endl;
        return;
    }
    Node<T>* node = new Node<T>;
    node->data = item;
    int count = 0;
    Node<T>* temp = l1.pHead;
    while (temp != NULL && count < index) {
        if (count == index - 1) {
            if (temp->next != NULL) {
                node->next = temp->next;
            }
            temp->next = node;
            l1.pTail = temp->pNext;
            cout << "new node added at index " << index << " !" << endl;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

// Display all elements in the list
template <typename T>
void displayAll(LinkedList<T> l1, void(*outputItem)(T data)) {
    if (l1.pHead == NULL) {
        cout << "Nothing to display";
        return;
    }
    Node<T>* temp = l1.pHead;
    while (temp != NULL) {
        outputItem(temp->data);
        temp = temp->pNext;
    }
}

// deallocate all elements in the list
template <typename T>
void deallocateAll(LinkedList<T> &l1) {
    while (l1.pHead != NULL) {
        Node<T>* tmp = l1.pHead;
        l1.pHead = l1.pHead->pNext;
        delete tmp;
    }
}


