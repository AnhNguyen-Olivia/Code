#include <iostream>
#include <cstring>
using namespace std;

class Student; 

class Employee { 
  enum { idMax = 9 };
  char id[idMax + 1];  // Id number
  float payRate;       // pay rate
public:
  Employee(const char * idVal );
  friend void hireStudent( Student & s, Employee & e, float rate);
  void display() {
    cout << "id = " << id << ", payRate = " << payRate << endl;
  }
};

class Student {  
  enum { idMax = 7 };
  char id[idMax+1];   // ID number
  int  employed;      // 1 = employed, 0 = not employed
public:
  Student(const char * idVal );
  //friend void hireStudent( Student & S, Employee & E, float rate );
  void display() {
    cout << "id = " << id << ", employment status = " << employed << endl;
  }
};


Employee::Employee(const char * idVal ) {  
  strncpy( id, idVal, idMax);
  id[idMax] = '\0';
  payRate = 0.0;
}

Student::Student(const char * idVal ) {  
  strncpy( id, idVal, idMax );
  id[idMax] = '\0';
  employed = 0;
}

// Global function that is a friend of both classes
void hireStudent( Student & s, Employee & e, float rate )  {
  s.employed = 1;
  e.payRate = rate;
}


int main() {  
  Employee e( "333445555" );
  Student s( "1234567" );
  hireStudent( s, e, 12.5 );
  e.display();
  s.display();
  return 0;
}//lec11_ex8-friend-func.cpp
