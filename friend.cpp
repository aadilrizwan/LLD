// Friend function and friend class in C++
// A friend function is a function that is not a member of a class but has access to its private and protected members.
// A friend class is a class that is declared as a friend of another class, allowing it to access the private and protected members of that class.

#include <iostream>
using namespace std;
class Box{
    private:
    int length;
    public:
    Box(int l): length(l){}
    friend void printLength(Box b); // Friend function declaration
    friend class Printer; // Friend class declaration
};

void printLength(Box b){
    cout << "Length of Box: " << b.length << endl; // Accessing private member
}

class Printer{
    public:
    void print(Box b){
        cout << "Length of Box from Printer: " << b.length << endl; // Accessing private member
    }
};

int main(){
    Box box(10);
    printLength(box); // Calling friend function
    Printer printer;
    printer.print(box); // Calling friend class method
    return 0;
}