#include <iostream>              // Include input/output stream library
#include <string>                // Include string library
using namespace std;             // Use the standard namespace

class Person {
public:
  string name;                   // Public member variable to store person's name
  unsigned age;                  // Public member variable to store person's age
public:
  virtual void setAge(unsigned n){age=n;}; // Virtual function to set age (can be overridden)
  unsigned getAge() const { return age; }  // Function to get age (read-only)
};

class Student : public virtual Person {            // Student class inherits from Person
private:
  unsigned majorCode;                     // Private member variable for major code
public:
  //#void setAge(unsigned n) { age = n; }	// (Commented out) Example of overriding setAge
  void setMajor(unsigned m) { majorCode = m; } // Function to set major code
  unsigned getMajor() const { return majorCode; } // Function to get major code
};

class Employee : public virtual Person {   // Employee class virtually inherits from Person
    //void setAge(unsigned n) { age = n; } // (Commented out) Example of overriding setAge
};

class Salaried : public Employee {         // Salaried class inherits from Employee
private:
  float salary;                           // Private member variable for salary
public:
  float getSalary() const { return salary; } // Function to get salary (read-only)
  void setSalary(float s) { salary = s; }    // Function to set salary
};

class GradAssistant : public Student, public Salaried { // GradAssistant inherits from Student and Salaried
public: 
  void display() const {                  // Function to display GradAssistant info
    cout << "Age: " << getAge()           // Output age
         << ", Major Code: " << getMajor()// Output major code
         << ", Salary: " << getSalary()   // Output salary
         << endl;
  }
};

int main() {
  GradAssistant gA;           // Create a GradAssistant object
  gA.setAge(25);              // Set age to 25
  gA.setSalary(850);          // Set salary to 850 USD
  gA.setMajor(1010);          // Set major code to 1010
  gA.display();               // Display GradAssistant's information
  return 0;                   // End of program
}

/*
==========================
Program Explanation (Improved)
==========================

This C++ program demonstrates the concepts of multiple inheritance and virtual inheritance, focusing on how to solve the "diamond problem" in object-oriented programming.

--------------------------
Class Structure Overview
--------------------------

1. Person Class
   - Base class for all others.
   - Public members: `name` (string), `age` (unsigned).
   - Provides a virtual function `setAge()` (can be overridden in derived classes).
   - Provides a getter `getAge()` for the age.

2. Student Class
   - Inherits from Person.
   - Adds a private member `majorCode` (unsigned).
   - Provides setter (`setMajor()`) and getter (`getMajor()`) for the major code.

3. Employee Class
   - Inherits **virtually** from Person.
   - Virtual inheritance ensures that only one instance of Person is present in the most derived class, solving the diamond problem.

4. Salaried Class
   - Inherits from Employee.
   - Adds a private member `salary` (float).
   - Provides setter (`setSalary()`) and getter (`getSalary()`) for the salary.

5. GradAssistant Class
   - Inherits from both Student and Salaried (multiple inheritance).
   - Because Employee uses virtual inheritance, only one Person base is shared.
   - Provides a `display()` function to print age, major code, and salary.

--------------------------
main() Function
--------------------------
- Creates a `GradAssistant` object.
- Sets the age, salary, and major code using the provided setters.
- Calls `display()` to print all information.

--------------------------
Key Concepts Demonstrated
--------------------------
- **Multiple Inheritance:** `GradAssistant` inherits from both `Student` and `Salaried`.
- **Virtual Inheritance:** Used in `Employee` to avoid duplicate `Person` base in the inheritance hierarchy (diamond problem).
- **Encapsulation:** Private data members with public getter/setter functions.
- **Polymorphism:** Virtual function `setAge()` allows derived classes to override age-setting behavior if needed.

--------------------------
Potential Error and Solution
--------------------------
- **Problem:** In the current code, `Student` inherits from `Person` non-virtually, while `Employee` inherits virtually. This means `GradAssistant` will have two `Person` subobjects: one from `Student` and one from the virtual inheritance chain through `Employee` and `Salaried`. This causes ambiguity when accessing members of `Person` (like `age`).
- **Solution:** To fix this, make `Student` inherit from `virtual Person` as well:
    class Student : public virtual Person { ... }
  This ensures there is only one `Person` base in `GradAssistant`, resolving ambiguity.

--------------------------