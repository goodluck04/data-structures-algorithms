#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;
    int marks;

// this default constructor
    Student(){
        cout << "Student class constructor" << endl;

    }

    // parameterized constructor - it takes parameters and initialize data mamber of class
    Student(string name,int rollNo,int marks){
        this->name=name;
        this->rollNo=rollNo;
        this->marks=marks;
    }

    void setData(string name, int rollNo, int marks){
        this->name=name;
        this->rollNo=rollNo;
        this->marks=marks;
    }

    void printData() {
        cout << "My name is " << name <<" and rollno is " << rollNo << " I got " << marks << " marks out of 100\n";
    }


};


int main(){
    // create object of student 
    Student s1; // default constructor will initialize the value


    Student s2("goodluck",21,90);

    cout << s1.name << endl;
    cout << s1.rollNo << endl;
    cout << s1.marks << endl;


    // setting value with hel[ of setter function
    // s1.setData("goodluck",21,90);

    // calling method of class
    s1.printData();
    s2.printData();
    return 0;
}
