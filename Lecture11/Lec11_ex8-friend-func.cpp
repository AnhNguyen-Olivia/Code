#include <iostream>      // Include input/output stream library for cout
#include <cstring>       // Include C string manipulation functions
using namespace std;     // Use the standard namespace

class Student;           // Forward declaration of Student class

// Employee class definition
class Employee { 
  enum { idMax = 9 };    // Maximum length for Employee ID (9 characters)
  char id[idMax + 1];    // Character array to store Employee ID (+1 for null terminator)
  float payRate;         // Employee's pay rate
public:
  Employee(const char * idVal ); // Constructor to initialize Employee ID
  friend void hireStudent( Student & s, Employee & e, float rate); // Friend function declaration
  void display() {       // Member function to display Employee info
    cout << "id = " << id << ", payRate = " << payRate << endl;
  }
};

// Student class definition
class Student {  
  enum { idMax = 7 };    // Maximum length for Student ID (7 characters)
  char id[idMax+1];      // Character array to store Student ID (+1 for null terminator)
  int  employed;         // Employment status: 1 = employed, 0 = not employed
  // NOTE:
  // 'employed' is a private member of Student.
  // Only Student's member functions and friend functions can access it.
  // If you try to access 'employed' directly from outside the class (e.g., s.employed in main),
  // you will get an error: "member 'Student::employed' is inaccessible".
  // In this program, 'hireStudent' is a friend function, so it can access 'employed' directly.
public:
  Student(const char * idVal ); // Constructor to initialize Student ID
  //friend void hireStudent( Student & S, Employee & E, float rate ); // Not needed, already friend in Employee
  void display() {       // Member function to display Student info
    cout << "id = " << id << ", employment status = " << employed << endl;
  }
};

// Employee constructor implementation
Employee::Employee(const char * idVal ) {  
  strncpy( id, idVal, idMax); // Copy up to idMax characters from idVal to id
  id[idMax] = '\0';           // Ensure null-termination
  payRate = 0.0;              // Initialize payRate to 0.0
}

// Student constructor implementation
Student::Student(const char * idVal ) {  
  strncpy( id, idVal, idMax ); // Copy up to idMax characters from idVal to id
  id[idMax] = '\0';            // Ensure null-termination
  employed = 0;                // Initialize employed status to 0 (not employed)
}

// Friend function definition: can access private members of both Employee and Student
void hireStudent( Student & s, Employee & e, float rate )  {
  s.employed = 1;      // Set student's employed status to 1 (employed)
  e.payRate = rate;    // Set employee's pay rate
}

int main() {  
  Employee e( "333445555" ); // Create Employee object with ID "333445555"
  Student s( "1234567" );    // Create Student object with ID "1234567"
  hireStudent( s, e, 12.5 ); // Hire the student and set employee's pay rate to 12.5
  e.display();               // Display Employee info
  s.display();               // Display Student info
  return 0;                  // End of program
}//lec11_ex8-friend-func.cpp

/*
This program demonstrates the concept of friend functions in C++.

Key Concepts Illustrated:

1. Friend Functions:
   - The function `hireStudent` is declared as a friend inside the `Employee` class.
   - This allows `hireStudent` to access private members of both the `Employee` and `Student` classes, even though it is not a member of either class.

2. Encapsulation with Controlled Access:
   - Normally, private data members are inaccessible from outside their class.
   - By declaring a function as a friend, you can grant it special access to private data, enabling controlled interaction between classes.

3. Practical Example:
   - The program simulates hiring a student as an employee.
   - `hireStudent` sets the student's employment status and the employee's pay rate, showing how a friend function can coordinate changes between two classes.

4. Good Class Design:
   - The use of private data members, constructors, and display functions demonstrates encapsulation and proper class structure.

Summary:
Friend functions are useful when you need to allow specific external functions access to the private data of multiple classes, enabling cooperation between classes while still maintaining encapsulation and data protection.
*/