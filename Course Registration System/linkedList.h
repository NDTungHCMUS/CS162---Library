#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "student.h"
#include "login.h"
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* pNext = NULL;
};

template <typename T>
struct LinkedList {
	Node<T>* pHead = NULL;
    Node<T>* pTail = NULL;
};

// FUNCTIONS PROTOTYPE:
template <typename T>
void add(LinkedList<T>& l1, T item); // add to last of the list

template<typename T>
void addFront(LinkedList<T>& l1, T item); // add to front of the list

template <typename T>
int length(LinkedList<T> l1); // find the length of the list

template <typename T>
void addIndex(LinkedList<T>& l1, T item, int index); // add a node to a specific index

template <typename T>
void displayAll(LinkedList<T> l1, void(*outputItem)(T data)); // display all elements of the list

template <typename T>
void deallocateAll(LinkedList<T>& l1); // deallocate the list

template <typename T>
void removeFront(LinkedList<T>& l1); // remove first element

template <typename T>
void remove(LinkedList<T>& l1, int index); // remove specific node



// FUNCTIONS DEFINITIONS:
// add element behind the list
template <typename T> 
void add(LinkedList<T> &l1, T item) {
    Node<T>* node = new Node<T>;
    node->data = item;
    if (l1.pHead == NULL) {
        l1.pHead = node;
        l1.pTail = l1.pHead;
        cout << "Element added at head." << endl;
        return;
    }
    l1.pTail->pNext = node;
    l1.pTail = l1.pTail->pNext;
    cout << "Element added back." << endl;
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
    node->pNext = l1.pHead;
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

// delete front
template <typename T>
void removeFront(LinkedList<T> &l1) {
    if (l1.pHead == NULL) {
        cout << "linked list is empty !" << endl;
        return;
    }
    Node<T>* tmp = l1.pHead;
    l1.pHead = l1.pHead->pNext;
    delete tmp;
    cout << "front item removed" << endl;
}

// remove a node at a specific index
template <typename T>
void remove(LinkedList<T> &l1, int index) {
    if (l1.head == NULL) {
        cout << "Empty list, nothing to remove." << endl;
        return;
    }
    if (index >= length(l1) || index < 0) {
        cout << "Invalid." << endl;
        return;
    }
    if (index == 0) {
        removeFront(l1);
        cout << "item removed at index " << index << endl;
        return;
    }

    int count = 0;
    Node<T>* temp = l1.pHead;
    while (temp != NULL) {
        if (count == index - 1) {
            temp->pNext = temp->pNext->pNext;
            cout << "item removed at index " << index << endl;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

// add a list of item
template <typename T>
void addList(LinkedList<T> l1, T(*inputItem)()) {
    cout << "Choose your option: " << endl
         << "1. Input." << endl
         << "2. Exit." << endl;
    char choice;
    cin >> choice;
    if (choice == '1') {
        T temp = inputItem();
        Node<T>* tmp = new Node<T>;
        tmp->data = temp;
        if (l1.pHead == NULL) {
            l1.pHead = tmp;
            l1.pTail = l1.pHead;
      
        }
        else {
            l1.pTail->pNext = tmp;
            l1.pTail = l1.pTail->pNext;
        }
        cout << "Added, back to choice menu." << endl;
        addList(l1, &inputItem);
        return;
    }
    else if (choice == '2') {
        cout << "Quit inputing" << endl;
        return;
    }
    else {
        cout << "Invalid, try another choice." << endl;
        addList(l1, &inputItem);
        return;
    }
}