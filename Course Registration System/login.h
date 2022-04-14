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

void login();
bool loginSt(string &ID,string &pass, ListLogin* &lhead, ListLogin* &position,ifstream &loginFile);

void RegisterStaff();
void RegisterStudent();

void saveStaff(ListLogin* &lhead);
void saveStudent(ListLogin* &lhead);

void loginStudent(ListLogin* &lhead, ListLogin* &position);
void loginStaff(ListLogin* &lhead, ListLogin* &position);

#endif // LOGIN_H_INCLUDED
