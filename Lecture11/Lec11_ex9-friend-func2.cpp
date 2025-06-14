#include <iostream>      // Include input/output stream library
#include <cstring>       // Include C string manipulation functions
using namespace std;     // Use the standard namespace

// Define the Employee class
class Employee {
  enum { idMax = 9 };    // Maximum length for id (9 characters)
  char id[idMax + 1];    // Character array to store id (+1 for null terminator)
  float payRate;         // Pay rate for the employee
public: 
  // Constructor: initializes id and payRate
  Employee(const char * idVal ) {  
    strncpy( id, idVal, idMax); // Copy up to idMax chars from idVal to id
    id[idMax] = '\0';           // Ensure null-terminated string
    payRate = 2.0;              // Set default pay rate
    cout<<"Employee!"<<endl;    // Print message when Employee is constructed
  }
  // Declare calcPay as a friend function (can access private members)
  friend float calcPay(Employee &e);
};

// Define SalariedEmployee class, derived from Employee
class SalariedEmployee : public Employee { 
  float salary;                 // Additional member: salary
public:
  // Constructor: calls Employee constructor and sets salary
  SalariedEmployee(const char * idVal) : Employee(idVal) {
    salary = 1000;              // Set default salary
    cout<<"SalariedEmployee!"<<endl; // Print message when constructed
  }
};

// Friend function for Employee (commented out)
// float calcPay(Employee & e) { return e.payRate; }

// Overloaded calcPay for SalariedEmployee (not a friend, but can access public/protected members)
float calcPay(SalariedEmployee & s) { return s.salary; } 
// 'salary' is a private member of SalariedEmployee. 
// It cannot be accessed directly outside the class unless through a public method or a friend function.
// In this code, the non-friend function 'calcPay(SalariedEmployee & s)' tries to access it directly,
// which will cause a compiler error due to private access.

// Main function
int main() {  
  //Employee e( "333445555" );         // Create an Employee object (commented out)
  SalariedEmployee s( "1234567" );    // Create a SalariedEmployee object
  //cout << calcPay(e) << endl;;       // Print pay for Employee (commented out)
  cout << calcPay(s) << endl;;        // Print pay for SalariedEmployee
  return 0;                           // End program
}//Lec11_ex9-friend-func2.cpp


/*
This program demonstrates the concept of friend functions and access control in C++ classes, particularly in the context of inheritance.

Key Concepts Illustrated:

1. Friend Functions and Private Member Access:
   - The Employee class declares a friend function, calcPay(Employee &e), which allows that function to access its private members (such as payRate).
   - The commented-out implementation of calcPay for Employee would work because it is explicitly declared as a friend.

2. Inheritance and Access Control:
   - SalariedEmployee is derived from Employee and introduces a new private member, salary.
   - The function calcPay(SalariedEmployee &s) attempts to access the private member salary directly.
   - However, since this function is not a friend of SalariedEmployee and is not a member function, direct access to salary is not allowed. This results in a compiler error, demonstrating C++'s enforcement of access restrictions.

3. Encapsulation:
   - The program highlights the importance of encapsulation by showing that private members cannot be accessed from outside the class unless through a public method or a friend function.

4. Resolving Access Issues:
   - To access private members from outside the class, you must either:
     a) Declare the function as a friend of the class, or
     b) Provide a public getter method.

Summary:
- Friend functions can access private members only if they are explicitly declared as friends.
- Non-friend, non-member functions cannot access private members, even in derived classes.
- Attempting to do so results in a compiler error, reinforcing the principle of encapsulation in C++.
*/