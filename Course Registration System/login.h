#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <iostream>
#include<fstream>
#include<string>
#include"linkedList.h"
#include"year.h"
#include <chrono>
#include <ctime>

using namespace std;
typedef std::chrono::system_clock Clock;
struct ListLogin
{
    string id;
    string pas;
    ListLogin *next = NULL;
};
bool checkExistAccount(ifstream& fin, string toCheck);

void deleteListLogin(ListLogin* &lhead);
void outList(ListLogin* &lhead);

void login(LinkedList<Year> &ListYear);

bool loginSt(string &ID,string &pass, ListLogin* &lhead, ListLogin* &position,ifstream &loginFile);

void RegisterStaff(LinkedList<Year> &ListYear);
void RegisterStudent(LinkedList<Year> &ListYear);

void saveStaff(ListLogin* &lhead);
void saveStudent(ListLogin* &lhead);

void loginStudent(ListLogin* &lhead, ListLogin* &position, LinkedList<Year> &ListYear);
void loginStaff(ListLogin* &lhead, ListLogin* &position, LinkedList<Year> &ListYear);

#endif // LOGIN_H_INCLUDED
