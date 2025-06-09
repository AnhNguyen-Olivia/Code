#include <iostream>
#include <cstring>
using namespace std;

class Employee {
  enum { idMax = 9 };
  char id[idMax + 1];  // Id number
  float payRate;
public: 
  Employee(const char * idVal ) {  
    strncpy( id, idVal, idMax);
    id[idMax] = '\0';
    payRate = 2.0;
    cout<<"Employee!"<<endl;
  }
  friend float calcPay(Employee &e);
};


class SalariedEmployee : public Employee { 
  float salary;
public:
  SalariedEmployee(const char * idVal) : Employee(idVal) {
    salary = 1000;
    cout<<"SalariedEmployee!"<<endl;
  }
};

//float calcPay(Employee & e) { return e.payRate; }
float calcPay(SalariedEmployee & s) { return s.salary; }



int main() {  
  //Employee e( "333445555" );
  SalariedEmployee s( "1234567" );
  //cout << calcPay(e) << endl;;
  cout << calcPay(s) << endl;;
  return 0;
}//Lec11_ex9-friend-func2.cpp
