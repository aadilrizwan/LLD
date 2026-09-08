//  Singleton Pattern ensures that Only one object of a class can exist throughout the program, and everyone accesses that same object.
// Real-world example

// Imagine an application having a single Logger:

// Application
//    |
//    +---- Module A ----+
//    |                  |
//    +---- Module B ----+----> ONE Logger
//    |                  |
//    +---- Module C ----+

#include <iostream>
using namespace std;

class Logger {
private:
    // Private constructor
    Logger() {
        cout << "Logger Created\n";
    }

public:
    // Prevent copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Get the single object
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(string message) {
        cout << "LOG: " << message << endl;
    }
};

int main() {

    Logger& l1 = Logger::getInstance();
    Logger& l2 = Logger::getInstance();

    l1.log("Hello");
    
    cout << (&l1 == &l2) << endl;

    return 0;
}
