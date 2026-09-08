#include <iostream>
using namespace std;

//  Single Inheritance
class Animal{
public:
    void eat(){
        cout << "Eating..." << endl;
    }
};

class Cow : public Animal{
public:
    void sound(){
        cout << "Moo..." << endl;
    }
};

int main(){
    Cow myCow;
    myCow.eat();   // Inherited from Animal class
    myCow.sound(); // Specific to Cow class
    return 0;
}
