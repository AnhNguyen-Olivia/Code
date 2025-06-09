#include <iostream>
using namespace std;

void display (int x) { 
  cout << "Int!!!\n"; 
} // version 1

void display (float y) { 
  cout << "Float!!!\n"; 
}  // version 2

int main() {
  int i = 0;
  float f = 0.0;
  double d = 0.0;
  display(i); // version 1
  display(f); // version 2
  // uncomment the below to see the effect
  //display(d); // do not know which one!!!
  //display(0.0);
}
