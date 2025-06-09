#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  string name;
  unsigned age;
public:
  virtual void setAge(unsigned n){age=n;};
  unsigned getAge() const { return age; }
};


class Student : public Person {
private:
  unsigned majorCode;
public:
  //#void setAge(unsigned n) { age = n; }	
  void setMajor(unsigned m) { majorCode = m; }
  unsigned getMajor() const { return majorCode; }
};

class Employee : public virtual Person {
	//void setAge(unsigned n) { age = n; }
};

class Salaried : public Employee {
private:
  float salary;
public:
  float getSalary() const { return salary; }
  void setSalary(float s) { salary = s; }
};

class GradAssistant : public Student, public Salaried {
public: 
  void display() const {
    cout << "Age: " << getAge() << ", Major Code: " << getMajor() << ", Salary: " << getSalary() << endl;
  }
};


int main() {
  GradAssistant gA;
  gA.setAge(25);
  gA.setSalary(850);// USD
  gA.setMajor(1010);
  gA.display();
  return 0;
}
