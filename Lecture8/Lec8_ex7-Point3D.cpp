#include <iostream>              // Include the standard input/output stream library
using namespace std;             // Use the standard namespace

class Point {
    protected:
        int x, y;                // Protected integer members for coordinates x and y
    public:
        Point()
        {
            x=0;                 // Initialize x to 0
            y=0;                 // Initialize y to 0
        }
};

class Point3D: public Point {     // Point3D inherits from Point
    protected:
        int z;                  // Additional protected integer member for z coordinate
    public:
        Point3D()
        {
            z=0;                 // Initialize z to 0
        }
};

main() 
{
    Point3D *cp=new Point3D;     // Dynamically allocate a Point3D object and assign its address to cp
    Point3D *cp1;                // Declare a pointer to Point3D, not initialized yet
    Point *p;                    // Declare a pointer to Point (base class)
    p=cp;                        // Assign the address of the Point3D object to the Point pointer (upcasting)
    cp1= (Point3D*) p;           // Cast the Point pointer back to Point3D pointer (downcasting)
}

/*

This program demonstrates the concepts of **inheritance** and **pointer casting** in C++ using simple 2D and 3D point classes.

-------------------------------
Explanation of the Program
-------------------------------

#include <iostream>              // Includes the standard input/output library
using namespace std;             // Uses the standard namespace

// Base class representing a 2D point
class Point {
    protected:
        int x, y;                // Coordinates x and y (protected, accessible in derived classes)
    public:
        Point()
        {
            x=0;                 // Initializes x to 0
            y=0;                 // Initializes y to 0
        }
};

// Derived class representing a 3D point, inherits from Point
class Point3D: public Point {
    protected:
        int z;                  // Adds a z coordinate for 3D
    public:
        Point3D()
        {
            z=0;                 // Initializes z to 0
        }
};

/*
    main() demonstrates:
    ---------------------
    - Creating a Point3D object dynamically.
    - Assigning its address to a Point3D* pointer (cp).
    - Upcasting: Assigning the Point3D* to a Point* pointer (p). This is safe because every Point3D is a Point.
    - Downcasting: Casting the Point* pointer back to a Point3D* pointer (cp1). This is only safe if p actually points to a Point3D object, as it does here.

    Code:
    -----
    Point3D *cp = new Point3D;   // Dynamically allocates a Point3D object, cp points to it
    Point3D *cp1;                // Declares a pointer to Point3D (not initialized)
    Point *p;                    // Declares a pointer to Point (base class)
    p = cp;                      // Upcasting: assigns Point3D pointer to Point pointer (safe)
    cp1 = (Point3D*) p;          // Downcasting: casts Point pointer back to Point3D pointer (must be careful)

-------------------------------
Summary
-------------------------------
- The program shows how inheritance allows a derived class (Point3D) to be treated as its base class (Point) via pointers.
- It also demonstrates how you can cast pointers back and forth between base and derived types.
- This is a fundamental concept in object-oriented programming in C++.
- **Upcasting** (derived to base) is always safe.
- **Downcasting** (base to derived) is only safe if the object is actually of the derived type.

*/