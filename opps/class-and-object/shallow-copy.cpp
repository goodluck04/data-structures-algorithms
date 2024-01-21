#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    // make setter function
    void setDimensions(int length1, int breadth1, int height1)
    {
        length = length1;
        breadth = breadth1;
        height = height1;
    }

    // make getter function to get the function
    void getDimensions()
    {
        cout << "Length: " << length << "\nBreath: " << breadth << "\nHeight: " << height << endl;
    }
};


int main(){
    // create object of class box
    Box B1, B3;

    // set dimensions
    B1.setDimensions(10,12,14);

    B1.getDimensions();

    // use COPY CONSTRUCTOR copy create and initialize the value of new class of box
    Box B2 = B1;
    B2.getDimensions();

    // copy data into exist objects using COPY ASSIGNMENT OPERATOR
    B3 = B1;
    // B1.setDimensions(0,0,0);
    // B1.getDimensions();
    B3.getDimensions();


}