#include <iostream>                   // Include the standard I/O stream library
using namespace std;                  // Use the standard namespace

const int MAXCOURSE = 40;             // Define a constant for the maximum number of courses

class Transcript {
  int count;                          // Number of courses in the transcript
  string * courses;                   // Pointer to a dynamic array of course names
public:
  Transcript();                       // Default constructor
  Transcript( const Transcript & T);  // Copy constructor
  Transcript & operator=(const Transcript & T); // Assignment operator
};

Transcript::Transcript() {
  cout << "Default Constructor \n";   // Print message when default constructor is called
  count=1;                            // Initialize count to 1
  courses = new string[MAXCOURSE];    // Allocate memory for courses array
}

Transcript::Transcript( const Transcript & T ) {
  count = T.count;                    // Copy the count from the source object
  courses = new string[MAXCOURSE];    // Allocate new memory for courses array
  for(unsigned i = 0; i < count; i++) // Copy each course from the source object
    courses[i] = T.courses[i];
  cout << "Copy Constructor.\n";      // Print message when copy constructor is called
}

Transcript & Transcript::operator =( const Transcript & T ) {  
  if( this != &T ) {                  // Check for self-assignment
      delete [] courses;              // Free previously allocated memory
      courses = new string[MAXCOURSE];// Allocate new memory for courses array
      count = T.count;                // Copy the count from the source object
      cout<<count;                    // Print the count
      for(int i = 0; i < count; i++)  // Copy each course from the source object
        courses[i] = T.courses[i];
  }
  cout << "= Operator\n";             // Print message when assignment operator is called
  return *this;                       // Return the current object by reference
}

int main() {
  Transcript T1;                      // Create T1 using default constructor
  Transcript T2( T1 );                // Create T2 as a copy of T1 (copy constructor)
  Transcript T4 = T1 ;                // Create T4 as a copy of T1 (copy constructor)
  Transcript T3;                      // Create T3 using default constructor
  T3 = T1;                            // Assign T1 to T3 (assignment operator)
  return 0;                           // End of program
}

/*

This code demonstrates the Rule of Three in C++ using a Transcript class that manages a dynamic array of course names.

Key features:
- The default constructor allocates memory for the courses array.
- The copy constructor creates a deep copy of another Transcript object, ensuring each object manages its own memory.
- The assignment operator handles self-assignment, releases old memory, and copies data from another Transcript object.

In main():
- Several Transcript objects are created using both the default and copy constructors.
- The assignment operator is used to copy one Transcript to another.
- Console output shows when each constructor or operator is called, helping to visualize object creation, copying, and assignment.

This example teaches safe dynamic memory management in C++ classes, preventing memory leaks and shallow copies.
*/