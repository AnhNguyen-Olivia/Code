#include <iostream>
using namespace std;

class Employee {
public:
  Employee() { cout << "Constructor of Employee() called.\n"; }
};

class SalariedEmployee : public Employee {
public:
  SalariedEmployee() { cout << "Constructor of SalariedEmployee() called.\n"; }
};

class ManagementEmployee : public SalariedEmployee {
public:
  ManagementEmployee() { 
    cout << "Constructor of ManagementEmployee() called.\n"; 
  }
};

main() {
  ManagementEmployee m;
}
