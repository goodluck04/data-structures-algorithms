#include <iostream>

class MyClass {
public:
    // Global variable shared by all instances of MyClass
    static int globalVariable;

    // Constructor
    MyClass() {
        // Increment the global variable in each instance
        globalVariable++;
    }
};

// Initializing the global variable
int MyClass::globalVariable = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    // All instances share the same global variable
    std::cout << "Global Variable: " << MyClass::globalVariable << std::endl;

    return 0;
}
