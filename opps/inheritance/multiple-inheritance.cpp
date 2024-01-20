#include <iostream>
using namespace std;

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


class FlyingCar : virtual public Car {
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

    void common(){
        cout << "Commom Hydro1\n";
    }
};




// its multi-level inheriatance
class HydroCar: virtual public Car {
    public:

    HydroCar(){

    }

    HydroCar(string name,string color, int engineHP){
        this->name=name;
        this->color=color;
        this->engineHP=engineHP;
    }

    void swim() {
        cout << name << " Car is travelling on the surface of water\n";
    }

// explicit overiding this method
    void common(){
        cout << "Commom Hydro2\n";
    }
};
// its multi-level inheriatance
class HydroFlyingCar: public FlyingCar, public HydroCar {
    public:

    HydroFlyingCar(){

    }

    HydroFlyingCar(string name,string color, int engineHP){
        this->name=name;
        this->color=color;
        this->engineHP=engineHP;
    }

    void hydroFly() {
        cout << name << " Car is travelling super fast on the surface of water\n";
    }

    void common() {
        // for overriding inherit from parent class
        // FlyingCar::common();
        // HydroCar::common();
        cout << "common of created\n";
    }
};


int main(){
    // Car c1("Maruti", "White", 2000);

    // c1.drive();
    
    // FlyingCar f1("SuperHyundai", "green", 5000);
    // cout << f1.wings << endl;

    // f1.drive();
    // f1.fly();

    // HydroCar h1("HydroCar", "blue", 6000);

    // h1.drive();
    // h1.swim();

    HydroFlyingCar hf1("SuperHydroCar", "black", 7000);
    hf1.drive();
    hf1.fly();
    hf1.swim();
    hf1.hydroFly();
    hf1.common();

    hf1.name = "goodluck";

    cout << hf1.name << endl;
   
};
