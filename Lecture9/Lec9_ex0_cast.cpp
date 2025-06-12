#include<stdio.h>                // Include the C standard input/output header
#include<iostream>               // Include the C++ standard input/output stream header
using namespace std;             // Use the standard namespace to avoid prefixing std::

int add(int a, int b);           // Function declaration: add two integers
double add(double a, double b);  // Function declaration: add two doubles

int add(int a, int b) {          // Function definition: add two integers
    return a + b;                // Return the sum of the integers
}

double add(double a, double b) { // Function definition: add two doubles
    return 1.0 + a + b;          // Return 1.0 plus the sum of the doubles (note: extra 1.0 added)
}

int main() {                     // Main function: program entry point
    cout << add(1.0, 1.0) << endl; // Call add with two doubles (1.0, 1.0), print result followed by newline
}

/*
This program demonstrates function overloading in C++. 
It defines two functions named 'add': 
    - One that takes two integers and returns their sum.
    - Another that takes two doubles and returns their sum plus 1.0.

In the main function, 'add' is called with two double values (1.0, 1.0). 
Because the arguments are doubles, the double version of 'add' is invoked, 
which returns 1.0 + 1.0 + 1.0 = 3.0. This result is printed to the console.

This example shows how C++ selects the correct overloaded function 
based on the types of the arguments provided in the function call.
*/

