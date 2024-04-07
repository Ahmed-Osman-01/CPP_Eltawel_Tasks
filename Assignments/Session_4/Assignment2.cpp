#include <iostream>

using namespace std;

class Student
{
    string name;
    char Class;
    int rollNumber;
    int marks;

public:
    Student():Student("None", '0', -1, -1)
    {}
    Student(string n, char c, int r, int m) : name{n}, Class{c}, rollNumber{r}, marks{m}
    {}

    void setName(string n) {name = n;}
    void setClass(char c) {Class = c;}
    void setRollNumber(int r) {rollNumber = r;}
    void setMarks(int m) {marks = m;}

    string getName(void) {return name;}
    char getClass(void) {return Class;}
    int getRollNumber(void) {return rollNumber;}
    int getMarks(void) {return marks;}

    void displayInfo(void)
    {
        cout<<"Student details:"<<endl;
        cout << "Name : " << name<< endl;
        cout << "Class: " << Class<< endl;
        cout << "Roll Number: "<< rollNumber<<endl;
        cout << "Marks[0-100]:" << marks<<endl;;
    }
};


int main()
{

    Student s{"Ahmed", 'B', 7, 98};

    s.displayInfo();
    return 0;
}