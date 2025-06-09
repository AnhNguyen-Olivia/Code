#include <iostream>
using namespace std;

class AClass {
public:
  int operator +(AClass &a) { return  5; }
};

int main() {
  AClass a, b; int i;
  i = a+b; 
  //i = a.operator +(b);
  cout << i << endl;
}
