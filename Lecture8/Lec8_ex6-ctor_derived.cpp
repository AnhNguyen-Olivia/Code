#include <iostream>                  // Provides input/output stream objects like cout
#include <string>                    // Provides the std::string class for string handling
using namespace std;                 // Allows direct access to standard library names

// Definition of the base class Student
class Student {
public:
  Student() {                       // Default constructor for Student
    cout << "Default Constructor of Student() called.\n";
  }
  Student(string name) {            // Parameterized constructor for Student
    cout << "Alternate Constructor of Student() called.\n";
    Student::name = name;           // Set the private member variable 'name'
  }
private:
  string name;                      // Stores the student's name (accessible only within Student)
};

// Definition of the derived class CSStudent, which inherits from Student
class CSStudent : public Student {
public:
  CSStudent(string name) {          // Parameterized constructor for CSStudent
    cout << "Alternate Constructor of CSStudent() called.\n";
    // Since there is no explicit call to Student(string name),
    // the default Student() constructor is called automatically
  }
};

// Entry point of the program
int main() {                        // Standard-compliant main function
  CSStudent aStudent("Nguyen Van A"); // Create a CSStudent object with the name "Nguyen Van A"
  // This triggers:
  // 1. Student's default constructor (prints a message)
  // 2. CSStudent's constructor (prints a message)
  return 0;                         // Indicate successful program termination
}

/*
Program Purpose:
----------------
Demonstrates how constructors are called in C++ inheritance.

Key Points:
-----------
- The Student class has:
    * A default constructor (prints a message)
    * A parameterized constructor (prints a message and sets the name)
- The CSStudent class inherits from Student and has its own parameterized constructor.

Constructor Call Sequence:
-------------------------
- When a CSStudent object is created with a name:
    * The default constructor of Student is called (since CSStudent does not explicitly call Student(string name))
    * Then, CSStudent's constructor is called

If you want the Student(string name) constructor to be called instead, you must use an initializer list in CSStudent's constructor:
    CSStudent(string name) : Student(name) { ... }

Expected Output:
----------------
Default Constructor of Student() called.
Alternate Constructor of CSStudent() called.
*/