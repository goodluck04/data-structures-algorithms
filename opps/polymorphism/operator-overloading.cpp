#include <iostream>
using namespace std;

class Complex{
    private:
    double real;
    double imaginary;
    public:

    // constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // getter functions
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // overloading binary  + operator for additon
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    // overloading binary  - operator for additon
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }
    // overloading binary  + operator for additon
    Complex operator*(const Complex& other) const {
        double realPart = (real* other.real) - (imaginary* other.imaginary);
        double imaginaryPart = (real* other.imaginary) - (imaginary* other.real);
        return Complex(realPart, imaginaryPart);
    }

    // overloading == for equality
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // overloading unary - operator for negative
    Complex operator-() const {
        return Complex(-real, -imaginary);
    }

      // Overloading << operator for stream output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

};


std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImaginary() << "i";
    return os;
}


int main() {
    Complex c1(2.0, 3.0);
    Complex c2(1.5, 2.5);

    // Using overloaded operators
    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    bool isEqual = (c1 == c2);

    // Outputting results
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "c1 is equal to c2: " << (isEqual ? "true" : "false") << endl;
    cout << "Negation of c1: " << -c1 << endl;

    return 0;
}