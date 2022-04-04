/*#include "linkedListTemplate.h"

// READ A LIST FROM EXTERNAL FILE
template <typename T>
void readList(item<T>* &pHead, void(*read)(item<T>* &pTHead)) {
    read(pHead);
}

// ADD AN ELEMENT TO THE BACK OF THE LIST
template <typename T>
void addElement(item<T>* &pHead, item<T> toAdd) {
    item<T> toAddItem = new item {toAdd.val, nullptr};
    if (pHead == nullptr) {
        pHead = toAddItem;
        return;
    }
    item<T> current = pHead;
    while (current->pNext != nullptr) {
        current = current->pNext;
    }
    current->pNext = toAddItem;
}

// ADD AN ITEM TO THE FRONT OF THE LIST
template <typename T>
void addFront(item<T>* &pHead, item<T> toAddHead) {
    item<T>* newFront = new item {toAddHead.val, nullptr};
    newFront->pNext = pHead;
    pHead = newFront;
}

// DEALLOCATE MEMORY
template <typename T>
void deallocate(item<T>* &pHead) {
    while (pHead != nullptr) {
        item<T>* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
}*/

