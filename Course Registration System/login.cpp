#include <iostream>
#include<fstream>
#include<string>
#include"login.h"
const char *studenttxt = "loginStudentList.txt";
const char *stafftxt = "loginStaffList.txt";
using namespace std;
void login()

{
    system("cls");

    ListLogin *lhead;
    ListLogin *position = nullptr;

    cout << "WELL COME TO OUR COURSE REGISTRATION SYSTEM" << endl;
    cout << "Are you:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Staff member" << endl;
    char x;
    cin >> x;
    if (x == '1' || x == '2')
    {
        if (x == '1')
        {
            cout << "** Student  ** \n";
            cout << "1. Register" << endl;
            cout << "2. login" << endl;
            cout << "3. Back" << endl;
            cin >> x;
            if (x == '1')
            {
                RegisterStudent();
            }
            else if (x == '2')
            {
                loginStudent(lhead, position );
            }
            else if (x == '3') login();
        }
        else if (x == '2')
        {
            cout << "** Academic Staff  ** \n";
            cout << "1. Register" << endl;
            cout << "2. login" << endl;
            cout << "3. Back" << endl;
            cin >> x;
            if (x == '1')
            {
                RegisterStaff();
            }
            else if (x == '2')
            {
                loginStaff(lhead, position );
            }
            else if (x == '3') login();
        }
        else if (x == '3') exit(0);
    }

    deleteListLogin(lhead);
}
void RegisterStaff()
{
    system("cls");
    cout << "*** Register Staff ***\n";
    string tmp;
    ofstream loginFile;
    loginFile.open(stafftxt, ios::app);
    cout << "Select ID: ";
    cin >> tmp;
    loginFile << tmp << endl;
    cout << endl << "Select Password: ";
    cin >> tmp;
    loginFile << tmp << endl;
    loginFile.close();
    cout << "successful!, please login again!\n";
    system("pause");
    login();
}
void RegisterStudent()
{
    system("cls");
    cout << "*** Register Student ***\n";
    string tmp;
    ofstream loginFile;
    loginFile.open(studenttxt, ios::app);
    cout << "Select ID: ";
    cin >> tmp;
    loginFile << tmp << endl;
    cout << endl << "Select Password: ";
    cin >> tmp;
    loginFile << tmp << endl;
    loginFile.close();
    cout << "successful!, please login again!\n";
    system("pause");
    login();
}
void loginStudent(ListLogin* &lhead, ListLogin* &position)
{
    system("cls");
    cout << "** Login Student ** \n";
    string ID, pass;
    cout << "ID: ";
    cin >> ID;
    cout << "PASSWORD: ";
    cin >> pass;
    ifstream loginFile;
    loginFile.open(studenttxt);
    if (loginSt(ID, pass, lhead, position,loginFile) == true)
    {
        char tmp = '2';
        while(tmp == '2')
        {
            system("cls");
            cout << "** Well Come " << ID << " **\n";
            cout << "1. My Account" << endl;
            cout << "2. My Course" << endl;
            cout << "3. log out" << endl;
            char x;
            cin >> x;
            if (x == '1')
            {
                cout << "*** User account ***\n";
                cout << "1. Change password" << endl;
                cout << "2. Back "<< endl;
                cin >> tmp;
                if (tmp == '2') continue;
                string current = "";
                if (tmp == '1')
                {
                    while (current != position->next->pas)
                    {
                        system("cls");
                        cout << "*** Change Password ***\n";
                        cout << "Please enter current password :";
                        cin >> current;
                        if (current != position->next->pas)
                        {

                            cout << endl;
                            cout << "Password Incorrect, Please try again!";
                            system("pause");
                            continue;
                        }
                        cout << endl;
                        cout << "Please enter new password : ";
                        cin >> current;
                        position->next->pas = current;
                        loginFile.close();
                        saveStudent(lhead);
                        cout << endl;
                        cout << "Change Password successful, please login again!";
                        system("pause");
                        deleteListLogin(lhead);

                        login();
                    }
                }
            }
            else if (x == '2')
            {
                // course();
            }
            else if (x == '3')
            {
                deleteListLogin(lhead);
                loginFile.close();
                login();
            }
        }
    }
    else
    {
        loginFile.close();
        deleteListLogin(lhead);
        cout <<"ID OR PASSWORD INCORECT, PLEASE TRY AGIAIN" << endl;
        system("pause");
        login();
    }

}
void loginStaff(ListLogin* &lhead, ListLogin* &position)
{
    system("cls");
    cout << "** Login Staff ** \n";
    string ID, pass;
    cout << "ID: ";
    cin >> ID;
    cout << "PASSWORD: ";
    cin >> pass;
    ifstream loginFile;
    loginFile.open(stafftxt);
    if (loginSt(ID, pass, lhead, position,loginFile) == true)
    {
        char tmp = '2';
        while(tmp == '2')
        {
            system("cls");
            cout << "** Well Come " << ID << " **\n";
            cout << "1. My Account" << endl;
            cout << "2. My Course" << endl;
            cout << "3. log out" << endl;
            char x;
            cin >> x;
            if (x == '1')
            {
                cout << "*** User account ***\n";
                cout << "1. Change password" << endl;
                cout << "2. Back "<< endl;
                cin >> tmp;
                if (tmp == '2') continue;
                string current = "";
                if (tmp == '1')
                {
                    while (current != position->next->pas)
                    {
                        system("cls");
                        cout << "*** Change Password ***\n";
                        cout << "Please enter current password :";
                        cin >> current;
                        if (current != position->next->pas)
                        {

                            cout << endl;
                            cout << "Password Incorrect, Please try again!";
                            system("pause");
                            continue;
                        }
                        cout << endl;
                        cout << "Please enter new password : ";
                        cin >> current;
                        position->next->pas = current;
                        loginFile.close();
                        saveStaff(lhead);
                        cout << endl;
                        cout << "Change Password successful, please login again!";
                        system("pause");
                        deleteListLogin(lhead);

                        login();
                    }
                }

            }
            else if (x == '2')
            {
                // course();
            }
            else if (x == '3')
            {
                deleteListLogin(lhead);
                loginFile.close();
                login();
            }
        }
    }
    else
    {
        loginFile.close();
        deleteListLogin(lhead);
        cout <<"ID OR PASSWORD INCORECT, PLEASE TRY AGIAIN" << endl;
        system("pause");
        login();
    }
}
void saveStaff(ListLogin* &lhead)
{
    ofstream outfile;
    outfile.open(stafftxt);
    for (ListLogin *cur = lhead; cur != nullptr; cur = cur->next)
        outfile << cur->id << endl << cur->pas << endl;
    outfile.close();
}
void saveStudent(ListLogin* &lhead)
{
    ofstream outfile;
    outfile.open(studenttxt);
    for (ListLogin *cur = lhead; cur != nullptr; cur = cur->next)
        outfile << cur->id << endl << cur->pas << endl;
    outfile.close();
}
void deleteListLogin(ListLogin* &lhead)
{
    ListLogin *tmp = lhead;
    while(tmp != nullptr)
    {
        delete tmp;
        lhead = lhead->next;
        tmp = lhead;
    }
}
void outList(ListLogin* &lhead)
{
    for (ListLogin *cur = lhead; cur != nullptr; cur = cur->next)
    {
        cout << endl << cur->id;
        cout << endl << cur->pas;
    }
}
bool loginSt(string &ID,string &pass, ListLogin* &lhead, ListLogin* &position, ifstream &loginFile)
{

    ListLogin *dummy = new ListLogin;
    dummy->id = "";
    dummy->pas = "";
    dummy->next = nullptr;
    ListLogin *cur = dummy;

    string ID1 = "";
    string pass1 = "";
    bool check = false;

    while (loginFile >> ID1 >> pass1)
    {
        ListLogin *tmp = new ListLogin;
        tmp->id = ID1;
        tmp->pas = pass1;
        tmp->next = nullptr;
        cur->next = tmp;

        if (ID1 == ID && pass1 == pass)
        {
            check = true;
            position = cur;
        }
        cur = cur->next;
    }
    lhead = dummy->next;
    delete dummy;
    if (check == true) return true;
    else return false;
}
