#include <iostream>                  // Includes the input/output stream library for using cout.
using namespace std;                 // Allows usage of standard library names without 'std::' prefix.

class AClass {                       // Defines a class named AClass.
public:
  int operator +(AClass &a) {        // Overloads the '+' operator for AClass objects.
    return  5;                       // Always returns 5 when '+' is used between two AClass objects.
  }
};

int main() {                         // Main function, program entry point.
  AClass a, b;                       // Declares two objects of type AClass: a and b.
  int i;
  i = a+b;                           // Uses overloaded '+' operator: calls a.operator+(b), result is 5.
  //i = a.operator +(b);             // Equivalent to the above line, but commented out.
  cout << i << endl;                 // Prints the value of i (which is 5) to the console.
}

/*
This program demonstrates the concept of operator overloading in C++. It provides a simple example to help you understand how to customize the behavior of operators for user-defined types (classes).

1. What is Operator Overloading?
Operator overloading allows you to redefine how operators (such as +, -, *, etc.) behave when used with objects of your own classes. This makes your classes more intuitive and easier to use, similar to built-in types.

2. How is the '+' Operator Overloaded?
In this example, the '+' operator is overloaded inside the class AClass by defining a special member function:
    int operator +(AClass &a) {
        return 5;
    }
- The function is named operator+.
- It takes another AClass object as a reference parameter.
- It always returns the integer 5, regardless of the objects' state.

3. How is the Overloaded Operator Used?
In the main() function:
    AClass a, b;
    int i;
    i = a + b;
- When a + b is written, it actually calls a.operator+(b).
- The overloaded operator returns 5, so i becomes 5.

4. What is the Output?
The program prints the result:
    cout << i << endl; // Outputs: 5

5. Key Learning Points
- Syntax: How to declare and define an overloaded operator in a class.
- Usage: How overloaded operators are used just like built-in operators.
- Flexibility: The overloaded operator can perform any logic you define (here, it simply returns 5 for demonstration).

6. Why Always Return 5?
The function always returns 5 to keep the example simple and focused on the mechanics of operator overloading, not on any real calculation.

Summary:
This program teaches the basics of operator overloading in C++, showing how you can make operators work with your own classes in a way that is natural and easy to use.
*/