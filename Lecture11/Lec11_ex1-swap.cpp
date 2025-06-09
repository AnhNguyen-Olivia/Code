#include <iostream>

template <class T>
void swap(T & x, T & y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}


class Student {
  unsigned idNum;
public:
  Student (unsigned id = 0) {
    idNum = id;
  }

  int getId() { return idNum; }
};

int main() {
  int m = 10, n = 20;
  Student s1(1234), s2(5678);
  std::cout << "m = " << m << ", n = " << n << std::endl;
  swap(m, n); // call with integers
  std::cout << "m = " << m << ", n = " << n << std::endl;

  std::cout << s1.getId() << ", " << s2.getId() << std::endl;
  swap( s1, s2 );   // call with Students
  std::cout << s1.getId() <<", " << s2.getId() << std::endl;
  return 0;
}
