#include <iostream>
using namespace std;

// Singleton class
// Purpose: Make sure that only ONE object of this class exists.
class Singleton {
private:
    Singleton() {
        cout << "Singleton Object Created\n";
    }
    // 2. Delete Copy Constructor Prevents creating a NEW object by copying an existing object.
    // Singleton obj2 = obj1;  // Not allowed
    Singleton(const Singleton&) = delete;
    // 3. Delete Copy Assignment Operator Prevents copying one existing object into another existing object.
    // obj2 = obj1;  // Not allowed
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void showMessage() {
        cout << "Singleton!\n";
    }
};
// Maintain only ONE Logger object in the entire program.
class Logger {
private:
    Logger() {
        cout << "Logger Created\n";
    }
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    void info(const string& message) {
        cout << "[INFO] " << message << endl;
    }
    void error(const string& message) {
        cout << "[ERROR] " << message << endl;
    }
    void warning(const string& message) {
        cout << "[WARNING] " << message << endl;
    }
};

int main() {
    Singleton& obj1 = Singleton::getInstance();
    Singleton& obj2 = Singleton::getInstance();
    obj1.showMessage();
    obj2.showMessage();

    // Check whether both are the same object
    if (&obj1 == &obj2) cout << "obj1 and obj2 are the SAME object.\n";
    else cout << "obj1 and obj2 are DIFFERENT objects.\n";
    

    Logger& logger1 = Logger::getInstance();

    logger1.info("Application started");
    logger1.info("User logged in");

    logger1.warning("Low memory");

    logger1.error("Database connection failed");

    Logger& logger2 = Logger::getInstance();

    logger2.info("Trying to reconnect to database");

    if (&logger1 == &logger2) cout << "Both are using the SAME Logger object.\n";
    
    return 0;
}