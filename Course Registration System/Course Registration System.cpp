#include "year.h"
#include "login.h"
using namespace std;
int main()
{
    LinkedList<Year> ListYear;
     login(ListYear);

    //example to use function : import Score board,	view Score Board Of a Course  ,and update A Student's result;
  /*  LinkedList<Year> ListYear;
    CreateYear(ListYear);
    LinkedList<Course> ListCourse;
    addList(ListCourse, &inputCourse);
    outputAllCourse(ListCourse);
    LinkedList<Class> ListClass;
    addList(ListYear.pHead->data.Listclass, inputClass);
    ListClass = ListYear.pHead->data.Listclass;
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
        return 0;
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
    //    system("pause");
    Student a;
    a.dob = {17,07,2003};
    a.FirstName = "Quoc";
    a.Gender = 1;
    a.LastName = "Tran Le";
    a.No = 1;
    a.StudentID  = 21125093;
    a.SocialID  = 5;

    Student b;
    b.dob = {17,07,2003};
    b.FirstName = "Nguyen Van";
    b.Gender = 2;
    b.LastName = "A";
    b.No = 2;
    b.StudentID  = 21125090;
    b.SocialID  = 6;

    Student c;
    b.dob = {18,07,2003};
    b.FirstName = "Nguyen Van";
    b.Gender = 2;
    b.LastName = "B";
    b.No = 3;
    b.StudentID  = 2112509;
    b.SocialID  = 7;

    add(ListCourse.pHead->data.EnrollStudentList, a);
    ListCourse.pHead->data.NumbOfStudent++;
    add(ListCourse.pHead->data.EnrollStudentList, b);
    ListCourse.pHead->data.NumbOfStudent++;
    add(ListCourse.pHead->data.EnrollStudentList, c);
    ListCourse.pHead->data.NumbOfStudent++;

    add(ListCourse.pHead->pNext->data.EnrollStudentList, a);
    ListCourse.pHead->pNext->data.NumbOfStudent++;
    add(ListCourse.pHead->pNext->data.EnrollStudentList, b);
    ListCourse.pHead->pNext->data.NumbOfStudent++;
    add(ListCourse.pHead->pNext->data.EnrollStudentList, c);
    ListCourse.pHead->pNext->data.NumbOfStudent++;

    importScoreboard(ListCourse);
    viewScoreBoardOfCourse(ListCourse);
    viewScoreBoardOfClass(ListClass,ListCourse);
    //updateAStudent(ListCourse);
    //viewScoreBoardOfCourse(ListCourse);

//	end example~~~

*/

    /*LinkedList<Year> listYear;
    Year y1{ 2020 };
    Year y2{ 2021 };
    Year y3{ 2022 };
    add(listYear, y1);
    add(listYear, y2);
    addFront(listYear, y3);
    cout << length(listYear) << endl;
    addList(listYear.pHead->data.Listclass, &inputClass);
    deallocateAll(listYear);

    CreateYear(listYear);

    LinkedList<Course> ListCourse;
    addList(ListCourse, &inputCourse);
    outputAllCourse(ListCourse);
    updateIndex(ListCourse, 1, inputCourse);
    outputAllCourse(ListCourse);
    deallocateAll(ListCourse);
    LinkedList<Student> ListStudent;
    inputStudentCSV(ListStudent);
    cout << ListStudent.pHead->data.No << endl;
    deallocateAll(ListStudent);*/


    //LinkedList<Student> ListStudent;
//	inputFile(ListStudent, &inputStudentFile);
//	Student s1 = findStudent(ListStudent);
    //outputStudent(s1);
    //////displayAll(ListStudent, &outputStudent);
    //addList(ListStudent, &AddStudent);
    //outputAllStudent(ListStudent);


    /*LinkedList<Course> ListCourse;
    addList(ListCourse, &inputCourse);
    removeCourse(ListCourse);*/


    /*LinkedList<Class> listClass;
    addList(listClass, &inputClass);
    outputListClass(listClass);
    return 0;*/

    /*Class c1{ "21CTT1", nullptr };
    addList(c1.listOfStudents, &AddStudent);
    outputStuListFile(c1);*/

    /*int index;
    LinkedList<Course> c1;
    addList(c1, &inputCourse);
    cout << "input index";
    cin >> index;
    Course c2;
    findIndex(c1, index, c2);
    cout << c2.CourseName;

    LinkedList <Course> ListCourse;
    addList(ListCourse, &inputCourse);
    Node<Course>* c;
    c = ListCourse.pHead;
    addList(c->data.EnrollStudentList, &AddStudent);
    outputStudentInCourse(ListCourse);*/
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

