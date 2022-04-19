#include "year.h"
#include<sstream>
using namespace std;

void CreateYear(LinkedList<Year>& yearList)
{
    Node<Year>* current = yearList.pHead;
    int temp;
    cout << setw(40) << " " << "Type in Year Start: ";
    cin >> temp;
    if (yearList.pHead == nullptr)
    {
        yearList.pHead = new Node<Year>;
        yearList.pHead->data.yearStart = temp;
        yearList.pTail = yearList.pHead;
    }
    else
    {
        yearList.pTail->pNext = new Node<Year>;
        yearList.pTail = yearList.pTail->pNext;
        yearList.pTail->data.yearStart = temp;
    }
    cout << setw(40) << " " << "Added successfully. ";
}

Semester inputSemester(Year y1)
{
    Semester t;
    t.schoolyear = y1.yearStart;
    cout << setw(40) << " " << "Input semester: ";
    cin >> t.SemesterNumb;
    cout << setw(40) << " " << "Input start date: ";
    cin >> t.startDate.day >> t.startDate.month >> t.startDate.year;
    cout << setw(40) << " " << "Input end date: ";
    cin >> t.endDate.day >> t.endDate.month >> t.endDate.year;
    return t;
}

void inputStudentCSV(LinkedList<Year> &ListYear, string &className)
{
    LinkedList<Student> s;
    /* bool check = false;
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
         return;
     }*/
    Node<Student> dummy;
    Node<Student>* temp = &dummy;
    ifstream fin;
    fin.open("Student.csv");
    string line;
    while (getline(fin, line))
    {
        temp->pNext = new Node<Student>;
        temp = temp->pNext;
        string sNo;
        string sID;
        string sGender;
        string sDay, sMonth, sYear;
        string sSocial;
        string dob;
        stringstream inputstream;
        inputstream.str(line);
        inputstream >> temp->data.No;
        inputstream >> temp->data.StudentID;
        cout << temp->data.No << ' ' << temp->data.StudentID<<endl;
        system("pause");
        getline(inputstream, temp->data.FirstName, ',');
        getline(inputstream, temp->data.LastName, ',');
        inputstream >> temp->data.Gender;
        getline(inputstream, dob, ',');
        stringstream dobstream;
        dobstream.str(dob);
        dobstream >> temp->data.dob.day;
        dobstream >> temp->data.dob.month;
        dobstream >> temp->data.dob.year;
        inputstream >> temp->data.SocialID;
    }
    s.pHead = dummy.pNext;
    s.pTail = temp;
    outputAllStudent(s);
    //cout << endl;
    /*	current = ListYear.pHead->data.Listclass.pHead;
    	while (current != nullptr)
        {
            if (current->data.classname == className)
                {
                    current->data.listOfStudents = s;
                    break;
                }
                current = current->pNext;
        }
       // outputAllStudent()
    */
}
Year inputYear()
{
    Year res{ 0, nullptr };
    cout << "input year start: ";
    cin >> res.yearStart;
    return res;
}
void displayYear(LinkedList<Year>yearList)
{
    Node<Year>* temp = yearList.pHead;
    if (yearList.pHead == nullptr) return;
    cout << "All years shown below: " << endl;
    while (temp)
    {
        cout << temp->data.yearStart << endl;
        temp = temp->pNext;
    }
}
void viewListCoursethisSemester(LinkedList<Year> listYear)
{
    displayYear(listYear);
    cout << "Input Year: ";
    int year;
    cin >> year;
    Node<Year>* cur = listYear.pHead;
    while (cur)
    {
        if (cur->data.yearStart == year) break;
        cur = cur->pNext;
    }
    cout << setw(20) << " " << "Input semester (from 1 to 3) in " << year << " you want to view list courses: ";
    int n;
    cin >> n;
    while (n <= 0 || n >= 4)
    {
        cout << "Please choose semester again: ";
        cin >> n;
    }
    if (n >= 1 && n <= 3)
    {
        cout << "All courses in semester " << n << " of year " << cur->data.yearStart << " shown as below: " << endl;
        Node <Semester>* temp = cur->data.ListSemester.pHead;
        int count = n - 1;
        int count2 = 0;
        while (count2 < count)
        {
            temp = temp->pNext;
            count2++;
        }
        outputAllCourse(temp->data.ListCourse);
    }
}

