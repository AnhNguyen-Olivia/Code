#include <iostream>
using namespace std;

class Point {
  int x, y;
};

class Shape {
public:
  virtual ~Shape() {}
  virtual void draw() const = 0;
  virtual void moveTo(int x2, int y2) = 0;
  virtual void rotate(int degree) {
  };
};


class Circle : public Shape {
private:
  Point center;
  float radius;

public:
  Circle() {}
  Circle(const Point & aCenter, float aRadius) {};
  virtual ~Circle() {};
  virtual void draw() const { 
    cout << "Drawing a Circle!\n";
  }
  virtual void moveTo(int x2, int y2) {
    cout << "Moving a Circle!\n";
  }
  /*virtual void rotate(int degree) {
    cout << "Rotating a Circle!\n";
  }*/
};
 

class Polygon : public Shape {
private:
  Point center;
  Point * vertices; // array of Points
public:
  Polygon(){}
  Polygon(Point & aCenter, Point * verts);
  ////////////////////////////
  /*
    virtual void draw() const { 
    cout << "Drawing a Polygon!\n";
  }
  
  virtual void moveTo(int x2, int y2) {
    cout << "Moving a Polygon!\n";
  } 
  
  virtual void rotate(int degree) {
    cout << "Rotating a Polygon!\n";
  }
  */
  ////////////////////////////
  virtual ~Polygon(){};
};

int main() {
  Circle c;
  c.draw();
  Point center;
  Point vertices[10];
  //Shape s;
  // Uncomment the below to see the effect that: Cannot create instance of abstract class Polygon
  //Polygon p(center, vertices);
  // HOW TO FIX?
  //Polygon x;
  //Polygon * p2=new Polygon(); // This is allowed
  //p2->draw();
  return 0;
}
