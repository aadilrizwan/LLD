// Runtime Polymorphism in C++ using virtual functions
// A virtual function is a member function in a base class that can be overridden in a derived class. 
// When you call it through a base-class pointer/reference, C++ decides at runtime which version to execute.
#include <iostream>
using namespace std;

class Animal{
public:
    virtual void sound(){
        cout << "Animal Sound\n";
    }
    virtual ~Animal() {}
};

class cow : public Animal{
public:
    void sound() override {
        cout << "Moo..\n";
    }
};

class cat : public Animal {
public:
    void sound() override {
        cout << "Meow..\n";
    }
};

int main() {
    Animal *a1 = new cow();
    Animal *a2 = new cat();

    a1->sound();
    a2->sound();

    delete a1;
    delete a2;

    return 0;
}