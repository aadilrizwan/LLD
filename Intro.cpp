#include <bits/stdc++.h>
using namespace std;

class Student{
public:
    // Attributes
    int id;
    string name;
    int age;
    int nos; // no of subjects

    Student(){
        cout << "Default Constructor called" << endl;
    }

    // Parameterized Constructor
    Student(int id, string name, int age, int nos){
        cout << "Parameterized Constructor called" << endl;
        this->id = id;
        this->name = name;
        this->age = age;
        this->nos = nos;
    }

    // Copy Constructor
    Student(const Student &s){
        cout << "Copy Constructor called" << endl;
        this->id = s.id;
        this->name = s.name;
        this->age = s.age;
        this->nos = s.nos;
    }

    // Behaviour / Methods / Functions
    void study(){
        cout << this->name << " is studying" << endl;
    }
    void sleep(){
        cout << this->name << " is sleeping" << endl;
    }

    ~Student(){
        cout << this->name << "Default Destructor called" << endl;
    }
};

int main(){
    Student A;
    A.id = 101;
    A.name = "Alice";
    A.age = 20;
    A.nos = 5;
    A.study();
    A.sleep();

    Student B(102, "Bob", 21, 6);
    B.study();
    B.sleep();

    Student C(B); // This will invoke the copy constructor
    C.study();
    C.sleep();

    // Dynamically allocated object
    Student *D = new Student(103, "Charlie", 22, 7);
    cout << "D's name: " << D->name << endl;
    delete D; // delete manually allocated object to avoid memory leak


    return 0;
    // 58:00
}