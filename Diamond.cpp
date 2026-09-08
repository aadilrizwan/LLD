#include <iostream>
using namespace std;

class A{
public:
    void show(){
        cout << "A";
    }
};
class B : public A{};
class C : public A{};
class D : public B, public C{};


// virtual inheritance can be used to solve the diamond problem
class E{
public:
    void show(){
        cout << "E";
    }
};
class F : virtual public E{};
class G : virtual public E{};
class H : public F, public G{};
int main(){
    D obj;
    // obj.show(); // This will cause ambiguity error
    obj.B::show(); // Resolving ambiguity by specifying the path

    H obj2;
    obj2.show(); // No ambiguity, works fine due to virtual inheritance
    return 0;
}