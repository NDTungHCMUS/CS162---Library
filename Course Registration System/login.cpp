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
        cout << setw(45) << " " << "| " << "1. Student" << setw(17) << " " <<  "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "2. Staff member" << setw(12) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "3. Load data" << setw(15) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "4. Save data" << setw(15) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;
        cout << setw(45) << " " << "| " << "5. Exit" << setw(20) << " " << "|" << endl;
        cout << setw(45) << " " << "------------------------------" << endl;

        cout << setw(45) << " " << "Input your choice (1 - 5): ";
        int x;
        while (cin >> x && (x != 1 && x != 2 && x != 3 && x != 4 && x!= 5))
        {
            cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
            cout << setw(45) << " ";
            system("pause");
            cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
            cout << setw(45) << " " << "Input your choice (1 - 3): ";
        }
        if (x == 1 || x == 2)
        {
            check = true;
            if (x == 1)
            {
                system("cls");
                char t;

                cout << setw(53) << " " << "** Student  **" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Register" << setw(16) << " " << "|" << endl;
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
            else if (x == 2)
            {
                system("cls");

                cout << setw(50) << " " << "** Academic Staff **" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Register" << setw(16) << " " <<  "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. Login" << setw(19) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                cout << setw(45) << " " << "| " << "3. Back" << setw(20) << " " << "|" << endl;
                cout << setw(45) << " " << "------------------------------" << endl;
                int t;
                cout << setw(45) << " " << "Input your choice (1 - 3): ";
                while (cin >> t && (t != 1 && t != 2 && t != 3))
                {
                    cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
                    cout << setw(45) << " ";
                    system("pause");
                    cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
                    cout << setw(45) << " " << "Input your choice (1 - 3): ";
                }
                if (t == 1)
                {
                    RegisterStaff(ListYear);
                }
                else if (t == 2)
                {
                    loginStaff(lhead, position,ListYear );
                }
                else if (t == 3) login(ListYear);
                else
                {
                    cout << setw(40) << " " << "Invalid input, please try again!" << endl;
                    cout << setw(40) << " ";
                    system("pause");
                    login(ListYear);
                }
            }
        }
        else if (x == 3)
        {
            ifstream fin;
            fin.open("course.txt");
            inAll(ListYear,fin);
            fin.close();
            cout << setw(45) << " " << "Loaded successfully!" << endl;
            cout << setw(45) << " ";
            system("pause");
        }
        else if (x == 4)
        {
            ofstream fout;
            fout.open("course.txt");
            outAll(ListYear,fout);
            fout.close();
            cout << setw(45) << " " << "Data saved!" << endl;
            cout << setw(45) << " ";
            system("pause");
        }
        else if (x == 5)
        {
            check = true;
            deleteListLogin(lhead);
            deleteAll(ListYear);
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
            int x;
            cout << setw(45) << " " << "Input your choice (1 - 3): ";
            while (cin >> x && (x != 1 && x != 2 && x != 3))
            {
                cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
                cout << setw(45) << " ";
                system("pause");
                cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
                cout << setw(45) << " " << "Input your choice (1 - 3): ";
            }
            if (x == 1)
            {
                system("cls");
                cout << setw(47) << " " << "*** User account ***\n";
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Change password" << setw(2) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. View your profile" << setw(0) << "" << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "3. Back" << setw(13) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "Your choice: ";
                int tmp1;
                cin >> tmp1;
                string current = "";
                if (tmp1 == 3) continue;
                else if (tmp1 == 1)
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
                            cout << setw(40) << " " << "Password Incorrect, Please try again!\n";
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
                else if (tmp1 == 2)
                {
                    system("cls");
                    cout << setw(47) << " " << "*** User profile ***\n";
                    cout << setw(47) << ' ' << "------------";
                    for (int i = 0; i <= ID.size(); i++)
                        cout << '-';
                    cout << endl;
                    cout << setw(47) << " " << "| " << "Your ID: " << ID <<" |" << endl;
                    cout << setw(47) << ' ' << "------------";
                    for (int i = 0; i <= ID.size(); i++)
                        cout << '-';
                    cout << endl;
                    cout << setw(43) << " ";
                    system("pause");
                }
                else
                {
                    cout << setw(45) << " " << "Invalid input, please try again !" << endl;
                    cout << setw(45) << " ";
                    system("pause");
                    continue;
                }
            }
            else if (x == 2)
            {
                student(id, ListYear, today, reg);
            }
            else if (x == 3)
            {
                loginFile.close();
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
            int x;
            cout << setw(45) << " " << "Input your choice (1 - 3): ";
            while (cin >> x && (x != 1 && x != 2 && x != 3))
            {
                cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
                cout << setw(45) << " ";
                system("pause");
                cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
                cout << setw(45) << " " << "Input your choice (1 - 3): ";
            }
            if (x == 1)
            {
                system("cls");
                cout << setw(47) << " " << "*** User account ***\n";
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "1. Change password" << setw(2) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "2. View your profile" << setw(0) << "" << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "| " << "3. Back" << setw(13) << " " << " |" << endl;
                cout << setw(45) << ' ' << "------------------------" << endl;
                cout << setw(45) << " " << "Your choice: ";
                char tmp2;
                cin >> tmp2;
                if (tmp2 == '3') continue;
                string current = "";
                if (tmp2 == '1')
                {
                    cout << current << endl;
                    cout << position->pas << endl;
                    cout << position->next->pas << endl;
                    while (current != position->next->pas)
                    {
                        system("cls");
                        cout << setw(45) << " " << "*** Change Password ***\n";
                        cout << setw(40) << " " << "Please enter current password :";
                        cin >> current;
                        if (current != position->next->pas)
                        {

                            cout << endl;
                            cout << setw(40) << " " << "Password Incorrect, Please try again!\n";
                            cout << setw(40) << " ";
                            system("pause");
                            continue;
                        }
                        cout << endl;
                        cout << setw(40) << " " << "Please enter new password : ";
                        cin >> current;
                        position->next->pas = current;
                        loginFile.close();
                        saveStaff(lhead);
                        cout << setw(40) << " " << "Change Password successful, please login again!\n";
                        cout << setw(40) << " ";
                        system("pause");
                        deleteListLogin(lhead);
                        login(ListYear);
                    }
                }
                else if (tmp2 == '2')
                {
                    system("cls");
                    cout << setw(49) << " " << "*** User profile ***\n";
                    cout << setw(47) << ' ' << "------------";
                    for (int i = 0; i <= ID.size(); i++)
                        cout << '-';
                    cout << endl;
                    cout << setw(47) << " " << "| " << "Your ID: " << ID <<" |" << endl;
                    cout << setw(47) << ' ' << "------------";
                    for (int i = 0; i <= ID.size(); i++)
                        cout << '-';
                    cout << endl;
                    cout << setw(43) << " ";
                    system("pause");
                }
            }
            else if (x == 2)
            {
                while (1) {
                    system("cls");
                    cout << setw(51) << ' ' << "***** Staff's Activities *****" << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "0. Change Date" << setw(24) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "1. Create new school year" << setw(13) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "2. Create new class" << setw(19) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "3. Add student into class" << setw(13) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "4. Import student from CSV file" << setw(7) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "5. Semester" << setw(27) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "6. View List of class" << setw(17) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "7. View a list of students in a class" << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "8. View a list of all courses" << setw(9) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "9. View a list of students in a course" << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "10. End of semester functions" << setw(9) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << " " << "| " << "11. Back" << setw(30) << " " << "| " << endl;
                    cout << setw(45) << ' ' << "-----------------------------------------" << endl;
                    cout << setw(45) << "  " << "Input choice (0 - 11): ";  
                    int temp;
                    while (cin >> temp && (temp < 0 || temp > 11))
                    {
                        cout << setw(45) << " " << "Invalid choice, please try again!" << endl;
                        cout << setw(45) << " ";
                        system("pause");
                        cout << "\033[A\33[2K\r" << "\033[A\33[2K\r" << "\033[A\33[2K\r";
                        cout << setw(45) << " " << "Input your choice (1 - 3): ";
                    }
                    if (temp == 0)
                    {
                        system("cls");
                        cout << setw(40) << " " << "Please enter day, month and year: ";
                        cin >> today.day >> today.month >> today.year;
                        cout << setw(40) << " " << "Date changed successfully. " << endl;
                        cout << setw(40) << " ";
                        system("pause");
                    }
                    else if (temp == 1)
                    {
                        system("cls");
                        CreateYear(ListYear);
                        cout << endl << setw(40) << " ";
                        system("pause");
                    }
                    else if (temp == 2)
                    {
                        if (ListYear.pTail == nullptr)
                        {
                            cout << setw(45) << ' ' << "Create year first! ";
                            cout << endl << setw(45) << ' ';
                            system("pause");
                        }
                        else
                        {
                            bool checkDupClass = false;
                            system("cls");
                            Class res;
                            cin.ignore(1000, '\n');
                            cout << setw(40) << " " << "Input classcode (e.g: 21CTT1): ";
                            getline(cin, res.classname, '\n');
                            for (Node<Class>* cur = ListYear.pTail->data.Listclass.pHead; cur != nullptr; cur = cur->pNext)
                            {
                                if (cur->data.classname == res.classname)
                                {
                                    checkDupClass = true;
                                    cout << setw(40) << " " << "Class " << res.classname << " already exist!";
                                    cout << endl << setw(40) << " ";
                                    system("pause");
                                    break;
                                }
                            }
                            if (checkDupClass == false)
                            {
                                cout << setw(40) << " " << "Added Successfully.\n";
                                add(ListYear.pTail->data.Listclass, res);
                                cout << setw(40) << " ";
                                system("pause");
                            }
                        }
                    }
                    else if (temp == 3)
                    {

                        if (ListYear.pTail == NULL)
                        {
                            cerr << setw(45) << " " << "No year to choose" << endl;
                            cout << setw(45) << " ";
                            system("pause");
                            continue;
                        }
                        if (ListYear.pTail->data.Listclass.pTail == nullptr)
                        {
                            cout << setw(45) << " " << "No class here. " << endl;
                            cout << setw(45) << " ";
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            string classcheck;
                            cout << setw(45) << " " << "Type in class name: ";
                            cin.ignore(1, '\n');
                            getline(cin, classcheck);
                            bool flag = false;
                            LinkedList<Class> track = ListYear.pTail->data.Listclass;
                            while (track.pHead != NULL)
                            {
                                if (track.pHead->data.classname == classcheck)
                                {
                                    addList(track.pHead->data.listOfStudents, &AddStudent);
                                    flag = true;
                                }
                                track.pHead = track.pHead->pNext;
                            }
                            if (flag == false)
                            {
                                cout << setw(45) << " " << "Invalid class" << endl;
                                cout << setw(45) << " ";
                                system("pause");
                            }
                        }
                    }
                    else if (temp == 4)
                    {
                        if (ListYear.pTail == NULL)
                        {
                            cout << setw(45) << ' ' << "Create a school year first" << endl;
                            cout << setw(45) << ' ';
                            system("pause");
                            continue;
                        }
                        if (ListYear.pTail->data.Listclass.pTail == nullptr)
                        {
                            cout << setw(45) << ' ' << "No class here. " << endl;
                            cout << setw(45) << ' ';
                            system("pause");
                            continue;
                        }
                        else
                        {
                            system("cls");
                            string className;
                            cout << setw(45) << " " << "Type in class's name: ";
                            getline(cin >> ws, className);
                            LinkedList<Student> s;

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
                                cout << setw(45) << " " << "Cannot find this class, please try again!" << endl;
                                cout << setw(45) << " ";
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
                            if (s.pHead == nullptr)
                            {
                                cout << setw(45) << " ";
                                system("pause");
                                continue;
                            }
                            cout << setw(45) << " " << "Imported successfully." << endl;
                            cout << setw(45) << " ";
                            system("pause");
                        }
                    }
                    else if (temp == 5)
                    {
                        if (ListYear.pTail == NULL)
                        {
                            cout << setw(45) << " " << "Create a school year first" << endl;
                            cout << setw(45) << " ";
                            system("pause");
                        }
                        else
                        {
                            semester(ListYear, reg);
                        }
                    }
                    else if (temp == 6)
                    {
                        if (ListYear.pTail == NULL)
                        {
                            cout << setw(45) << ' ' << "Create a school year first" << endl;
                            cout << setw(45) << ' ';
                            system("pause");
                        }
                        else
                        {
                            int yearcheck;
                            cout << setw(45) << " " << "Please enter the school year (ex: 2020...): ";
                            cin >> yearcheck;
                            Node<Year>* currentYear = ListYear.pHead;
                            for (; currentYear != nullptr; currentYear = currentYear->pNext)
                            {
                                if (currentYear->data.yearStart == yearcheck)
                                {
                                    break;
                                }
                            }
                            if (currentYear == nullptr) {
                                cout << setw(45) << " " << "Year not found" << endl;
                                cout << setw(45) << " "; system("pause"); continue;
                            }
                            outputListClass(currentYear->data.Listclass);
                            system("pause");
                        }
                    }
                    else if (temp == 7)
                    {
                        if (ListYear.pTail == NULL)
                        {
                            cout << setw(45) << ' ' << "Create a school year first" << endl;
                            cout << setw(45) << ' ';
                            system("pause");
                            continue;
                        }
                        if (ListYear.pTail->data.Listclass.pTail == nullptr)
                        {
                            cout << setw(45) << ' ' << "No class here. " << endl;
                            cout << setw(45) << ' ';
                            system("pause");
                            continue;
                        }
                        else
                        {
                            system("cls");
                            int yearcheck;
                            cout << setw(30) << " " << "Please enter the school year (ex: 2020...): ";
                            cin >> yearcheck;
                            Node<Year>* currentYear = ListYear.pHead;
                            for (; currentYear != nullptr; currentYear = currentYear->pNext)
                            {
                                if (currentYear->data.yearStart == yearcheck)
                                {
                                    break;
                                }
                            }
                            if (currentYear == nullptr) {
                                cout << setw(30) << " " << "Year not found" << endl;
                                cout << setw(30) << " "; system("pause"); continue;
                            }
                            string classnow;
                            cout << setw(30) << " " << "Please enter the class name (ex: 20CTT1...): ";
                            cin >> classnow;
                            Node<Class>* current = currentYear->data.Listclass.pHead;
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
                                cout << setw(30) << ' ' << "Can not find this class, please try again!" << endl;
                                cout << setw(30) << ' ';
                                system("pause");
                            }
                        }
                    }
                    else if (temp == 8)
                    {
                        system("cls");
                        int yearcheck;
                        cout << setw(30) << " " << "Please enter the school year (ex: 2020...): ";
                        cin >> yearcheck;
                        Node<Year>* currentYear = ListYear.pHead;
                        for (; currentYear != nullptr; currentYear = currentYear->pNext)
                        {
                            if (currentYear->data.yearStart == yearcheck)
                            {
                                break;
                            }
                        }
                        if (currentYear == nullptr) {
                            cout << setw(30) << " " << "Year not found" << endl;
                            cout << setw(30) << " "; system("pause"); continue;
                        }
                        int semcheck;
                        cout << setw(30) << " " << "Please enter the semester (1, 2 or 3): ";
                        while (cin >> semcheck &&  (semcheck < 1 || semcheck > 3)) {
                            cout << setw(30) << " " << "Invalid, try again: ";
                        }
                        Node<Semester>* currentSem  = currentYear->data.ListSemester.pHead;
                        int i = 1;
                        while (i < semcheck && currentSem != nullptr) {
                            currentSem = currentSem->pNext;
                            ++i;
                        }
                        system("cls");
                        if (currentSem == nullptr) {
                            cout << setw(30) << " " << "No course to display." << endl;
                            cout << setw(30) << " "; system("pause");
                        }
                        else {
                            outputAllCourse(currentSem->data.ListCourse);
                            cout << endl;
                            system("pause");
                        }
                    }
                    else if (temp == 9)
                    {   
                        if (ListYear.pTail == nullptr)
                        {
                            cout << setw(45) << ' ' << "Create year first!" << endl;
                            cout << setw(45) << " ";
                            system("pause");
                            continue;
                        }
                        if (ListYear.pTail->data.ListSemester.pTail == nullptr)
                        {
                            cout << setw(45) << ' ' << "Create semester first!" << endl;
                            cout << setw(45) << " ";
                            system("pause");
                            continue;
                        }
                        system("cls");
                        int yearcheck;
                        cout << setw(30) << " " << "Please enter the school year (ex: 2020...): ";
                        cin >> yearcheck;
                        Node<Year>* currentYear = ListYear.pHead;
                        for (; currentYear != nullptr; currentYear = currentYear->pNext)
                        {
                            if (currentYear->data.yearStart == yearcheck)
                            {
                                break;
                            }
                        }
                        if (currentYear == nullptr) {
                            cout << setw(30) << " " << "Year not found" << endl;
                            cout << setw(30) << " "; system("pause"); continue;
                        }
                        int semcheck;
                        cout << setw(30) << " " << "Please enter the semester (1, 2 or 3): ";
                        while (cin >> semcheck && (semcheck < 1 || semcheck > 3)) {
                            cout << setw(30) << " " << "Invalid, try again: ";
                        }
                        Node<Semester>* currentSem = currentYear->data.ListSemester.pHead;
                        int i = 1;
                        while (i < semcheck && currentSem != nullptr) {
                            currentSem = currentSem->pNext;
                            ++i;
                        }
                        system("cls");
                        if (currentSem == nullptr) {
                            cout << setw(30) << ' ' << "There is no course in this semester!" << endl;
                            cout << setw(30) << " "; system("pause");
                        }
                        else {
                            system("cls");
                            outputStudentInCourse(ListYear.pTail->data.ListSemester.pTail->data.ListCourse);
                            system("pause");
                        }
                    }
                    else if (temp == 10)
                    {
                        EndofSemester(ListYear);
                    }
                    else if (temp == 11)
                    {
                        break;
                    }
                    else
                    {
                        cout << setw(45) << " " << "Invalid input, please try again!" << endl;
                        system("pause");
                    }
                }
            }
            else if (x == 3)
            {
                deleteListLogin(lhead);
                loginFile.close();
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
void deleteAll(LinkedList<Year> &ListYear)
{
    Node<Year> *NodeYear = ListYear.pHead;
    while(NodeYear != nullptr)
    {
        Node<Semester> *NodeSemester = NodeYear->data.ListSemester.pHead;
        while(NodeSemester != nullptr)
        {
            Node<Course>* NodeCourse = NodeSemester->data.ListCourse.pHead;
            while(NodeCourse != nullptr)
            {

                Node<Student> *NodeEnrollStudent = NodeCourse->data.EnrollStudentList.pHead;
                while(NodeEnrollStudent != nullptr)
                {

                    Node<CourseData> *NodeListCourseData = NodeEnrollStudent->data.ListCourseData.pHead;
                    while(NodeListCourseData != nullptr)
                    {
                        NodeEnrollStudent->data.ListCourseData.pHead = NodeEnrollStudent->data.ListCourseData.pHead->pNext;
                        delete NodeListCourseData;
                        NodeListCourseData = NodeEnrollStudent->data.ListCourseData.pHead;
                    }

                    NodeCourse->data.EnrollStudentList.pHead = NodeCourse->data.EnrollStudentList.pHead->pNext;
                    delete NodeEnrollStudent;
                    NodeEnrollStudent = NodeCourse->data.EnrollStudentList.pHead;
                }
                Node<Score> *NodeScore = NodeCourse->data.scoreBoard.pHead;
                while(NodeScore != nullptr)
                {
                    NodeCourse->data.scoreBoard.pHead = NodeCourse->data.scoreBoard.pHead->pNext;
                    delete NodeScore;
                    NodeScore = NodeCourse->data.scoreBoard.pHead;
                }
                NodeSemester->data.ListCourse.pHead = NodeSemester->data.ListCourse.pHead->pNext;
                delete NodeCourse;
                NodeCourse = NodeSemester->data.ListCourse.pHead;
            }

            NodeYear->data.ListSemester.pHead = NodeYear->data.ListSemester.pHead->pNext;
            delete NodeSemester;
            NodeSemester = NodeYear->data.ListSemester.pHead;
        }

        Node<Class> *NodeClass = NodeYear->data.Listclass.pHead;
        while(NodeClass != nullptr)
        {

            Node<Student>* NodeStudent = NodeClass->data.listOfStudents.pHead;
            while(NodeStudent != nullptr)
            {
                Node<CourseData> *NodeCourseData = NodeStudent->data.ListCourseData.pHead;
                while(NodeCourseData != nullptr)
                {
                    NodeStudent->data.ListCourseData.pHead = NodeStudent->data.ListCourseData.pHead->pNext;
                    delete NodeCourseData;
                    NodeCourseData = NodeStudent->data.ListCourseData.pHead;
                }

                NodeClass->data.listOfStudents.pHead = NodeClass->data.listOfStudents.pHead->pNext;
                delete NodeStudent;
                NodeStudent = NodeClass->data.listOfStudents.pHead;
            }

            NodeYear->data.Listclass.pHead = NodeYear->data.Listclass.pHead->pNext;
            delete NodeClass;
            NodeClass = NodeYear->data.Listclass.pHead;
        }

        ListYear.pHead = ListYear.pHead->pNext;
        delete NodeYear;
        NodeYear = ListYear.pHead;
    }
}
void outAll(LinkedList<Year> &ListYear, ofstream &fout)
{
   // cout << "All data are stored !" << endl;
    int lengthYear = length(ListYear);
  //  cout << lengthYear << endl;

    fout << lengthYear << endl;
    for (Node<Year> *NodeYear = ListYear.pHead; NodeYear != nullptr; NodeYear = NodeYear->pNext)
    {
        fout << NodeYear->data.yearStart << endl;

        fout << length(NodeYear->data.ListSemester) << endl;
        for (Node<Semester> *NodeSemester = NodeYear->data.ListSemester.pHead; NodeSemester != nullptr; NodeSemester = NodeSemester->pNext)
        {
            fout << NodeSemester->data.SemesterNumb << endl;
            fout << NodeSemester->data.schoolyear << endl;
            fout << NodeSemester->data.startDate.day <<' '<<NodeSemester->data.startDate.month <<' '<<NodeSemester->data.startDate.year<< endl;
            fout << NodeSemester->data.endDate.day <<' '<<NodeSemester->data.endDate.month <<' '<<NodeSemester->data.endDate.year<< endl;
            fout << length(NodeSemester->data.ListCourse) << endl;
            for (Node<Course>* NodeCourse = NodeSemester->data.ListCourse.pHead; NodeCourse != nullptr; NodeCourse = NodeCourse->pNext)
            {
                fout << NodeCourse->data.ID << endl; // string
                fout << NodeCourse->data.CourseName << endl; // string
                fout << NodeCourse->data.TeacherName << endl; // string
                fout << NodeCourse->data.NumbOfCredits << endl;
                fout << NodeCourse->data.MaxStudent << endl;
                fout << NodeCourse->data.NumbOfStudent << endl;
                fout << NodeCourse->data.s1.day << endl; // string
                fout << NodeCourse->data.s1.period << endl; // string
                fout << NodeCourse->data.s2.day << endl; // string
                fout << NodeCourse->data.s2.period << endl; // string

                fout << length(NodeCourse->data.EnrollStudentList) << endl;
                for (Node<Student> *NodeEnrollStudent = NodeCourse->data.EnrollStudentList.pHead; NodeEnrollStudent != nullptr; NodeEnrollStudent = NodeEnrollStudent->pNext)
                {
                    fout << NodeEnrollStudent->data.No << endl;
                    fout << NodeEnrollStudent->data.StudentID << endl;
                    fout << NodeEnrollStudent->data.FirstName << endl; // string
                    fout << NodeEnrollStudent->data.LastName << endl; // string
                    fout << NodeEnrollStudent->data.Gender << endl;
                    fout << NodeEnrollStudent->data.dob.day <<' ' <<NodeEnrollStudent->data.dob.month <<' ' << NodeEnrollStudent->data.dob.year  << endl;
                    fout << NodeEnrollStudent->data.SocialID << endl;
                    fout << NodeEnrollStudent->data.numCourse << endl;
                }

                fout << length(NodeCourse->data.scoreBoard) << endl;
                for(Node<Score> *NodeScore = NodeCourse->data.scoreBoard.pHead; NodeScore != nullptr; NodeScore = NodeScore->pNext)
                {
                    fout << NodeScore->data.no << endl;
                    fout << NodeScore->data.ID << endl;
                    fout << NodeScore->data.fullname << endl; // string
                    fout << NodeScore->data.totalMark << endl;
                    fout << NodeScore->data.finalMark << endl;
                    fout << NodeScore->data.midtermMark << endl;
                    fout << NodeScore->data.otherMark << endl;
                }
            }
        }

        fout << length(NodeYear->data.Listclass) << endl;
        for(Node<Class> *NodeClass = NodeYear->data.Listclass.pHead; NodeClass != nullptr; NodeClass = NodeClass->pNext)
        {
            fout << NodeClass->data.classname << endl;
            fout << length(NodeClass->data.listOfStudents) << endl;
            for (Node<Student>* NodeStudent = NodeClass->data.listOfStudents.pHead; NodeStudent != nullptr; NodeStudent = NodeStudent->pNext)
            {
                fout << NodeStudent->data.No << endl;
                fout << NodeStudent->data.StudentID << endl;
                fout << NodeStudent->data.FirstName << endl; // string
                fout << NodeStudent->data.LastName << endl; // string
                fout << NodeStudent->data.Gender << endl;
                fout << NodeStudent->data.dob.day <<' ' <<NodeStudent->data.dob.month <<' ' << NodeStudent->data.dob.year  << endl;
                fout << NodeStudent->data.SocialID << endl;
                fout << NodeStudent->data.numCourse << endl;
                fout << length(NodeStudent->data.ListCourseData) << endl;
                for (Node<CourseData> *NodeCourseData = NodeStudent->data.ListCourseData.pHead; NodeCourseData != nullptr; NodeCourseData = NodeCourseData->pNext)
                {
                    fout << NodeCourseData->data.ID << endl; // string
                    fout << NodeCourseData->data.CourseName << endl; // string
                    fout << NodeCourseData->data.TeacherName << endl; // string
                    fout << NodeCourseData->data.s1.day << endl; // string
                    fout << NodeCourseData->data.s1.period << endl; // string
                    fout << NodeCourseData->data.s2.day << endl; // string
                    fout << NodeCourseData->data.s2.period << endl; // string
                }
            }

        }
    }
}
void inAll(LinkedList<Year> &ListYear, ifstream &fin)
{
    int lengthYear;
    fin >> lengthYear;
    for (int i = 0; i < lengthYear; i++)
    {
        Year NodeYear;
        fin >> NodeYear.yearStart;
        int lengthSemester;
        fin >> lengthSemester;
        LinkedList<Semester> ListSemester;
        for (int j = 0; j < lengthSemester; j++)
        {
            Semester NodeSemester;
            fin >> NodeSemester.SemesterNumb;
            fin >> NodeSemester.schoolyear;
            fin >> NodeSemester.startDate.day >> NodeSemester.startDate.month >> NodeSemester.startDate.year ;
            fin >> NodeSemester.endDate.day >> NodeSemester.endDate.month >> NodeSemester.endDate.year ;
            int lengthCourse;
            fin >> lengthCourse;
            LinkedList<Course> ListCourse;
            Course NodeCourse;
            for (int u = 0; u < lengthCourse; u++)
            {
                getline(fin >> ws, NodeCourse.ID);
                getline(fin >> ws, NodeCourse.CourseName);
                getline(fin >> ws, NodeCourse.TeacherName);
                fin >> NodeCourse.NumbOfCredits;
                fin >> NodeCourse.MaxStudent;
                fin >> NodeCourse.NumbOfStudent;
                getline(fin >> ws, NodeCourse.s1.day);
                getline(fin >> ws, NodeCourse.s1.period);
                getline(fin >> ws, NodeCourse.s2.day);
                getline(fin >> ws, NodeCourse.s2.period);
                int lengthEnrollStudentList;
                fin >> lengthEnrollStudentList;
                LinkedList<Student> EnrollStudentList;
                Student NodeEnrollStudent;
                for (int v = 0; v < lengthEnrollStudentList; v++)
                {
                    fin >> NodeEnrollStudent.No;
                    fin >> NodeEnrollStudent.StudentID;
                    getline(fin >> ws,NodeEnrollStudent.FirstName);
                    getline(fin >> ws,NodeEnrollStudent.LastName);
                    fin >> NodeEnrollStudent.Gender;
                    fin >> NodeEnrollStudent.dob.day >> NodeEnrollStudent.dob.month >> NodeEnrollStudent.dob.year;
                    fin >> NodeEnrollStudent.SocialID;
                    fin >> NodeEnrollStudent.numCourse;
                    add(EnrollStudentList,NodeEnrollStudent);
                }
                NodeCourse.EnrollStudentList = EnrollStudentList;
                int lengthScoreboard;
                fin >> lengthScoreboard;
                LinkedList<Score> ListScore;
                Score NodeScore;

                for (int k = 0; k < lengthScoreboard; k++)
                {
                    fin >> NodeScore.no;
                    fin >> NodeScore.ID;
                    getline(fin >> ws, NodeScore.fullname);
                    fin >> NodeScore.totalMark;
                    fin >> NodeScore.finalMark;
                    fin >> NodeScore.midtermMark;
                    fin >> NodeScore.otherMark;
                    add(ListScore,NodeScore);
                }
                NodeCourse.scoreBoard = ListScore;
                add(ListCourse, NodeCourse);
            }
            NodeSemester.ListCourse = ListCourse;
            add(ListSemester, NodeSemester);
        }
        NodeYear.ListSemester = ListSemester;

        int lengthClass;
        fin >> lengthClass;
        Class NodeClass;
        LinkedList<Class> Listclass;
        for (int l = 0;  l < lengthClass; l++ )
        {
            fin >> NodeClass.classname;

            int lengthOfStudent;
            fin >> lengthOfStudent;
            Student NodeStudent;
            LinkedList<Student> listOfStudents;
            for (int q = 0; q < lengthOfStudent; q++)
            {
                fin >>  NodeStudent.No;
                fin >>  NodeStudent.StudentID;
                getline(fin >> ws, NodeStudent.FirstName);
                getline(fin >> ws, NodeStudent.LastName);
                fin >>  NodeStudent.Gender;
                fin >>  NodeStudent.dob.day >> NodeStudent.dob.month >> NodeStudent.dob.year ;
                fin >>  NodeStudent.SocialID;
                fin >> NodeStudent.numCourse;
                int lengListCourse;
                fin >> lengListCourse;
                LinkedList<CourseData> ListCourseData;
                CourseData NodeCourseData;
                for (int w = 0; w < lengListCourse; w++)
                {
                    getline(fin >> ws, NodeCourseData.ID);
                    getline(fin >> ws, NodeCourseData.CourseName);
                    getline(fin >> ws, NodeCourseData.TeacherName);
                    getline(fin >> ws, NodeCourseData.s1.day);
                    getline(fin >> ws, NodeCourseData.s1.period);
                    getline(fin >> ws, NodeCourseData.s2.day);
                    getline(fin >> ws, NodeCourseData.s2.period);
                    add(ListCourseData,NodeCourseData);
                }

                NodeStudent.ListCourseData = ListCourseData;
                add(listOfStudents,NodeStudent);
            }
            NodeClass.listOfStudents = listOfStudents;
            add(Listclass,NodeClass);
        }


        NodeYear.Listclass = Listclass;
        add(ListYear,NodeYear);
    }
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

1
CS163
data structure
Dinh Ba Tien
4
MON
S1
TUE
S2
1
MATH1
linear algeobra
Nguyen Huu Anh
4
MON
S3
TUE
S4
1
MATH2
caculus2
Nguyen Huu Anh
4
THU
S3
SAT
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
