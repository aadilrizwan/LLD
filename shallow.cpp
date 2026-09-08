// Shallow vs Deep Copy
// In C++, when an object of a class is copied, there are two types of copies that can be made: shallow copy and deep copy.

// A shallow copy copies all the member values from one object to another, including pointers. 
// This means that both objects will point to the same memory location for any dynamically allocated memory, which can lead to issues such as double deletion or unexpected changes in one object affecting the other.

// A deep copy, on the other hand, creates a new copy of any dynamically allocated memory
// and copies the values from the original object to the new object. This ensures that each object has its own separate copy of the data, preventing issues related to shared memory.

// Why new?
// Because we want to allocate memory during runtime.
// This is called dynamic memory allocation.

#include <bits/stdc++.h>
using namespace std;
class String{
    char* str;
    public:
    String(const char* s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor for deep copy
    String(const String& other){
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    ~String(){
        delete[] str;
    }
    void display() const {
        cout << str << endl;
    }
};

int main(){
    String s1("Hello");
    String s2 = s1; // Calls copy constructor for deep copy
    s1.display();
    s2.display();
    return 0;
}


// char* str
//    ↓
// pointer that stores the address

// new char[...]
//    ↓
// creates memory

// strcpy(...)
//    ↓
// copies characters

// String(const String& other)
//    ↓
// deep copy

// ~String()
//    ↓
// destructor

// delete[]
//    ↓
// frees the memory