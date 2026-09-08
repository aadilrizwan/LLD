// Static Members in C++ are class members that are shared among all instances of the class. 
// They are not tied to any specific object, but rather belong to the class itself. 
// Static members can be variables or functions, and they are declared using the `static` keyword.

// Normal member = each object gets its own copy.
// Static member = the class has one shared copy for all objects.

// Without static
// class Student {
// public:
//     string name;
// };

// If we create:

// Student s1;
// Student s2;

// Each object has its own name:

// s1 → name = "Rahul"
// s2 → name = "Amit"

// Changing s1.name does not affect s2.name.

// With static
// class Student {
// public:
//     static int count;
// };

// Now there is only one count, shared by everyone:

//              Student class
//                   |
//                 count
//                   |
//           ┌───────┴───────┐
//           ↓               ↓
//          s1              s2

// Both s1 and s2 refer to the same count.

// So:

// Student::count = 10;

// and then:

// cout << s1.count;  // 10
// cout << s2.count;  // 10

#include <iostream>
using namespace std;
class Counter{
    public:
    static int count; // Static member variable
    Counter() { count++; } // Constructor increments count
    static void displayCount() { // Static member function
        cout << "Count: " << count << endl;
    }
};
int Counter::count = 0; // Definition of static member variable
int main(){
    Counter c1,c2,c3;
    Counter::displayCount(); // Accessing static member function
}