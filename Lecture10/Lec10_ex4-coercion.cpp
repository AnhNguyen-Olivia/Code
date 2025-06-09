#include <iostream>
using namespace std;

void print (float a, float b) {
  cout << "version 1\n";
}

void print(float a, int b) {
  cout << "version 2\n";
}

int main() {
  int i = 0, j = 0;
  float f = 0.0;
  double d = 0.0;
  print(i, j); // version 2
  print(i, f); // version 1
  print(d, f); // version 1 
  //print(d, 3.5);
  //print(i, 4.5);
  //print(d, 3.0);
  //print(i, d);
  print (d,float(3.5));	// version 1
  print (i,int(4.5));	// version 2
  print (d,float(3.0));	// version 1
  print (i,int(d));	// version 2

}
