// C++ doesn't have a dedicated interface keyword. An interface is typically implemented using an abstract class containing pure virtual functions. 
// It defines a contract that derived classes must implement, allowing us to achieve abstraction and runtime polymorphism.

#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay() = 0;
    virtual ~Payment() = default;
};

// UPI implements the Payment interface
class UPI : public Payment {
public:
    void pay() override {
        cout << "Payment through UPI" << endl;
    }
};

// CreditCard implements the Payment interface
class CreditCard : public Payment {
public:

    // Providing implementation of pay()
    void pay() override {
        cout << "Payment through Credit Card" << endl;
    }
};


int main() {
    // Payment is an abstract class, so we CANNOT create: Payment p;
    UPI upi;
    CreditCard card;

    upi.pay();
    card.pay();

    // base-class pointer , Payment* pointer and make it point to the existing upi and card object
    Payment* p1 = &upi;
    Payment* p2 = &card;

    // Runtime polymorphism
    // C++ decides at runtime which pay() to call
    p1->pay();  // Calls UPI::pay()
    p2->pay();  // Calls CreditCard::pay()

    return 0;
}