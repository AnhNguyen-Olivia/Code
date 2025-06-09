#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  string name;
  unsigned age;
  unsigned majorCode;
public:
  void setAge(unsigned n) { age = n; }
  unsigned getAge() const { return age; }
  void setMajor(unsigned m) { majorCode = m; }
  unsigned getMajor() const { return majorCode; }
};

class Employee {
private:
  unsigned age;
  void setAge(unsigned n) { age = n; }
  unsigned getAge() const { 
    cout << "Employee's age is " << age << endl;
    return age; 
  }
};

class Salaried : private Employee {
private:
  float salary;
public:
  float getSalary() const { return salary; }
  void setSalary(float s) { salary = s; }
};

class GradAssistant : public Student, public Salaried {
public: 
  void display() const {
    cout << "Major Code: " << getMajor() << ", Salary: " << getSalary() << endl;
  }
};


int main() {
  GradAssistant gA;
  // Uncomment the below statement to see the effect
  //gA.setAge(25);
  gA.setSalary(850);// USD
  gA.setMajor(1010);
  gA.display();
  return 0;
}
