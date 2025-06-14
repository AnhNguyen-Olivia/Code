#include <iostream> // Include the input/output stream library

// Define a function template for swapping two variables of any type T
template <class T>
void swap(T & x, T & y) {
  T temp;   // Create a temporary variable of type T
  temp = x; // Store the value of x in temp
  x = y;    // Assign the value of y to x
  y = temp; // Assign the value of temp (original x) to y
}

// Define a Student class
class Student {
  unsigned idNum; // Private member variable to store student ID
public:
  // Constructor with a default parameter value
  Student (unsigned id = 0) {
    idNum = id; // Initialize idNum with the given id
  }

  // Public member function to get the student ID
  int getId() { return idNum; }
};

int main() {
  int m = 10, n = 20; // Declare and initialize two integers
  Student s1(1234), s2(5678); // Create two Student objects with IDs

  // Print the values of m and n before swapping
  std::cout << "m = " << m << ", n = " << n << std::endl;

  swap(m, n); // Call the swap template function with integers

  // Print the values of m and n after swapping
  std::cout << "m = " << m << ", n = " << n << std::endl;

  // Print the IDs of the two Student objects before swapping
  std::cout << s1.getId() << ", " << s2.getId() << std::endl;

  swap( s1, s2 );   // Call the swap template function with Student objects

  // Print the IDs of the two Student objects after swapping
  std::cout << s1.getId() <<", " << s2.getId() << std::endl;

  return 0; // Indicate successful program termination
}

/*

This program demonstrates the use of function templates in C++. It shows how a single generic swap function can be written to work with any data type, including both built-in types (like int) and user-defined types (like the Student class).

Key concepts illustrated:

- Templates: The swap function is defined as a template, enabling it to operate on any type T, making the code reusable and type-independent.
- Pass by reference: The swap function uses references to modify the original variables directly, rather than working on copies.
- User-defined types: The program proves that templates can be used with custom classes, as long as the required operations (like assignment) are supported by the class.
- Testing and output: The program swaps both integers and Student objects, printing their values before and after each swap to clearly show the effect.

Overall, this example teaches how templates in C++ allow for flexible, reusable, and type-safe code that works with a wide variety of data types.

*/