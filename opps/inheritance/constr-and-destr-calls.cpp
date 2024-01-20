#include <iostream>
using namespace std;

// in this first base class constuctor then derived constructor is call
// first derived class destructor then base class destructor is call
// Base constructor
// Derived constructor
// Derived Destructor
// Base Destructor

// class Base {

//     public:

//     Base(){
//         cout << "Base constructor\n";
//     }

//     ~Base(){
//         cout << "Base Destructor\n";
//     }

// };

// class Derived:public Base {

//     public:

//     Derived(){
//         cout << "Derived constructor\n";
//     }

//     ~Derived(){
//         cout << "Derived Destructor\n";
//     }

// };

// in this programm we will overide destructor

class Base
{

public:
    Base()
    {
        cout << "Base constructor\n";
    }

    Base(int value)
    {
        cout << "base " << value << "\n";
    }

    virtual ~Base()
    {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base
{

public:
    Derived()
    {
        cout << "Derived constructor\n";
    }
    // we are over ridding base class constructor 
    Derived(int value) : Base(value)
    {
        cout << "Derived constructor\n";
    }

    ~Derived() override
    {
        cout << "Derived Destructor\n";
    }
};

int main()
{

    // Derived deriverdObj1;
    Derived deriverdObj2(12);

    return 0;
}