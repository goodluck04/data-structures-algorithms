#include <iostream>
using namespace std;
 
class Abstraction {
private:
    int a, b;
 
public:
    // method to set values of
    // private members
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
 
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class Vehicle
{
  private:
          void piston()
        {
            cout<<"4 piston\n";
        }
 
        void manWhoMade()
        {
            cout<<"Markus Librette\n";
        }
    public:
        void company()
        {
            cout<<"GFG\n";
        }
        void model()
        {
            cout<<"SIMPLE\n";
        }
        void color()
        {
            cout<<"Red/GREEN/Silver\n";
        }
        void cost()
        {
            cout<<"Rs. 60000 to 900000\n";
        }
        void oil()
        {
            cout<<"PETRO\n";
        }
};
 
int main()
{
    Abstraction obj;
    obj.set(10, 20);
    obj.display();

    Vehicle obj1;
    obj1.company();
    obj1.model();
    obj1.color();
    obj1.cost();
    obj1.oil();

    // abstracted
    // obj1.piston();
    // obj1.manWhoMade();
    return 0;
}