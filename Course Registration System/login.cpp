#include"login.h"
const char *studenttxt = "loginStudentList.txt";
const char *stafftxt = "loginStaffList.txt";
using namespace std;

bool checkExistAccount(ifstream& fin, string toCheck) {
    string check;
    string skip;
    while (!fin.eof()) {
        getline(fin, check, '\n');
        if (check == toCheck) {
            return true;
        }
        getline(fin, skip, '\n');
    }
    return false;
}

void login()

{
    system("cls");

    ListLogin *lhead = nullptr;
    ListLogin *position = nullptr;

    cout << "WELCOME TO OUR COURSE REGISTRATION SYSTEM" << endl;
    cout << "Are you:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Staff member" << endl;
    cout << "3. Exit" << endl;
    char x;
    cin >> x;
    if (x == '1' || x == '2')
    {
        if (x == '1')
        {
            system("cls");
            char t;
            cout << "** Student  ** \n";
            cout << "1. Register" << endl;
            cout << "2. login" << endl;
            cout << "3. Back" << endl;
            cin >> t;
            if (t == '1')
            {
                RegisterStudent();
            }
            else if (t == '2')
            {
                loginStudent(lhead, position );
            }
            else if (t == '3') login();
        }
        else if (x == '2')
        {
            system("cls");
            cout << "** Academic Staff  ** \n";
            cout << "1. Register" << endl;
            cout << "2. login" << endl;
            cout << "3. Back" << endl;
            char t;
            cin >> t;
            if (t == '1')
            {
                RegisterStaff();
            }
            else if (t == '2')
            {
                loginStaff(lhead, position );
            }
            else if (t == '3') login();
        }

    }
    else if (x == '3')
    {
        deleteListLogin(lhead);
        exit(0);
    }
    deleteListLogin(lhead);
}
void RegisterStaff()
{
    system("cls");
    cout << "*** Register Staff ***\n";
    string tmp;
    ifstream checkFile;
    ofstream loginFile;
    checkFile.open(studenttxt);
    loginFile.open(stafftxt, ios::app);
    cout << "Select ID: ";
    cin >> tmp;
    bool checkEx = checkExistAccount(checkFile, tmp);
    while (checkEx) {
        cout << "ID exist, try again: ";
        cin >> tmp;
        checkEx = checkExistAccount(checkFile, tmp);
    }
    loginFile << endl << tmp;
    cout << "Select Password: ";
    cin >> tmp;
    loginFile << endl << tmp;
    loginFile.close();
    cout << "Successful!, please login again!\n";
    system("pause");
    login();
}
void RegisterStudent()
{
    system("cls");
    cout << "*** Register Student ***\n";
    string tmp;
    ifstream checkFile;
    ofstream loginFile;
    checkFile.open(studenttxt);
    loginFile.open(studenttxt, ios::app);
    cout << "Select ID: ";
    cin >> tmp;
    bool checkEx = checkExistAccount(checkFile, tmp);
    while (checkEx) {
        cout << "ID exist, try again: ";
        cin >> tmp;
        checkEx = checkExistAccount(checkFile, tmp);
    }
    loginFile << endl << tmp;
    cout << "Select Password: ";
    cin >> tmp;
    loginFile << endl << tmp;
    loginFile.close();
    checkFile.close();
    cout << "Successful!, please login again!\n";
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
            cout << "** Welcome " << ID << " **\n";
            cout << "1. My Account" << endl;
            cout << "2. My Course" << endl;
            cout << "3. Log out" << endl;
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
        cout <<"ID OR PASSWORD INCORECT, PLEASE TRY AGAIN" << endl;
        system("pause");
        login();
    }

}
void loginStaff(ListLogin* &lhead, ListLogin* &position)
{
    LinkedList<Year> ListYear;
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
            cout << "** Welcome " << ID << " **\n";
            cout << "1. My Account" << endl;
            cout << "2. Staff's Activities" << endl;
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
                cout << "*** Staff's Activities ***" << endl;
                cout << "1. Create new school year" << endl;
                cout << "2. Create new class" << endl;
                cout << "3..." << endl;
                cout << "4. Import student from CSV file" << endl;
                int temp;
                cin >> temp;
                if (temp == 1)
                {
                    CreateYear(ListYear);
                }
                else if (temp == 2)
                {
                    addList(ListYear.pHead->data.Listclass, inputClass);
                    /*displayAll(ListYear.pHead->data.Listclass, outputClass);
                    system("pause");*/
                }
                else if (temp == 4)
                {

                    string className;
                    cout << "Type in class's name: ";
                    getline(cin >> ws, className);
                    LinkedList<Student> s;
                    // ListYear.pHead->data.Listclass.pHead->data.listOfStudents

                    Node<Class> *current = ListYear.pHead->data.Listclass.pHead;
                    bool check = false;
                    while (current != nullptr)
                    {
                        if (current->data.classname == className)
                        {
                            s = current->data.listOfStudents;
                            check = true;
                            break;
                        }
                        current = current->pNext;
                    }
                    if (check == false)
                    {
                        cout << "Can not find this class, please try again!" << endl;
                        continue;
                    }
                    string filename = className + "Student.csv";
                    inputFile(s,inputStudentFile,filename);
                    current = ListYear.pHead->data.Listclass.pHead;
                    while (current != nullptr)
                    {
                        if (current->data.classname == className)
                        {
                            current->data.listOfStudents = s;
                            break;
                        }
                        current = current->pNext;
                    }
                 //   outputAllStudent(s);
                    //Node<Class> *current = ListYear.pHead->data.Listclass.pHead;
                    system("pause");

                }
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
        lhead = lhead->next;
        delete tmp;
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
