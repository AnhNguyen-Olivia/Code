#include <iostream> // Include the input/output stream library for console operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Define the base class Employee
class Employee {
public:
  Employee() { 
    cout << "Constructor of Employee() called.\n"; // Constructor prints a message when called
  }
};

// Define SalariedEmployee, which inherits from Employee
class SalariedEmployee : public Employee {
public:
  SalariedEmployee() { 
    cout << "Constructor of SalariedEmployee() called.\n"; // Constructor prints a message when called
  }
};

// Define ManagementEmployee, which inherits from SalariedEmployee
class ManagementEmployee : public SalariedEmployee {
public:
  ManagementEmployee() { 
    cout << "Constructor of ManagementEmployee() called.\n"; // Constructor prints a message when called
  }
};

// Main function, program entry point
main() {
  ManagementEmployee m; // Create a ManagementEmployee object, triggering all constructors in the inheritance chain
}


/*
This program demonstrates how constructor chaining works in C++ class inheritance.

How the program is structured:

1. There are three classes forming an inheritance chain:
   - Employee (base class)
   - SalariedEmployee (inherits from Employee)
   - ManagementEmployee (inherits from SalariedEmployee)

2. Each class has its own constructor, which prints a message when called.

3. In the main function, a ManagementEmployee object is created:
   - When this object is created, the constructors are called in order, starting from the base class up the inheritance chain:
     a. Employee constructor is called first.
     b. Then SalariedEmployee constructor.
     c. Finally, ManagementEmployee constructor.

4. The output will be:
   Constructor of Employee() called.
   Constructor of SalariedEmployee() called.
   Constructor of ManagementEmployee() called.

This output shows the order in which constructors are executed when an object of a derived class is created.  
It illustrates a key concept in object-oriented programming:  
**Base class constructors are always called before derived class constructors.**
*/