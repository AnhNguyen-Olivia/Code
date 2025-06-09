#include <iostream>
using namespace std;

class Point {
  int x, y;
public:
  Point (int xx = 0, int yy = 0) {
    x = xx; y = yy;
    cout << "Point Constructor.\n";
  }
};


class Figure {
public:
  Figure() { cout << "Default Constructor.\n"; }
  Figure(const Point & center) { 
    cout << "2nd Constructor.\n"; 
  }
  Figure(const Point vertices[], int count) {
    cout << "3rd Constructor.\n"; 
  }
};

int main() {
  Figure fig1[3];
  Point center(25, 50);
  Figure fig2(center);
  const int VCount = 5;
  Point verts[VCount];
  Figure fig3(verts, VCount);
  return 0;
}
