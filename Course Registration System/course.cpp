#include "course.h"
using namespace std;

//Function to add Course to a Semester
//addList(ListYear.pHead->data.ListSemester.pHead->data.ListCourse, &inputCourse);
Course inputCourse()
{
    Course a;
    cin.ignore(1000, '\n');
    cout << setw(40) << " " << "Course ID: ";
    getline(cin, a.ID);
    cout << setw(40) << " " << "Course Name: ";
    getline(cin, a.CourseName);
    cout << setw(40) << " " << "Teacher Name: ";
    getline(cin, a.TeacherName);
    cout << setw(40) << " " << "Number Of Credits: ";
    cin >> a.NumbOfCredits;
    cin.ignore(1000, '\n');
    cout << setw(40) << " " << "Available Session: MON, TUE, WED, THU, FRI, SAT." << endl;
    cout << setw(40) << " " << "Available Time: S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)." << endl;
    cout << setw(40) << " " << "First Session's Day: ";
    getline(cin, a.s1.day);
    cout << setw(40) << " " << "Session Time: ";
    getline(cin, a.s1.period);
    cout << setw(40) << " " << "Second Session's Day: ";
    getline(cin, a.s2.day);
    cout << setw(40) << " " << "Session Time: ";
    getline(cin, a.s2.period);
    return a;
}

// To display the list of courses, use the void displayAll() functions
// Pass in the outputCourse as a function parameter
void outputCourse(Course c1)
{
    cout << left << setw(25) << c1.ID
         << left << setw(25) << c1.CourseName
         << left << setw(25) << c1.TeacherName
         << left << setw(10) << c1.NumbOfCredits
         << left << setw(14) << (c1.s1.day + " - " + c1.s1.period)
         << left << setw(14) << (c1.s2.day + " - " + c1.s2.period)
         << endl;
}

void outputCourseMenu()
{
    cout << left << setw(5) << "No"
         << left << setw(25) << "Course ID"
         << left << setw(25) << "Course Name"
         << left << setw(25) << "Lecturer"
         << left << setw(10) << "Credits"
         << left << setw(14) << "Session 1"
         << left << setw(14) << "Session 2"
         << endl;
}

void outputAllCourse(LinkedList<Course> ListCourse)
{
    outputCourseMenu();
    displayAll(ListCourse, &outputCourse);
}

void removeCourse(LinkedList<Course> ListCourse)
{
    outputAllCourse(ListCourse);
    int temp;
    cout << setw(40) << " " << "Please input the number of the Course you want to remove (From 1): ";
    cin >> temp;
    removeIndex(ListCourse, temp);
    system("cls");
    outputAllCourse(ListCourse);
}

bool checkSessionConflict(Session s1, Session s2)
{
    if (s1.day == s2.day)
    {
        if (s1.period == s2.period)
            return true;
    }
    return false;
}

bool checkAvailable(Course a, Student s)
{
    while (s.ListCourseData.pHead != nullptr)
    {
        if (checkSessionConflict(a.s1, s.ListCourseData.pHead->data.s1) || checkSessionConflict(a.s1, s.ListCourseData.pHead->data.s2)
                || checkSessionConflict(a.s2, s.ListCourseData.pHead->data.s1) || checkSessionConflict(a.s2, s.ListCourseData.pHead->data.s2))
            return false;
        else
        {
            s.ListCourseData.pHead = s.ListCourseData.pHead->pNext;
        }
    }
    return true;
}

CourseData addCourseData(Course a)
{
    CourseData b;
    b.CourseName = a.CourseName;
    b.ID = a.ID;
    b.s1 = a.s1;
    b.s2 = a.s2;
    b.TeacherName = a.TeacherName;
    return b;
}

