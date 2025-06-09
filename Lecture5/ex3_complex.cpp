#include<iostream>
using namespace std;
class Complex 
{
public: 
    double real;
    double imaginary;

public:
	Complex(){	real = 0; imaginary = 0;	}
    Complex(double r, double i);    
    // addition
    Complex operator+(Complex c2);
};
Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}
Complex Complex::operator+(Complex c2) 
{
    Complex result;
    result.real =real + c2.real;
    result.imaginary =imaginary + c2.imaginary;
    return result;
}
main() {
    Complex y;
    Complex z(3,7);
    Complex sum;
    y = Complex(2, 4);
    //z = Complex(3, 5);

    sum = y+z;
	cout<<"Sum is: "<<sum.real<<"+j"<<sum.imaginary<<endl;
  
    return 0;
}
