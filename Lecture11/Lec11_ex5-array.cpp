#include <iostream>      // Includes the standard input/output stream library.
#include <string>        // Includes the standard string library.

using namespace std;     // Allows usage of standard library names without 'std::' prefix.

template <class T>       // Declares a template class 'Array' for any type T.
class Array {
public:
  Array( unsigned sz );  // Constructor: creates an array of size 'sz'.
  ~Array();              // Destructor: cleans up memory.
  T & operator[]( unsigned i ); // Overloads [] to access elements by index.
private:
  T * values;            // Pointer to the array of type T.
  unsigned size;         // Stores the size of the array.
};

template<class T> Array<T>::Array( unsigned sz ) {  
  values = new T [sz];   // Allocates memory for 'sz' elements of type T.
  size = sz;             // Sets the size.
}

template<class T> T & Array<T>::operator[] ( unsigned i ) { 
  if( i >= size ) {      // Checks if index is out of bounds.
    cout << "ERROR: array index out of bound!!!\n"; // Prints error message.
    abort();             // Terminates the program.
  }
  return values[i];      // Returns reference to the element at index i.
}

template<class T> Array<T>::~Array() {  
  delete [] values;      // Destructor: releases the allocated memory.
}

int main() {  
  const unsigned numStudents = 2;         // Number of students.
  Array<int>     ages( numStudents );     // Array of ints for ages.
  Array<float>   gpas( numStudents );     // Array of floats for GPAs.
  Array<string>  names(numStudents);      // Array of strings for names.
  for(int j = 0; j < numStudents; j++) {  // Loop over students.
    // do whatever you want
    ages[j] = 20;                         // Sets each student's age to 20.
  }
  return 0;                              // Program ends.
} //Lec11_ex5-array.cpp

/*
This program demonstrates key C++ programming concepts using a simple, type-safe, dynamic array class template.

Key Concepts Illustrated:

1. Templates:
   - Shows how to define and use a generic class (Array<T>) that can store elements of any type (e.g., int, float, string).
   - Demonstrates the flexibility and reusability of template classes.

2. Dynamic Memory Management:
   - Allocates memory for arrays at runtime using 'new' in the constructor.
   - Properly releases memory using 'delete[]' in the destructor to prevent memory leaks.

3. Operator Overloading:
   - Overloads the [] operator to provide intuitive, array-like access to elements.
   - Includes bounds checking for safer access, printing an error and terminating if an invalid index is used.

4. Class Design and Encapsulation:
   - Encapsulates the array data and its size as private members.
   - Provides controlled access to elements through public methods.

5. Practical Usage Example:
   - In main(), demonstrates how to create and use arrays of different types (int, float, string) with the template class.
   - Shows how to assign values to array elements using the overloaded [] operator.

Overall, this program teaches how to build and use a simple, reusable, and type-safe dynamic array class in C++, while reinforcing best practices in memory management, operator overloading, and class design.
*/