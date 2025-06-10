#include <iostream>         // Includes the input/output stream library for using cout.
#include <math.h>           // Includes the math library (not used in this code).

using namespace std;        // Allows usage of standard library names without 'std::'.

// Class to represent points

class Point {               // Defines a class named Point.

private:
  int x, y;                // Private member variables to store x and y coordinates.

public:

  Point(int xVal = 0, int yVal = 0) { // Constructor with default values for x and y.
    x = xVal;                         // Sets x to xVal.
    y = yVal;                         // Sets y to yVal.
  }

  void setX(int xVal) { x = xVal; }   // Setter for x coordinate.
  void setY(int yVal) { y = yVal; }   // Setter for y coordinate.

  int getX() { return x; }            // Getter for x coordinate.
  int getY() { return y; }            // Getter for y coordinate.

};

main()                                // Main function (should be 'int main()').
{
  Point p, p2;                        // Creates two Point objects, p and p2.
  p.setX(300);                        // Sets the x coordinate of p to 300.
  cout << "x = " << p.getX() << endl; // Prints the x coordinate of p.
  p2 = p;                             // Copies p to p2 (member-wise copy).
}


/*
  This program demonstrates a simple Point class in C++ to represent a point in 2D space with integer coordinates.

  Features:
  - Defines a Point class with private members x and y.
  - Provides a constructor to initialize x and y (default is 0).
  - Includes setter and getter methods for both coordinates.

  In the main function:
  - Creates two Point objects: p and p2.
  - Sets the x coordinate of p to 300 using setX().
  - Prints the x coordinate of p to the console.
  - Copies the values of p into p2 using assignment.

  Output:
    x = 300

  Note:
  The main function should be declared as int main() and should return an integer value (usually return 0;).
*/