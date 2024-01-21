#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int* breadth;
    int height;

public:
    // constructor
    Box(){
        breadth = new int;
    }


    // make setter function
    void setDimensions(int length1, int breadth1, int height1)
    {
        length = length1;
        *breadth = breadth1;
        height = height1;
    }

    // make getter function to get the function
    void getDimensions()
    {
        cout << "Length: " << length << "\nBreath: " << *breadth << "\nHeight: " << height << endl;
    }

    // parametrized constructor for implementing deep copy
    Box(Box& sample){
        cout << "parametrized constructor called! during deep copy\n";
        length = sample.length;
        breadth = new int;
        *breadth = *(sample.breadth);
        height = sample.height;
    }

    // destructor
    ~Box(){
        cout << "Destructor called\n";
        delete breadth;
    }
};


int main(){
    // create object of class box
    Box B1, B3;

    // set dimensions
    B1.setDimensions(10,12,14);

    B1.getDimensions();
    B1.setDimensions(0,0,0);

    // use COPY CONSTRUCTOR copy create and initialize the value of new class of box
    Box B2 = B1;
    B2.getDimensions();


// copy assingment operator wont work for deep copy
    // B3 = B2;
    // B3.getDimensions();

    return 0;




}