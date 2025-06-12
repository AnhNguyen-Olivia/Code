#include <iostream>              // Include input/output stream library for cout, etc.
#include <string>                // Include string library for using std::string
using namespace std;             // Use the standard namespace to avoid std:: prefix

// Define a Student class
class Student {
private:
  string name;                   // Student's name
  unsigned age;                  // Student's age
  unsigned majorCode;            // Student's major code
public:
  void setAge(unsigned n) { age = n; }             // Set the student's age
  unsigned getAge() const { return age; }          // Get the student's age
  void setMajor(unsigned m) { majorCode = m; }     // Set the student's major code
  unsigned getMajor() const { return majorCode; }  // Get the student's major code
};

// Define an Employee class
class Employee {
private:
  unsigned age;                  // Employee's age
  void setAge(unsigned n) { age = n; }             // Set the employee's age (private)
  unsigned getAge() const {                        // Get the employee's age (private)
    cout << "Employee's age is " << age << endl;   // Print employee's age
    return age; 
  }
};

// Define a Salaried class, inheriting privately from Employee
class Salaried : private Employee {
private:
  float salary;                  // Salary of the employee
public:
  float getSalary() const { return salary; }       // Get the salary
  void setSalary(float s) { salary = s; }          // Set the salary
};

// Define a GradAssistant class, inheriting publicly from Student and Salaried
class GradAssistant : public Student, public Salaried {
public: 
  void display() const {                           // Display major code and salary
    cout << "Major Code: " << getMajor() << ", Salary: " << getSalary() << endl;
  }
};

int main() {
  GradAssistant gA;            // Create a GradAssistant object
  // Uncomment the below statement to see the effect
  //gA.setAge(25);             // This would call Student::setAge (not Employee's, which is private)
  gA.setSalary(850);           // Set the salary to 850 USD
  gA.setMajor(1010);           // Set the major code to 1010
  gA.display();                // Display the major code and salary
  return 0;                    // End of program
}

/*
This program demonstrates multiple inheritance and access control in C++ using a scenario with students, employees, and graduate assistants.

Key Concepts Demonstrated:

1. Classes and Encapsulation:
   - Four classes are defined: Student, Employee, Salaried, and GradAssistant.
   - Each class manages its own data and provides methods to interact with that data.

2. Access Specifiers:
   - private: Members are accessible only within the class itself.
   - public: Members are accessible from outside the class.

3. Inheritance:
   - Salaried inherits privately from Employee. This means Employee's public and protected members become private in Salaried.
   - GradAssistant inherits publicly from both Student and Salaried, so it can access their public members.

Class Details:

- Student:
  - Stores a student's name, age, and major code.
  - Provides public methods to set and get age and major code.

- Employee:
  - Stores an employee's age.
  - Methods to set and get age are private, so only Employee itself can use them.

- Salaried:
  - Inherits privately from Employee, so Employee's members are not accessible to further derived classes.
  - Adds a salary attribute with public set/get methods.

- GradAssistant:
  - Inherits publicly from both Student and Salaried.
  - Adds a display() method to print the major code and salary.

Main Function Workflow:

- Creates a GradAssistant object.
- Sets the salary and major code using inherited methods.
- Calls display() to print the major code and salary.

Expected Output:
  Major Code: 1010, Salary: 850

Notes:
- The commented-out line gA.setAge(25); would call Student::setAge, not Employee::setAge, because Employee's setAge is private and inaccessible through Salaried or GradAssistant.
- This example shows how access specifiers and inheritance types affect which members are accessible in derived classes.
*/