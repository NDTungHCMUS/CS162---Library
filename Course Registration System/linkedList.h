#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::ifstream;
using std::endl;
using std::cin;
using std::ofstream;
using std::left;
using std::setw;

template <class T>
struct Node
{
	T data;
	Node* pNext = NULL;
};

template <class T>
struct LinkedList {
	Node<T>* pHead = NULL;
    Node<T>* pTail = NULL;
};

// FUNCTIONS PROTOTYPE:
template <class T>
void add(LinkedList<T>& l1, T item); // add to last of the list

template<class T>
void addFront(LinkedList<T>& l1, T item); // add to front of the list

template<class T>
bool findIndex(LinkedList<T> TList, int index, T& findEle); // find an element of the list through index

template <class T>
int length(LinkedList<T> l1); // find the length of the list

template <class T>
void addIndex(LinkedList<T>& l1, T item, int index); // add a node to a specific index

template <class T>
void displayAll(LinkedList<T> l1, void(*outputItem)(T data)); // display all elements of the list

template <class T>
void deallocateAll(LinkedList<T>& l1); // deallocate the list

template <class T>
void removeFront(LinkedList<T>& l1); // remove first element

template <class T>
void removeIndex(LinkedList<T>& l1, int index); // remove specific node

template <class T>
void addList(LinkedList<T>& l1, T(*inputItem)()); //add a list of things

// update an existing item
template <class T>
//index here represent the order of the element in the list, starting with 1, not 0
void updateIndex(LinkedList<T>& l1, int index, T(*inputT)());

// read a csv file, using stringstream.
// to use, we need an input from string function for each type of object
template <class T>
void inputFile(LinkedList<T>& TList, void(*inputTFile)(T&, string), string& filename);

// output info of a list to a csv file
template <class T>
void outputListFile(LinkedList<T> TList, ofstream& foutList, void(*outputFileT)(T, ofstream&));



// FUNCTIONS DEFINITIONS:
// add element behind the list
template <class T>
void add(LinkedList<T> &l1, T item) {
    Node<T>* node = new Node<T>;
    node->data = item;
    if (l1.pHead == NULL) {
        l1.pHead = node;
        l1.pTail = l1.pHead;
        return;
    }
    l1.pTail->pNext = node;
    l1.pTail = l1.pTail->pNext;
}

// add element before the list
template<class T>
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

// find an element of the list through index
template<class T>
bool findIndex(LinkedList<T> TList, int index, T &findEle) {
    bool flag = false;
    if (index > length(TList) || TList.pHead == nullptr) {
        return flag;
    }
    else {
        int count = 1;
        Node<T>* track = TList.pHead;
        while (count != index) {
            track = track->pNext;
            ++count;
        }
        findEle = track->data;
        flag = true;
        return flag;
    }
}

// count number of elements
template <class T>
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
template <class T>
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
            if (temp->pNext != NULL) {
                node->pNext = temp->pNext;
            }
            temp->pNext = node;
            if (temp->pNext == nullptr) {
                l1.pTail = temp->pNext;
            }
            cout << "new node added at index " << index << " !" << endl;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

// Display all elements in the list
template <class T>
void displayAll(LinkedList<T> l1, void(*outputItem)(T data)) {
    if (l1.pHead == NULL) {
        cout << "Nothing to display";
        return;
    }
    Node<T>* temp = l1.pHead;
    int i = 0;
    while (temp != NULL) {
        ++i;
        cout << left << setw(5) <<i;
        outputItem(temp->data);
        temp = temp->pNext;
    }
}

// deallocate all elements in the list
template <class T>
void deallocateAll(LinkedList<T> &l1) {
    while (l1.pHead != NULL) {
        Node<T>* tmp = l1.pHead;
        l1.pHead = l1.pHead->pNext;
        delete tmp;
    }
}

// delete front
template <class T>
void removeFront(LinkedList<T> &l1) {
    if (l1.pHead == NULL) {
        return;
    }
    Node<T>* tmp = l1.pHead;
    l1.pHead = l1.pHead->pNext;
    delete tmp;
}

// remove a node at a specific index
template <class T>
void removeIndex(LinkedList<T> &l1, int index) {
    if (l1.pHead == NULL) {
        cout << "Empty list, nothing to remove." << endl;
        return;
    }
    if (index >= length(l1) || index < 0) {
        cout << "Invalid." << endl;
        return;
    }
    if (index == 1) {
        removeFront(l1);
        return;
    }

    int count = 0;
    Node<T>* temp = l1.pHead;
    while (temp != NULL) {
        if (count == index - 1) {
            Node<T>* delItem = temp->pNext;
            temp->pNext = temp->pNext->pNext;
            delete delItem;
            cout << "Item removed" << endl;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

// add a list of item
template <class T>
void addList(LinkedList<T> &l1, T(*inputItem)()) {
    cout << setw(45) << " " << "Choose your option: " << endl
         << setw(45) << " " << "1. Input." << endl
         << setw(45) << " " << "2. Exit." << endl;
    cout << setw(45) << " " << "Choice: ";
    char choice;
    cin >> choice;
    system("cls");
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
        system("cls");
        addList(l1, inputItem);
        return;
    }
    else if (choice == '2') {
        cout << setw(40) << " " << "Quit inputing" << endl;
        return;
    }
    else {
        cout << setw(40) << " " << "Invalid, try another choice." << endl;
        cout << setw(40) << " "; system("pause");
        system("cls");
        addList(l1, inputItem);
        return;
    }
}

// update an existing item
template <class T>
//index here represent the order of the element in the list, starting with 1, not 0
void updateIndex(LinkedList<T>& l1, int index, T(*inputT)()) {
    if (index > length(l1)) {
        cout << "Invalid choice." << endl;
        return;
    }
    else if (l1.pHead == nullptr) {
        cout << "List empty." << endl;
        return;
    }
    else {
        int count = 1;
        Node<T>* track = l1.pHead;
        while (count != index) {
            track = track->pNext;
            ++count;
        }
        track->data = inputT();
        cout << "Data modified !" << endl;
        return;
    }
}

// read a csv file, using stringstream.
// to use, we need an input from string function for each type of object
template <class T>
void inputFile(LinkedList<T> &TList, void(*inputTFile)(T &, string), string &filename) {

    //cout << "Input file name: ";
    //getline(cin, filename, '\n');
    string line;
    ifstream file;
    Node<T> dummy;
    Node<T>* ptr = &dummy;
    int i = 0;
    file.open(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line, '\n');
            ptr->pNext = new Node<T>;
            ptr = ptr->pNext;
            inputTFile(ptr->data, line);
        }
    }
    else {
        cout << "Can not open file." << endl;
    }
    file.close();
    TList.pHead = dummy.pNext;
    TList.pTail = ptr;
}
// output info of a list to a csv file
template <class T>
void outputListFile(LinkedList<T> TList, ofstream &foutList, void(*outputFileT)(T, ofstream &)) {
    while (TList.pHead != nullptr) {
        outputFileT(TList.pHead->data, foutList);
        if (TList.pHead->pNext != nullptr) {
            foutList << endl;
        }
        TList.pHead = TList.pHead->pNext;
    }
}
