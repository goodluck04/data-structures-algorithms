#include <iostream>
using namespace std;

// polymorphism means one exhibit more than forms
// compile time- during compile time will be decide what will be the behavior of the function by using function overloading and operator overloading
//  and runtime polymorphism - during runtime and decide only at rune time using virtual functions


// this is example of function overlaoding compile time polymorphism
// all the function inside class shold have same return type
class Find{
    public:

    // without argument
    void fun(){
        cout << "value of x is: " << 0 << endl; 
    }
    // argument with int
    void fun(int x){
        cout << "value of x is: " << x << endl; 
    }
    // argument with double
    void fun(double x){
        cout << "value of x is: " << x << endl; 
    }
    // with 2 arguments
    void fun(int x, int y){
        cout << "value of x and y is: " << x << " " << y << endl; 
    }
};

int main(){

    Find object1;

    // first behavior
    object1.fun();
    object1.fun(7);
    object1.fun(8.25);
    object1.fun(10,10);

    return 0;
}