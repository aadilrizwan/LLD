// Pure virtual function & Abstract class
// An abstract class is a class that cannot be instantiated directly. 
// It is generally used as a blueprint for derived classes.

// A pure virtual function in C++ is a virtual function that has no required implementation in the base class and is declared using = 0.

#include <iostream>
using namespace std;
class Shape{    // Abstract class
    public:
    virtual void draw() = 0; // pure virtual function
    virtual double area() = 0; // pure virtual function
};

class Circle: public Shape{
    double r;
    public:
    Circle(double radius): r(radius) {}
    void draw() override{
        cout << "Drawing Circle" << endl;
    }
    double area() override{
        return 3.14 * r * r;
    }
};

int main(){
    Shape* shape = new Circle(5.0);
    shape->draw();
    cout << "Area of Circle: " << shape->area() << endl;
    delete shape;
    return 0;
}