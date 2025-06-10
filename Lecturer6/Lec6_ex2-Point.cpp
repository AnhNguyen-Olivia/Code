#include <iostream>                // Includes the input/output stream library for cout.
#include <math.h>                  // Includes the math library (not used in this code).

using namespace std;               // Allows use of standard library names without 'std::'.

// Class to represent points

class Point {                      // Defines a class named Point.

private:
  int x;                           // Private integer member variable x.

public:
  int y;                           // Public integer member variable y.
  Point(){                         // Default constructor for Point.
      cout<<"Default constructor"<<endl; // Prints message when a Point is created.
  }
  /*
  Point(int xVal = 0, int yVal = 0) { // (Commented out) Constructor with default values.
    x = xVal;
    y = yVal;
  }
    */
  void setX(int xVal) { x = xVal; }   // Public method to set x.
  void setY(int yVal) { y = yVal; }   // Public method to set y.

  int getX() { return x; }            // Public method to get x.
  int getY() { return y; }            // Public method to get y.

};

main()                                // Main function (should be int main()).
{
  //Point figure[5];                   // (Commented out) Would create an array of 5 Points.
  Point p;                            // Creates a Point object p (prints constructor message).
  p.setX(300);                        // Sets p's x to 300.
  p.setY(500);                        // Sets p's y to 500.
  cout << "x = " << p.getX() << endl; // Prints p's x value.
  cout << "y = " << p.y << endl;      // Prints p's y value directly.

}

/*
==========================
  Program Explanation
==========================

This program demonstrates the basics of defining and using a simple C++ class called `Point`.

---------------------------------
Class Definition: Point
---------------------------------
- Members:
    - `x` (private): Integer, only accessible through setter/getter methods.
    - `y` (public): Integer, can be accessed directly.
- Methods:
    - Default constructor: Prints "Default constructor" when a Point object is created.
    - `setX(int)`: Sets the value of `x`.
    - `setY(int)`: Sets the value of `y`.
    - `getX()`: Returns the value of `x`.
    - `getY()`: Returns the value of `y`.

---------------------------------
Main Function
---------------------------------
- Creates a Point object `p` (triggers the constructor message).
- Sets `x` to 300 and `y` to 500 using the setter methods.
- Prints the value of `x` using the getter.
- Prints the value of `y` directly.

---------------------------------
Sample Output
---------------------------------
Default constructor
x = 300
y = 500

---------------------------------
Purpose
---------------------------------
- Shows how to define a class.
- Demonstrates use of constructors.
- Illustrates encapsulation and access control.
- Shows how to access class members in C++.

==========================
*/
