#include <iostream>
#include <string>
using namespace std;

class Student {
public:
  Student() { cout << "Default Constructor of Student() called.\n"; }
  Student(string name) { 
    cout << "Alternate Constructor of Student() called.\n"; 
    Student::name = name;
  }
private:
  string name;
};

class CSStudent : public Student {
public:
  CSStudent(string name) {
    cout << "Alternate Constructor of CSStudent() called.\n"; 
  }
};


main() {
  CSStudent aStudent("Nguyen Van A");
}
