#include <iostream>

class MyClass {
public:
    // Static member shared by all instances of MyClass
    static int staticVariable;

    // Constructor
    MyClass() {
        // Increment the static variable in each instance
        staticVariable++;
    }
};

// Initializing the static variable
int MyClass::staticVariable = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    // All instances share the same static variable
    std::cout << "Static Variable: " << MyClass::staticVariable << std::endl;

    return 0;
}
