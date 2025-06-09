#include <iostream>
#include <cstring>
using namespace std;

class Student;

class Employee { 
  char id[8];  // Id number
  float payRate;     // pay rate
public:
  Employee(const char * idVal ) {
    strcpy( id, idVal);
    id[7] =0;
    payRate = 0.24f;
  }
  
  friend class Student;
};

class Student { 
  char id[8];   // ID number
  int employed;
public:
  Student() { 
    id[0] = '\0';
    employed = 0;
  };

  void getE1() {
    Employee e("xxxxxxx");
    cout << e.id << endl << e.payRate << endl;  
  }
  
  void getE2(Employee & e) {
    cout << e.id << endl << e.payRate << endl;  
  }
};


int main() { 
  Employee e( "333445555" );
  Student s;
  s.getE1();
  s.getE2(e);
  return 0;
}// Lec11_ex7-friend.cpp