void outputScoreBoardOfClassMenu(LinkedList<Course>& ListCourse)
{
    cout << "\n";

    cout << "No"
         << "\t" << "StudentID"
         << "\t" << "Student Name\t";
    Node <Course>* NodeCourse = ListCourse.pHead;
    for (; NodeCourse != nullptr; NodeCourse = NodeCourse->pNext)
    {
        cout << "\t" << NodeCourse->data.ID;
    }
    cout << "\t" << "Semester GPA";
    cout << "\t" << "Overall GPA\n";
    cout << "\n";
}

void viewScoreBoardOfClass(LinkedList <Class>& ListClass, LinkedList<Course>& ListCourse)
{
    string clName;
    cout << "\nPlease enter the class's name:";
    getline(cin >> ws, clName);
    Node <Class>* NodeClass = ListClass.pHead;
    for (; NodeClass != nullptr; NodeClass = NodeClass->pNext)
    {
        if (NodeClass->data.classname == clName) break;
    }
    if (NodeClass == nullptr)
    {
        cout << "\nThere is no class with this name, please try again!";
        return;
    }

    Node<Student>* NodeStudent = NodeClass->data.listOfStudents.pHead;
    cout << "---------------------------------- Score Board of class " << clName << " ----------------------------------------\n";
    outputScoreBoardOfClassMenu(ListCourse);
    int noOfStudent = 0;
    for (; NodeStudent != nullptr; NodeStudent = NodeStudent->pNext)
    {
        cout << ++noOfStudent << "\t" << NodeStudent->data.StudentID << "\t" << NodeStudent->data.FirstName << ' ' << NodeStudent->data.LastName;
        int countCourse = 0;
        float sumGPA = 0;
        Node<Course>* NodeCourse = ListCourse.pHead;
        for (; NodeCourse != nullptr; NodeCourse = NodeCourse->pNext)
        {

            Node<Score>* NodeSore = NodeCourse->data.scoreBoard.pHead;
            for (; NodeSore != nullptr; NodeSore = NodeSore->pNext)
            {
                if (NodeSore->data.ID == NodeStudent->data.StudentID)
                {
                    cout << "        " << NodeSore->data.totalMark;
                    countCourse++;
                    sumGPA += NodeSore->data.totalMark;
                    break;
                }
            }
            if (NodeSore == nullptr) cout << "        " << "X";
        }
        float GPAThisSemester = sumGPA / ((float)countCourse);
        cout << "        " << fixed << setprecision(1) << GPAThisSemester;
        float overallGPA;
        ifstream GPAfile;
        string classnameGPA = clName;
        classnameGPA += "GPA.txt";
        GPAfile.open(classnameGPA);
        if (GPAfile)
        {
            int NumOfStudentInClass;
            GPAfile >> NumOfStudentInClass;
            int STID;
            int allCourse;
            float GPA;
            for (int i = 1; i <= NumOfStudentInClass; i++)
            {
                GPAfile >> STID >> allCourse >> GPA;
                if (STID == NodeStudent->data.StudentID)
                {
                    overallGPA = (GPA * ((float)allCourse) + GPAThisSemester) / ((float)(allCourse + 1));
                    break;
                }
            }
        }
        else cout << "file " << classnameGPA << " cannot open !\n";
        cout << "        " << fixed << setprecision(1) << overallGPA << '\n';
    }
}
void EndofSemester(LinkedList<Year> ListYear)
{
    if (ListYear.pHead == nullptr)
    {
        cout << "create year first!" << endl;
        system("pause");
        return;
    }
    if (ListYear.pHead->data.ListSemester.pHead== nullptr)
    {
        cout << "create semester first!" << endl;
        system("pause");
        return;
    }
    if (ListYear.pHead->data.ListSemester.pHead->data.ListCourse.pHead == nullptr)
    {
        cout << "0 course found! " << endl;
        system("pause");
        return;
    }
    int tmp;
    cout << "1. Export a list of students in a course to a CSV file" << endl;
    cout << "2. Import the scoreboard of a course." << endl;
    cout << "3. View the scoreboard of a course." << endl;
    cout << "4. Update a student result." << endl;
    cout << "5. View the scoreboard of a class" << endl;
    cout << "6. Back" << endl;
    cin >> tmp;
    if (tmp == 6)
    {
        return;
    }
    if(tmp == 1)
    {
        cout << "Please choose the course you want (from 1) :\n";
        outputAllCourse(ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
        int num;
        cin >> num;
        Course a;
        findIndex(ListYear.pHead->data.ListSemester.pHead->data.ListCourse, num, a);
        ofstream fout;
        string coursename = a.CourseName + ".CSV";
        fout.open(coursename);
        outputListFile(a.EnrollStudentList,fout,outputStudentFile);
        fout.close();
        system("pause");
    }
    if (tmp == 2)
    {
        importScoreboard(ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
        system("pause");
    }
    if (tmp == 3)
    {
        viewScoreBoardOfCourse(ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
        system("pause");
    }
    if (tmp == 4)
    {
        updateAStudent(ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
        system("pause");
    }
    if (tmp == 5)
    {
        viewScoreBoardOfClass(ListYear.pHead->data.Listclass,ListYear.pHead->data.ListSemester.pHead->data.ListCourse);
        system("pause");
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
2
2
1
21CTT1
1
21CTT2
2
2
4
21CTT1
2
5
21
*/
void semester(LinkedList<Year> &ListYear, Regis &reg)
{
    int choice;
    while (1)
    {
        system("cls");
        cout << setw(53) << ' ' << "**** Semester Managing ****" << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "1. Create a new semester " << setw(15) << " " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "2. Create a course registration session " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "3. Add a course into semester " << setw(10) << " " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "4. View list of current courses " << setw(8) << " " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "5. Update a course information " << setw(9) << " " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "6. Delete a course " << setw(23) << " " "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << " " << "| " << "7. Back to menu " << setw(24) << " " << "| " << endl;
        cout << setw(45) << ' ' << "-------------------------------------------" << endl;
        cout << setw(45) << "  " << "Input choice (1 - 7): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << setw(40) << " " << "You are creating a semester in year " << ListYear.pTail->data.yearStart << "." << endl;
            Semester tmp = inputSemester(ListYear.pTail->data);
            add(ListYear.pTail->data.ListSemester, tmp);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            cout << setw(40) << " " << "You are creating a course registration session." << endl;
            cout << setw(40) << " " << "Input start date (day month year): ";
            cin >> reg.start.day >> reg.start.month >> reg.start.year;
            cout << setw(40) << " " << "Input end date (day month year): ";
            cin >> reg.end.day >> reg.end.month >> reg.end.year;
            cout << setw(40) << " " << "Create successfully." << endl;
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            addList(ListYear.pTail->data.ListSemester.pTail->data.ListCourse, &inputCourse);
            break;
        }
        case 4:
        {
            system("cls");
            cout << setw(40) <<  " " << "<----List of current available course---->" << endl;
            outputAllCourse(ListYear.pTail->data.ListSemester.pTail->data.ListCourse);
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            if (ListYear.pTail->data.ListSemester.pTail->data.ListCourse.pHead == NULL)
            {
                cout << "No courses to modify" << endl;
                system("pause");
            }
            else
            {
                int ind;
                cout << setw(40) << " " << "<----List of current available course---->" << endl;
                outputAllCourse(ListYear.pTail->data.ListSemester.pTail->data.ListCourse);
                cout << "Input the index of the course you want to update: ";
                cin >> ind;
                updateIndex(ListYear.pTail->data.ListSemester.pTail->data.ListCourse, ind, &inputCourse);
                system("pause");
            }
            break;
        }
        case 6:
        {
            system("cls");
            if (ListYear.pTail->data.ListSemester.pTail->data.ListCourse.pHead == NULL)
            {
                cout << "No courses to delete" << endl;
                system("pause");
            }
            else
            {
                int ind;
                cout << setw(40) << " " << "<----List of current available course---->" << endl;
                outputAllCourse(ListYear.pTail->data.ListSemester.pTail->data.ListCourse);
                cout << "Input the index of the course you want to delete: ";
                cin >> ind;
                removeIndex(ListYear.pTail->data.ListSemester.pTail->data.ListCourse, ind);
                cout << "Delete successfully" << endl;
                system("pause");
            }
            break;
        }
        case 7:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice, please try again" << endl;
            system("pauese");
            break;
        }
        }
    }
}

void student(int id, LinkedList<Year>& ListYear, Date &today, Regis &reg)
{
    if (ListYear.pHead == nullptr)
    {
        cout << "create year first!" << endl;
        system("pause");
        return;
    }
    if (ListYear.pHead->data.ListSemester.pHead== nullptr)
    {
        cout << "create semester first!" << endl;
        system("pause");
        return;
    }
    if (ListYear.pHead->data.ListSemester.pHead->data.ListCourse.pHead == nullptr)
    {
        cout << "0 course found! " << endl;
        system("pause");
        return;
    }
    LinkedList <Course> ListCourse = ListYear.pHead->data.ListSemester.pHead->data.ListCourse;
    Student user;
    string ID = to_string(id);
    //ListYear.pHead->data.ListSemester.pHead->data.ListCourse
    Node <Class>* NodeClass = ListYear.pHead->data.Listclass.pHead;
    bool check1 = true;
    for (; NodeClass != nullptr; NodeClass = NodeClass->pNext)
    {
        user = findStudent(NodeClass->data.listOfStudents, id, check1);
        if (check1 == true)
            break;
    }
    if (check1 == false)
    {
        cout << "Can not find your information, please try again!\n";
        return;
    }

    LinkedList <Student> ListStudent = NodeClass->data.listOfStudents;
    Student stutemp = user;
    int choice;
    while (1)
    {
        system("cls");
        cout << setw(60) << ' ' << "*****  Student's Activities *****" << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << " " << "| " << "1. Enroll Course" << setw(14) << " " << "|" << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << " " << "| " << "2. View list of enroll course" << " " << "|" << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << " " << "| " << "3. Remove Course" << setw(16) << " " "| " << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << " " << "| " << "4. View your scoreboard" << setw(9) << " " "| " << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << " " << "| " << "5. Back" << setw(25) << " " "| " << endl;
        cout << setw(60) << ' ' << "---------------------------------" << endl;
        cout << setw(60) << "  " << "Input choice (0 - 5): ";
        cin >> choice;
        if (choice == 1)
        {
            enrollCourse(ListCourse, stutemp,today,reg);
            system("pause");
        }
        else if (choice == 2)
        {
            system("cls");
            viewEnrollCourse(stutemp);
            system("pause");
        }
        else if (choice == 3)
        {
            system("cls");
            removeCourseFromEnrollList(stutemp);
        }
        else if (choice == 4)
        {
            viewScoreBoard(ListYear.pHead->data.ListSemester.pHead->data.ListCourse, user);
            system("pause");
        }
        else if (choice == 5)
        {
            return;
        }
        else
        {
            cout << "invalid input, please try again!" << endl;
        }
    }

}
