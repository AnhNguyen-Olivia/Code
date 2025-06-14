#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace

// Define a template function to find the index of a value in an array
template <class T>
long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++) // Loop through the array
    if (searchVal == table[i])        // If the value matches
      return i;                       // Return the index
  return -1;                          // Return -1 if not found
}

// Define a Student class
class Student {
  long id; // Private member variable to store student ID
public:
  Student( long idVal ) { id = idVal; } // Constructor to initialize id
  // Overload the == operator to compare Student objects by id
  int operator ==( const Student & s2 ) const {
    return id == s2.id;
  }
};

int main() {
  const unsigned sc = 5; // Number of students
  // Initialize an array of Student objects with different IDs
  Student sTable[sc] = { 10000, 11111, 20000, 22222, 30000 };
  Student s( 20000 ); // Create a Student object with id 20000
  // Find the index of student s in sTable and print it
  cout << indexOf( s, sTable, sc ) << endl;     // print "3"
  return 0; // End of program
}

/*
This program is designed to teach several important C++ concepts:

Templates:
The indexOf function is a template, meaning it can work with any data type, not just built-in types like int or double. This demonstrates generic programming in C++.

Operator Overloading:
The Student class overloads the == operator, allowing two Student objects to be compared based on their id values. This shows how to make user-defined types work with standard operators.

Searching Arrays of Objects:
The program shows how to search for an object in an array of objects using a generic function (indexOf) and operator overloading.

Encapsulation:
The id member of Student is private, showing how to protect data inside a class.

Object Initialization:
The array sTable is initialized with Student objects using their constructor.

Summary:
The main lesson is how to write reusable, type-independent code (with templates) that works with both built-in and user-defined types, provided the necessary operators (like ==) are defined for those types.


*/