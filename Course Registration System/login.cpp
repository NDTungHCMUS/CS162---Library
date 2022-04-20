#pragma warning(disable : 4996)
#include"login.h"
const char *studenttxt = "loginStudentList.txt";
const char *stafftxt = "loginStaffList.txt";
using namespace std;
auto now = Clock::now();
Regis reg{};
std::time_t now_c = Clock::to_time_t(now);
struct tm *parts = std::localtime(&now_c);
int year = 1900 + parts->tm_year;
int month = 1    + parts->tm_mon;
int date = parts->tm_mday;
Date today = {date,month,year};
bool checkExistAccount(ifstream& fin, string toCheck)
{
    string check;
    string skip;
    while (!fin.eof())
    {
        getline(fin, check, '\n');
        if (check == toCheck)
        {
            return true;
        }
        getline(fin, skip, '\n');
    }
    return false;
}

void login(LinkedList<Year> &ListYear)
{
    bool check = false;
    while(check == false)
    {
        system("cls");

        ListLogin *lhead = nullptr;
        ListLogin *position = nullptr;

        cout << setw(40) << " " << "WELCOME TO OUR COURSE REGISTRATION SYSTEM" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "1. Student" << setw(18) << " "  "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "2. Staff member" << setw(12) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "3. Exit" << setw(20) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        char x;
        cout << setw(45) << " " << "Input your choice (1 - 3): ";
        cin >> x;
        if (x == '1' || x == '2')
        {
            check = true;
            if (x == '1')
            {
                system("cls");
                char t;

                cout << setw(53) << " " << "** Student  **" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Register" << setw(17) << " "  "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. Login" << setw(19) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "3. Back" << setw(20) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "Input your choice (1 - 3): ";
                while (cin >> t && (t != '1' && t != '2' && t != '3'))
                {
                    cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
                    cout << setw(45) << " ";
                    system("pause");
                    cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
                    cout << setw(45) << " " << "Input your choice (1 - 3): ";
                }
                if (t == '1')
                {
                    RegisterStudent(ListYear);
                }
                else if (t == '2')
                {
                    loginStudent(lhead, position,ListYear );
                }
                else if (t == '3') login(ListYear);
            }
            else if (x == '2')
            {
                system("cls");

                cout << setw(50) << " " << "** Academic Staff **" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Register" << setw(17) << " "  "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. Login" << setw(19) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "3. Back" << setw(20) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;

                char t;
                cout << setw(45) << " ";
                cin >> t;
                if (t == '1')
                {
                    RegisterStaff(ListYear);
                }
                else if (t == '2')
                {
                    loginStaff(lhead, position,ListYear );
                }
                else if (t == '3') login(ListYear);
                else
                {
                    cout << setw(40) << " " << "Invalid input, please try again!" << endl;
                    cout << setw(40) << " ";
                    system("pause");
                    login(ListYear);
                }
            }
        }
        else if (x == '3')
        {
            check = true;
            deleteListLogin(lhead);
            exit(0);
        }
        else
        {
            cout << setw(40) << " " << "Invalid input, please try again!" << endl;
            cout << setw(40) << " ";
            system("pause");
            check = false;
        }
        deleteListLogin(lhead);
    }
}
void RegisterStaff(LinkedList<Year> &ListYear)
{
    system("cls");
    cout << setw(40) << " " << "*** Register Staff ***\n";
    string tmp;
    ifstream checkFile;
    ofstream loginFile;
    checkFile.open(stafftxt);
    cout << setw(40) << " " << "Select ID: ";
    cin >> tmp;
    bool checkEx = checkExistAccount(checkFile, tmp);
    checkFile.close();
    while (checkEx)
    {
        cout << setw(40) << " " << "ID exist, try again: ";
        cin >> tmp;
        checkFile.open(stafftxt);
        checkEx = checkExistAccount(checkFile, tmp);
        checkFile.close();
    }
    loginFile.open(stafftxt, ios::app);
    loginFile << endl << tmp;
    cout << setw(40) << " " << "Select Password: ";
    cin >> tmp;
    loginFile << endl << tmp;
    loginFile.close();
    cout << setw(40) << " " << "Successful!, please login again!\n";
    cout << setw(40) << " ";
    system("pause");
    login(ListYear);
}
void RegisterStudent(LinkedList<Year> &ListYear)
{
    system("cls");
    cout << setw(40) << " " << "*** Register Student ***\n";
    string tmp;
    ifstream checkFile;
    ofstream loginFile;
    checkFile.open(studenttxt);
    cout << setw(40) << " " << "Select ID: ";
    cin >> tmp;
    bool checkEx = checkExistAccount(checkFile, tmp);
    checkFile.close();
    while (checkEx)
    {
        cout << setw(40) << " " << "ID exist, try again: ";
        cin >> tmp;
        checkFile.open(studenttxt);
        checkEx = checkExistAccount(checkFile, tmp);
        checkFile.close();
    }
    loginFile.open(studenttxt, ios::app);
    loginFile << endl << tmp;
    cout << setw(40) << " " << "Select Password: ";
    cin >> tmp;
    loginFile << endl << tmp;
    loginFile.close();
    checkFile.close();
    cout << setw(40) << " " << "Successful!, please login again!\n";
    cout << setw(40) << " ";
    system("pause");
    login(ListYear);
}
void loginStudent(ListLogin* &lhead, ListLogin* &position, LinkedList<Year> &ListYear)
{
    system("cls");
    cout << setw(45) << " " << "** Login Student ** \n";
    string ID,pass;
    int id;
    cout << setw(45) << " " << "ID: ";
    cin >> id;
    ID = to_string(id);
    cout << setw(45) << " " << "PASSWORD: ";
    cin >> pass;
    ifstream loginFile;
    loginFile.open(studenttxt);
    if (loginSt(ID, pass, lhead, position,loginFile) == true)
    {
        char tmp = '2';
        while(tmp == '2')
        {
            system("cls");
            cout << setw(46) << " " << "**** Welcome " << ID << " ****\n";
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "1. My Account" << setw(11) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "2. My Course" << setw(12) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "3. Log out" << setw(14) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            char x;
            cout << setw(45) << " " << "Input your choice (1 - 3): ";
            cin >> x;
            if (x == '1')
            {
                system("cls");
                cout << setw(47) << " " << "*** User account ***\n";
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Change password" << setw(2) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. Back" << setw(13) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "Your choice: ";
                cin >> tmp;
                string current = "";
                if (tmp == '2') continue;
                else if (tmp == '1')
                {
                    while (current != position->next->pas)
                    {
                        system("cls");
                        cout << setw(45) << " " << "*** Change Password ***\n";
                        cout << setw(40) << " " << "Please enter current password :";
                        cin >> current;
                        if (current != position->next->pas)
                        {
                            cout << endl;
                            cout << setw(40) << " " << "Password Incorrect, Please try again!";
                            cout << setw(40) << " ";
                            system("pause");
                            continue;
                        }
                        cout << setw(40) << " " << "Please enter new password : ";
                        cin >> current;
                        position->next->pas = current;
                        loginFile.close();
                        saveStudent(lhead);
                        cout << setw(40) << " " << "Change Password successful, please login again!\n";
                        cout << setw(40) << " ";
                        system("pause");
                        deleteListLogin(lhead);
                        login(ListYear);
                    }
                }
                else
                {
                    cout << setw(45) << " " << "Invalid input, please try again !" << endl;
                    cout << setw(45) << " ";
                    system("pause");
                    continue;
                }
            }
            else if (x == '2')
            {
                student(id, ListYear, today, reg);
            }
            else if (x == '3')
            {
                loginFile.close();
                login(ListYear);
            }
            else
            {
                cout << setw(45) << " " << "Invalid input, please try again !" << endl;
                cout << setw(45) << " ";
                system("pause");
            }
        }
    }
    else
    {
        loginFile.close();
        deleteListLogin(lhead);
        cout << setw(40) << " " << "ID OR PASSWORD INCORECT, PLEASE TRY AGAIN" << endl;
        cout << setw(40) << " ";
        system("pause");
        login(ListYear);
    }
}
void loginStaff(ListLogin* &lhead, ListLogin* &position, LinkedList<Year> &ListYear)
{
    system("cls");
    cout << setw(45) << " " << "** Login Staff ** \n";
    string ID, pass;
    cout << setw(45) << " " << "ID: ";
    cin >> ID;
    cout << setw(45) << " " << "PASSWORD: ";
    cin >> pass;
    ifstream loginFile;
    loginFile.open(stafftxt);
    if (loginSt(ID, pass, lhead, position,loginFile) == true)
    {
        char tmp = '2';
        while(tmp == '2')
        {
            system("cls");
            cout << setw(46) << " " << "**** Welcome " << ID << " ****\n";
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "1. My Account" << setw(11) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "2. Staff's Activities" << setw(3) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            cout << setw(45) << " " << "| " << "3. Log out" << setw(14) << " " << " |" << endl;
            cout << setw(45) << ' ' << "----------------------------" << endl;
            char x;
            cout << setw(45) << " " << "Input your choice (1 - 3): ";
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

                        login(ListYear);
                    }
                }

            }
            else if (x == '2')
            {
                system("cls");
                cout << setw(51) <<' '<< "***** Staff's Activities *****" << endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "0. Change Date" << setw(24) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "1. Create new school year" << setw(13) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "2. Create new class" << setw(19) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "3. Add student into class" << setw(13) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "4. Import student from CSV file" << setw(7) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "5. Semester" << setw(29) <<" " "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "6. View List of class" << setw(17) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "7. View a list of students in a class" << " " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "8. View a list of all courses" << setw(9) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "9. View a list of students in a course" <<"| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) <<" "<< "| "<< "10. End of semester functions" << setw(9) <<" " << "| "<< endl;
                cout << setw(45) <<' '<<"-----------------------------------------" << endl;
                cout << setw(45) << " " << "| " << "11. Back" << setw(30) << " " << "| " << endl;
                cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                cout << setw(45) <<"  "<< "Input choice (0 - 11): ";
                int temp;
                cin >> temp;
                if (temp == 0)
                {
                    cout << setw(40) << " " << "Please enter day, month and year: ";
                    cin >> today.day >> today.month >> today.year;
                }
                else if (temp == 1)
                {
                    system("cls");
                    CreateYear(ListYear);
                    system("pause");
                }
                else if (temp == 2)
                {
                    system("cls");
                    addList(ListYear.pHead->data.Listclass, inputClass);
                    /*displayAll(ListYear.pHead->data.Listclass, outputClass);
                    system("pause");*/
                }
                else if (temp == 3)
                {
                    system("cls");
                    if (ListYear.pTail == NULL)
                    {
                        cerr << "No year to choose" << endl;
                        system("pause");
                    }
                    else
                    {
                        string classcheck;
                        cout << setw(40) << " " << "Type in class name: ";
                        cin.ignore(1, '\n');
                        getline(cin, classcheck);
                        LinkedList<Class> track = ListYear.pTail->data.Listclass;
                        while (track.pHead != NULL)
                        {
                            if (track.pHead->data.classname == classcheck)
                            {
                                addList(track.pHead->data.listOfStudents, &AddStudent);
                            }
                            track.pHead = track.pHead->pNext;
                        }
                    }
                }
                else if (temp == 4)
                {
                    system("cls");
                    string className;
                    cout << "Type in class's name: ";
                    getline(cin >> ws, className);
                    LinkedList<Student> s;
                    // ListYear.pHead->data.Listclass.pHead->data.listOfStudents

                    Node<Class>* current = ListYear.pHead->data.Listclass.pHead;
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
                        cout << "Cannot find this class, please try again!" << endl;
                        system("pause");
                        continue;
                    }
                    string filename = className + "Student.csv";
                    inputFile(s, inputStudentFile, filename);
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
                else if (temp == 5)
                {
                    if (ListYear.pTail == NULL)
                    {
                        cout << "Create a school year first" << endl;
                        system("pause");
                    }
                    else
                    {
                        semester(ListYear, reg);
                    }
                }
                else if (temp == 6)
                {
                    outputListClass(ListYear.pHead->data.Listclass);
                    system("pause");
                }
                else if (temp == 7)
                {
                    string classnow;
                    cout << "Please enter the class name (ex: 20CTT1...)" << endl;
                    cin >> classnow;
                    Node<Class> *current = ListYear.pHead->data.Listclass.pHead;
                    for (; current != nullptr; current = current->pNext)
                    {
                        if (current->data.classname == classnow)
                        {
                            outputAllStudent(current->data.listOfStudents);
                            system("pause");
                            break;
                        }
                    }
                    if (current == nullptr)
                    {
                        cout << "Can not find this class, please try again!"<<endl;
                        system("pause");
                    }
                }
                else if (temp == 8)
                {
                    if (ListYear.pTail == nullptr)
                    {
                        cout << "Create year first!" << endl;
                        system("pause");
                        continue;
                    }
                    if (ListYear.pTail->data.ListSemester.pTail == nullptr)
                    {
                        cout << "Create semester first!" << endl;
                        system("pause");
                        continue;
                    }
                    if (ListYear.pTail->data.ListSemester.pTail->data.ListCourse.pTail == nullptr)
                    {
                        cout << "There is no course in this semester!" << endl;
                        system("pause");
                        continue;
                    }
                    outputAllCourse(ListYear.pTail->data.ListSemester.pTail->data.ListCourse);
                    system("pause");
                }
                else if (temp == 9)
                {
                    outputStudentInCourse(ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
                    system("pause");
                }
                else if (temp == 10)
                {
                    EndofSemester(ListYear);
                }
                else if (temp == 11)
                {
                }
                else
                {
                    cout << "Invalid input, please try again!" << endl;
                    system("pause");
                }
            }
            else if (x == '3')
            {
                deleteListLogin(lhead);
                loginFile.close();
                login(ListYear);
            }
            else
            {
                deleteListLogin(lhead);
                loginFile.close();
                cout << "Invalid input, please try again!" << endl;
                system("pause");
                login(ListYear);
            }
        }
    }
    else
    {
        loginFile.close();
        deleteListLogin(lhead);
        cout << setw(40) << " " << "ID OR PASSWORD INCORECT, PLEASE TRY AGAIN" << endl;
        cout << setw(40) << " ";
        system("pause");
        login(ListYear);
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
/*
2
2
1
1
2
1
2021
.
2
2
1
21CTT1
1
20APCS2
2
2
4
21CTT1

2
5
1
1
15 3 2022
15 10 2022

2
15 3 2022
14 10 2022

3
1
CS162
introduce to CS1
Dinh Ba Tien
4
MON
S1
TUE
S2
1
CM101
comunication M
Duong Nguyen Vu
4
MON
S3
TUE
S4
2

7
3
1
2
21125087
0
2
1

*/
