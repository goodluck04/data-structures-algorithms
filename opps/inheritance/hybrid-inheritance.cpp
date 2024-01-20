#include <iostream>
using namespace std;

// when more than one child class inherit the same parent class


class Car {

    public:
    string name;
    string color;
    int engineHP;

    Car() {
        // defalt constructor
    }

    Car(string name,string color, int engineHP){
        this->name=name;
        this->color=color;
        this->engineHP=engineHP;
    }

    void drive(){
        cout << name << " Car is driving\n";
    }

};


class FlyingCar : public Car {
    public:
    bool wings;
    FlyingCar(){

    }

    FlyingCar(string name,string color, int engineHP){
        this->name=name;
        this->color=color;
        this->engineHP=engineHP;
        this->wings=true;
    }

    void fly(){
        cout << name << " Car is flying\n";
    }
};


// its multi-level inheriatance
class HydroFlyingCar: public Car {
    public:

    HydroFlyingCar(){

    }

    HydroFlyingCar(string name,string color, int engineHP){
        this->name=name;
        this->color=color;
        this->engineHP=engineHP;
    }

    void swim() {
        cout << name << " Car is trsvelling on the surface of water\n";
    }
};


int main(){
    // Car c1("Maruti", "White", 2000);

    // c1.drive();
    
    FlyingCar f1("SuperHyundai", "green", 5000);
    // cout << f1.wings << endl;

    f1.drive();
    f1.fly();

    HydroFlyingCar h1("SuperHyderaCar", "blue", 6000);

    h1.drive();
    
    h1.swim();

}