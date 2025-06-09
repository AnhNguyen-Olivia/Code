#include <iostream>
using namespace std;

class Point {
private:
  int x, y;

public:
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void display() {
    cout << "X = " << x << ", Y = " << y << endl;
  }
};

int main() {
  Point p(1, 2);
  p.display();
}


