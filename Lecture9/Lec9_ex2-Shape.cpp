#include <iostream> // Include the standard input/output stream library
using namespace std; // Use the standard namespace

// Define a simple Point class with private x and y coordinates
class Point {
  int x, y;
};

// Abstract base class Shape with pure virtual functions
class Shape {
public:
  virtual ~Shape() {} // Virtual destructor for proper cleanup of derived classes
  virtual void draw() const = 0; // Pure virtual function: must be implemented by derived classes
  virtual void moveTo(int x2, int y2) = 0; // Pure virtual function: must be implemented by derived classes
  virtual void rotate(int degree) { // Virtual function with default (empty) implementation
  };
};

// Circle class derived from Shape
class Circle : public Shape {
private:
  Point center; // Center of the circle
  float radius; // Radius of the circle

public:
  Circle() {} // Default constructor
  Circle(const Point & aCenter, float aRadius) {}; // Constructor with parameters
  virtual ~Circle() {}; // Virtual destructor
  virtual void draw() const { // Implementation of draw for Circle
    cout << "Drawing a Circle!\n";
  }
  virtual void moveTo(int x2, int y2) { // Implementation of moveTo for Circle
    cout << "Moving a Circle!\n";
  }
  /*virtual void rotate(int degree) {
    cout << "Rotating a Circle!\n";
  }*/
  // rotate is not overridden, so it uses the base class's (empty) implementation
};

// Polygon class derived from Shape
class Polygon : public Shape {
private:
  Point center; // Center of the polygon
  Point * vertices; // Pointer to array of Points (vertices)
public:
  Polygon(){} // Default constructor
  Polygon(Point & aCenter, Point * verts); // Constructor with parameters (not implemented here)
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
  // The above methods are commented out, so Polygon does NOT implement the pure virtual functions from Shape
  ////////////////////////////
  virtual ~Polygon(){}; // Virtual destructor
};

int main() {
  Circle c; // Create a Circle object
  c.draw(); // Call draw() on the Circle (prints "Drawing a Circle!")
  Point center; // Create a Point object for the center
  Point vertices[10]; // Create an array of 10 Points for vertices
  //Shape s; // Cannot instantiate abstract class Shape
  // Uncomment the below to see the effect that: Cannot create instance of abstract class Polygon
  //Polygon p(center, vertices); // Error: Polygon is abstract (doesn't implement all pure virtuals)
  // HOW TO FIX?
  //Polygon x; // Error: Polygon is abstract
  //Polygon * p2=new Polygon(); // This is allowed by the compiler, but calling pure virtuals will cause runtime error
  //p2->draw();
  return 0; // End of main function
}

/*
This program demonstrates the use of abstract classes and inheritance in C++.

- The base class `Shape` is abstract because it contains pure virtual functions (`draw` and `moveTo`).
- The derived class `Circle` implements all pure virtual functions, so objects of type `Circle` can be created and used.
- The derived class `Polygon` does NOT implement the pure virtual functions (the implementations are commented out), so `Polygon` remains abstract and cannot be instantiated.

In the `main()` function:
- A `Circle` object is created and its `draw()` method is called, which prints "Drawing a Circle!".
- The code (in comments) shows that you cannot create objects of `Shape` or `Polygon` because they are abstract.
- The comments also explain that attempting to instantiate `Polygon` or call its pure virtual functions will result in a compile-time or runtime error.

Purpose:
To illustrate how abstract classes and pure virtual functions work in C++, and to show what happens if a derived class does not implement all required methods.
*/