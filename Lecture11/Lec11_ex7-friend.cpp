#include <iostream>
#include <string>
using namespace std;

class Student; // Forward declaration

class Employee {
    string id;        // Employee ID
    float payRate;    // Employee pay rate
public:
    Employee(const string& idVal, float rate = 0.24f)
        : id(idVal), payRate(rate) {} // Use initialization list

    void display() const {
        cout << "Employee ID: " << id << "\nPay Rate: " << payRate << endl;
    }

    friend class Student; // Student can access private members
};

class Student {
    string id;      // Student ID
    bool employed;  // Employment status
public:
    Student(const string& idVal = "", bool emp = false)
        : id(idVal), employed(emp) {}

    // Student can access Employee's private members
    void showEmployeeInfo(const Employee& e) const {
        cout << "[Student Access]\n";
        cout << "Employee ID: " << e.id << "\nPay Rate: " << e.payRate << endl;
    }
};

int main() {
    Employee e("333445555", 0.30f); // Create Employee with custom pay rate
    Student s("S1234567", true);    // Create Student with ID and employment status

    cout << "Employee info (via Employee):" << endl;
    e.display();

    cout << "\nEmployee info (via Student):" << endl;
    s.showEmployeeInfo(e);

    return 0;
}
/*
Improvements:
- Uses std::string for safer and easier string handling.
- Adds display functions for better encapsulation.
- Demonstrates friend class access in a clearer way.
- Adds more meaningful constructors and output.
*/