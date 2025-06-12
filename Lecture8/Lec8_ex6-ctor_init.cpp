#include <iostream>      // Provides input/output stream objects like cout
#include <string>        // Provides the std::string class for string handling
using namespace std;     // Allows direct use of standard library names (like cout, string) without std:: prefix

// Definition of the Student class
class Student {
public:
  // Default constructor: called when no name is provided
  Student() { 
    cout << "Default Constructor of Student() called.\n"; 
    // Message indicates a Student object was created without a name
  }
  // Parameterized constructor: called when a name is provided
  Student(string name) { 
    cout << "Constructor of Student() called.\n"; 
    Student::name = name; // Assigns the provided name to the private member variable
  }
private:
  string name; // Stores the student's name (accessible only within Student)
};

// Definition of the CSStudent class, which inherits from Student
class CSStudent : public Student { // CSStudent is a derived class of Student
public:
  // Parameterized constructor for CSStudent
  CSStudent(string name) : Student(name) { // Passes 'name' to the Student constructor
    cout << "Constructor of CSStudent() called.\n"; 
    // Message indicates a CSStudent object was created
  }
};

// Main function: program entry point
main() { // Should be 'int main()', but some compilers accept this form
  CSStudent aStudent("Nguyen Van A"); // Creates a CSStudent object with the name "Nguyen Van A"
  // This triggers:
  //   1. Student(string) constructor (prints message)
  //   2. CSStudent(string) constructor (prints message)
}

/*

This program demonstrates constructor initialization and inheritance in C++.

Key Concepts:
- Inheritance: CSStudent inherits from Student, gaining its public and protected members.
- Constructor Chaining: Creating a CSStudent object first calls the Student constructor, then the CSStudent constructor.

Code Flow:
1. The program includes necessary headers and uses the standard namespace.
2. The Student class defines two constructors and a private name member.
3. The CSStudent class inherits from Student and passes its constructor argument to the Student constructor.
4. In main(), a CSStudent object is created, showing the order of constructor calls.

Expected Output:
Constructor of Student() called.
Constructor of CSStudent() called.

This illustrates how base and derived class constructors are called in order when creating derived class objects in C++.

*/