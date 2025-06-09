#include <iostream>

template <class T>
class S {
  T x;
public:
  S(const T & xx) { x = xx; }

  static double something_relevant;
  void display() {
    std::cout << "x = " << x << ", st = " << something_relevant << "\n";
  }
};

template <class T>
double S<T>::something_relevant = 1.5;

int main() {
  S<int> a(10);
  a.display();
  return 0;
}
