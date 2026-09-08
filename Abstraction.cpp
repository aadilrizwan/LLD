// Hiding implementation details

#include <iostream>
using namespace std;
class Car{
public:
    void start(){
        // complex implementation hidden
        checkEngine();
        injectFuel();
        ignite();
        cout << "Car started successfully!" << endl;
    }

private:
    void checkEngine(){
        // Check engine status
        cout << "Checking engine..." << endl;
    }
    void injectFuel(){
        // Inject fuel into the engine
        cout << "Injecting fuel..." << endl;
    }
    void ignite(){
        // Ignite the engine
        cout << "Igniting engine..." << endl;
    }
};

int main(){
    Car myCar;
    myCar.start(); // Start the car, implementation details are hidden
    return 0;
}