void enrollCourse(LinkedList<Course> &ListCourse, Node<Student> *a, Date &today, Regis &reg)
{
    system("cls");
    if (compareDate(reg.start,today) == true && compareDate(today,reg.end) == true )
    {
        cout << setw(40) << " " << "Choose the option: " << endl;
        cout << setw(40) << " " << "1. Enroll Course" << endl;
        cout << setw(40) << " " << "2. Exit" << endl;
        cout << setw(40) << " ";
        int numb;
        cin >> numb;
        if (numb == 1)
        {
            if (a->data.numCourse == 5)
            {
                cout << setw(40) << " " << "Number of courses reached maximum" << endl;
                cout << setw(40) << " ";
                system("pause");
                return;
            }
            else
            {
                outputAllCourse(ListCourse);
                cout << setw(40) << " " << "Enter the Course No you want to enroll: ";
                cin >> numb;
                Course temp;
                if (findIndex(ListCourse, numb, temp))
                {
                    if (checkAvailable(temp, a->data) && temp.NumbOfStudent < temp.MaxStudent)
                    {
                        Node<Course>* current = ListCourse.pHead;
                        for (int i = 1; i < numb; ++i)
                        {
                            current = current->pNext;
                        }
                        add(current->data.EnrollStudentList, a->data);
                        current->data.NumbOfStudent++;

                        CourseData dtemp = addCourseData(temp);
                        add(a->data.ListCourseData, dtemp);
                        a->data.numCourse++;
                        cout << setw(40) << "Enrolled Successfully.\n";
                        cout << setw(40) << " ";
                        system("pause");
                    }
                    else
                    {
                        cout << setw(40) << " " << "Timetable conflicted. Please choose other courses.\n";
                        cout << setw(40) << " ";
                        system("pause");
                        enrollCourse(ListCourse, a, today,reg);
                    }
                }
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        cout << setw(40) << " " << "Course registration session is close!\n";
        cout << setw(40) << " ";
        system("pause");
    }
}

void outputCourseData(Student a)
{
    while (a.ListCourseData.pHead != nullptr)
    {
        cout << a.ListCourseData.pHead->data.CourseName << endl;
        a.ListCourseData.pHead = a.ListCourseData.pHead->pNext;
    }
}
void importScoreboard(LinkedList<Course> &ListCourse)
{
    outputAllCourse(ListCourse);
    cout << setw(40) << " " << "Type the Course that you want import score board (from 1):\n ";
    int num;
    cin >> num;
    Node<Course>*a = ListCourse.pHead;
    for (int i = 1; i < num; i++)
    {
        a = a->pNext;
    }
    string filename = a->data.ID + "scoreboard.txt";
    ifstream FileScore;
    FileScore.open(filename);
    if (FileScore)
    {
        cout << setw(40) << " " << "Importing successful!\n";
        cout << a->data.NumbOfStudent << endl;
        for (int i = 0; i < a->data.NumbOfStudent; i++)
        {
            Score tmp;
            FileScore >> tmp.no >> tmp.ID;
            getline(FileScore >> ws, tmp.fullname);
            FileScore >> tmp.totalMark >> tmp.finalMark >> tmp.midtermMark >> tmp.otherMark;
            add(a->data.scoreBoard,tmp);
        }
    }
    else
        cout << setw(40) << " " << "Loading file error, please try again!\n";
    FileScore.close();
    /*  Node<Score> *tmp = a.scoreBoard.pHead;
      for (int i = 0; i < a.NumbOfStudent; i++)
      {

          cout << tmp->data.no << ' ' << tmp->data.ID << ' ' << tmp->data.fullname << ' ' << tmp->data.totalMark << ' ' << tmp->data.finalMark << ' ' << tmp->data.midtermMark << ' ' << tmp->data.otherMark << endl;
          tmp = tmp->pNext;
      }*/

}
void outputScoreBoard(Score s1)
{
    cout << left << setw(20) << s1.ID
         << left << setw(20) << s1.fullname
         << left << setw(15) << s1.midtermMark
         << left << setw(15) << s1.finalMark
         << left << setw(13) << s1.otherMark
         << left << setw(13) << s1.totalMark
         << '\n';
}
void outputScoreBoardMenu()
{


    cout << "\n";
    cout << left << setw(5) << "No"
         << left << setw(20) << "ID"
         << left << setw(20) << "Full Name"
         << left << setw(15) << "Midterm Mark"
         << left << setw(15) << "Final Mark"
         << left << setw(13) << "Other Mark"
         << left << setw(13) << "Total Mark"
         << '\n';
}
void viewScoreBoardOfCourse(LinkedList<Course> &ListCourse)
{
    cout << setw(20) << " " << "Type the Course that you want to view score board (from 1): \n";
    outputAllCourse(ListCourse);
    int num;
    cin >> num;
    Course a;
    findIndex(ListCourse, num, a);
    outputScoreBoardMenu();
    displayAll(a.scoreBoard, &outputScoreBoard);
}
void updateAStudent(LinkedList<Course> &ListCourse)
{
    outputAllCourse(ListCourse);
    cout << setw(40) << " " << "Please enter the course you want to update(from 1) :\n";
    int num;
    cin >> num;
    Course a;
    findIndex(ListCourse, num, a);
    cout << setw(40) << " " << "Please enter the ID of the student you want to update:\n";
    int ID;
    cin >> ID;
    bool flag = false;
    for (Node<Score> *tmp = a.scoreBoard.pHead; tmp != nullptr; tmp = tmp->pNext)
    {
        if (tmp->data.ID == ID)
        {
            float finalmark;
            cout << setw(40) << " " << "Final mark:" << endl;
            cin >> finalmark;
            float midtermmark;
            cout << setw(40) << " " << "Midterm mark:" << endl;
            cin >> midtermmark;
            float othermmark;
            cout << setw(40) << " " << "Other mark:" << endl;
            cin >> othermmark;
            float totalmark;
            cout << setw(40) << " " << "Total mark:" << endl;
            cin >> totalmark;
            tmp->data.midtermMark = midtermmark;
            tmp->data.finalMark = finalmark;
            tmp->data.totalMark = totalmark;
            tmp->data.otherMark = othermmark;
            flag = true;
            cout << setw(40) << " " << "Update successful!\n";
        }
    }
    if (flag == false)
    {
        cout << setw(40) << " " << "There is no student with this ID in the course, please try again!\n";
    }
}

/*
2021
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
1
21CTT1
1
21CTN1
2
21CTT1
1
1
21CTT1
*/
//void removeCourseEnroll(LinkedList<Course> ListCourse)
void outputStudentInCourse(LinkedList<Course>ListCourse)
{
    cout << "Type the Course No you want to view list of student (from 1): \n";
    outputAllCourse(ListCourse);
    int num;
    cin >> num;
    Course c1;
    findIndex(ListCourse, num, c1);
    system("cls");
    cout << "All students in course " << c1.CourseName << " are: \n";
    displayAll(c1.EnrollStudentList, &outputStudent);
}

void viewEnrollCourse(Student s1)
{
    if (s1.ListCourseData.pHead == nullptr) cout << "This student hasn't enrolled course\n";
    else
    {
        cout << "All Enrolled Course by " << s1.FirstName << " " << s1.LastName << " are: \n";
        Node<CourseData>* temp = s1.ListCourseData.pHead;
        for (temp; temp!=nullptr; temp=temp->pNext)
        {
            cout << temp->data.CourseName << " (" << temp->data.ID << ") " << endl;
        }
    }
}
void removeCourseFromEnrollList(Node<Student> *s1)
{
    cout << setw(40) << " " << "Choose the option: " << endl;
    cout << setw(40) << " " << "1. Remove Course Data" << endl;
    cout << setw(40) << " " << "2. Exit" << endl;
    cout << setw(40) << " " << "Your choice is: ";
    int choose;
    cin >> choose;
    while (choose != 1 && choose != 2)
    {
        cout << setw(40) << " " << "Please choose again: " << endl;
        system("pause");
        system("cls");
        removeCourseFromEnrollList(s1);
    }
    if (choose == 1)
    {
        system("cls");
        viewEnrollCourse(s1->data);
        cout << "Input the Course ID you want to remove: ";
        string num;
        cin >> num;
        Node <CourseData>* temp = s1->data.ListCourseData.pHead;
        Node <CourseData>* pre = new Node <CourseData>;
        pre->pNext = temp;
        while (temp != nullptr)
        {
            if (temp->data.ID == num)
            {
                if (temp == s1->data.ListCourseData.pHead)
                {
                    s1->data.ListCourseData.pHead = s1->data.ListCourseData.pHead->pNext;
                    delete temp;
                    break;
                }
                else
                {
                    Node <CourseData>* del = temp;
                    pre->pNext = temp->pNext;
                    temp = temp->pNext;
                    delete del;
                    if (temp == nullptr)
                    {
                        s1->data.ListCourseData.pTail = pre;
                    }
                    break;
                }
            }
            else
            {
                temp = temp->pNext;
                pre = pre->pNext;
            }
        }
        cout << "List of CourseData after removing: " << endl;
        viewEnrollCourse(s1->data);
        system("pause");
    }
    if (choose == 2)
    {
        return;
    }

}

bool checkIfStudentInCourse(Course c1, Student s1)
{
    Node<Student>* temp = c1.EnrollStudentList.pHead;
    while (temp != nullptr)
    {
        if (temp->data.StudentID == s1.StudentID) return true;
        temp = temp->pNext;
    }
    return false;
}
bool checkIfStudentInListCourse(LinkedList<Course> listCourse, Student s)
{
    Node <Course>* temp = listCourse.pHead;
    Node <Student>* cur = listCourse.pHead->data.EnrollStudentList.pHead;
    while (temp)
    {
        // cur = temp->data.EnrollStudentList.pHead; ??
        while (cur)
        {
            if (cur->data.StudentID == s.StudentID) return true;
            cur = cur->pNext;
        }
        temp = temp->pNext;
    }
    return false;
}
//bool checkIfScoreOfCoursehasStudent(Node<Course>* c1, Student s) {
//    if (c1 == nullptr) return false;
//    Node <Score>* temp = c1->data.scoreBoard.pHead;
//    while (temp != nullptr) {
//        if (temp->data.ID == s.StudentID) return true;
//        temp = temp->pNext;
//    }
//    return false;
//}
Score inputScore()
{
    Score s;
    cout << setw(40) << " " << "Input No" << endl;
    cin >> s.no;
    cout << setw(40) << " " << "Input ID" << endl;
    cin >> s.ID;
    cout << setw(40) << " " << "Input Student full name" << endl;
    cin.ignore(1000, '\n');
    getline(cin, s.fullname);
    cout << setw(40) << " " << "Input Mark" << endl;
    cin >> s.totalMark >> s.finalMark >> s.midtermMark >> s.otherMark;
    return s;
}
void scoreBoardMenu()
{
    cout << left << setw(15) << "Course Name"
         << left << setw(15) << "Total Mark"
         << left << setw(15) << "Final Mark"
         << left << setw(15) << "MidTerm Mark"
         << left << setw(15) << "Other Mark"
         << endl;
}
void outputScore(Node<Course>* c1, Student s)
{
    Node <Score>* temp = c1->data.scoreBoard.pHead;
    while (temp)
    {
        if (temp->data.ID == s.StudentID)
        {
            cout << left << setw(15) << c1->data.CourseName
                 << left << setw(15) << temp->data.totalMark
                 << left << setw(15) << temp->data.finalMark
                 << left << setw(15) << temp->data.midtermMark
                 << left << setw(15) << temp->data.otherMark
                 << endl;
            break;
        }
        temp = temp->pNext;
    }
}
void viewScoreBoard(LinkedList<Course> ListCourse, Student s1)
{
    Node<Course>* temp = ListCourse.pHead;
    if (ListCourse.pHead == nullptr)
    {
        cout << setw(40) << " " << "No course";
        return;
    }
    if (checkIfStudentInListCourse(ListCourse, s1))
    {
        scoreBoardMenu();
    }
    while (temp != nullptr)
    {
        if (checkIfStudentInCourse(temp->data, s1))
        {
            outputScore(temp, s1);
        }
        temp = temp->pNext;
    }
}
