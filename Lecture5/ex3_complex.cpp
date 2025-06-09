#include<iostream>
using namespace std; 

class Complex // Defines a class named Complex to represent complex numbers.
{
public: 
    double real; // Public data member to store the real part.
    double imaginary; // Public data member to store the imaginary part.

public:
    Complex(){ real = 0; imaginary = 0; } // Default constructor, initializes both parts to 0.
    Complex(double r, double i); // Parameterized constructor declaration.
    // addition
    Complex operator+(Complex c2); // Overloads the + operator for Complex addition.
};

Complex::Complex(double r, double i) // Definition of the parameterized constructor.
{
    real = r; // Sets the real part.
    imaginary = i; // Sets the imaginary part.
}

Complex Complex::operator+(Complex c2) // Definition of the + operator overload.
{
    Complex result; // Creates a temporary Complex object to store the result.
    result.real = real + c2.real; // Adds the real parts.
    result.imaginary = imaginary + c2.imaginary; // Adds the imaginary parts.
    return result; // Returns the result.
}

int main() { // Main function (should be 'int main()' in standard C++).
    Complex y; // Declares a Complex object y (initialized to 0,0).
    Complex z(3,7); // Declares and initializes z to (3,7).
    Complex sum; // Declares a Complex object sum (initialized to 0,0).
    y = Complex(2, 4); // Assigns (2,4) to y.
    //z = Complex(3, 5); // Commented out: would assign (3,5) to z.

    sum = y+z; // Adds y and z using the overloaded + operator, stores in sum.
    cout<<"Sum is: "<<sum.real<<"+j"<<sum.imaginary<<endl; // Prints the sum in a+jb form.
  
    return 0; // Returns 0 to indicate successful execution.
}

/*


*/