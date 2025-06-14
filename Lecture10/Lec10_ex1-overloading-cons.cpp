#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace

// Define a class named Point
class Point {
  int x, y; // Private data members for coordinates
public:
  // Constructor with default arguments
  Point (int xx = 0, int yy = 0) {
    x = xx; y = yy; // Initialize x and y
    cout << "Point Constructor.\n"; // Print message when constructor is called
  }
};

// Define a class named Figure
class Figure {
public:
  // Default constructor
  Figure() { 
    cout << "Default Constructor.\n"; // Print message when default constructor is called
  }
  // Constructor that takes a Point object as the center
  Figure(const Point & center) { 
    cout << "2nd Constructor.\n"; // Print message when this constructor is called
  }
  // Constructor that takes an array of Points and a count
  Figure(const Point vertices[], int count) {
    cout << "3rd Constructor.\n"; // Print message when this constructor is called
  }
};

int main() {
  Figure fig1[3]; // Create an array of 3 Figure objects (calls default constructor 3 times)
  Point center(25, 50); // Create a Point object with x=25, y=50 (calls Point constructor)
  Figure fig2(center); // Create a Figure object using the Point constructor (calls 2nd constructor)
  const int VCount = 5; // Define a constant for the number of vertices
  Point verts[VCount]; // Create an array of 5 Point objects (calls Point constructor 5 times)
  Figure fig3(verts, VCount); // Create a Figure object using the array and count (calls 3rd constructor)
  return 0; // End of program
}

/*
  This program demonstrates constructor overloading in C++ using two classes: Point and Figure.
  It shows how different constructors are called depending on how objects are created.

  Program Overview:
  -----------------
  - The Point class has a constructor that can take two integers (x and y coordinates), with default values of 0.
    Each time a Point object is created, it prints "Point Constructor."

  - The Figure class has three overloaded constructors:
      1. A default constructor (no arguments) that prints "Default Constructor."
      2. A constructor that takes a single Point object (used as a center), printing "2nd Constructor."
      3. A constructor that takes an array of Point objects and an integer (number of points), printing "3rd Constructor."

  In main():
  ----------
  - Creates an array of 3 Figure objects, calling the default constructor three times.
  - Creates a Point object with coordinates (25, 50), calling the Point constructor.
  - Creates a Figure object using the Point object as the center, calling the second Figure constructor.
  - Creates an array of 5 Point objects, calling the Point constructor five times.
  - Creates a Figure object using the array of Point objects and the count, calling the third Figure constructor.

  Purpose:
  --------
  This program helps visualize how constructor overloading works in C++ by printing messages
  each time a constructor is called, making it easy to see which constructor is used for each object.
*/