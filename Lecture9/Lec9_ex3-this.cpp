#include <iostream>                // Include the standard input/output stream library
using namespace std;               // Use the standard namespace to simplify code

// Definition of the Point class
class Point {
private:
  int x, y;                       // Private member variables for x and y coordinates

public:
  Point() {}                      // Default constructor (does not initialize x and y)

  // Parameterized constructor to initialize x and y
  Point(int x, int y) {
    this->x = x;                  // Use 'this' pointer to assign parameter x to member variable x
    this->y = y;                  // Use 'this' pointer to assign parameter y to member variable y
  }

  // Member function to display the coordinates of the point
  void display() {
    cout << "X = " << x << ", Y = " << y << endl; // Output the values of x and y
  }
};

int main() {                      // Main function: program execution starts here
  Point p(1, 2);                  // Create a Point object 'p' with x=1 and y=2 using the parameterized constructor
  p.display();                    // Call the display method to print the coordinates of 'p'
}

/*
Program Explanation:

- The program defines a class 'Point' to represent a point in 2D space.
- The class has two private integer members: x and y.
- There are two constructors:
    1. A default constructor that does nothing.
    2. A parameterized constructor that uses the 'this' pointer to distinguish between member variables and parameters.
- The 'display' member function prints the coordinates of the point.
- In 'main', a Point object is created with coordinates (1, 2) and its values are displayed.

Expected Output:
X = 1, Y = 2
*/