#include <iostream> // Include the standard input/output stream library
using namespace std; // Use the standard namespace

// Define a function template for indexOf, which works with any type T
template <class T>

// Function to find the index of searchVal in the array table of size 'size'
long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++) // Loop through each element in the array
    if (searchVal == table[i])        // If the current element matches searchVal
      return i;                       // Return the index where it was found
  return -1;                          // If not found, return -1
}

int main() {
  const unsigned iCount = 10, fCount = 5; // Define sizes for integer and float arrays

  // Initialize an integer array with 10 elements
  int iTable[iCount] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

  // Initialize a float array with 5 elements
  float fTable[fCount] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

  // Find the index of 20 in iTable and print the result
  cout << indexOf( 20, iTable, iCount )   << endl;

  // Find the index of 2.2f in fTable and print the result
  cout << indexOf( 2.2f, fTable, fCount ) << endl;  

  const unsigned sCount = 5; // Define size for string array

  // Initialize a string array with 5 names
  string names[sCount] = { "John","Mary","Sue","Dan","Bob" };

  // Find the index of "Dan" in names and print the result
  cout << indexOf( (string) "Dan", names, sCount ) << endl; 

  return 0; // Indicate successful program termination
}

/*
This program demonstrates the use of function templates in C++. It shows how to create a single generic function (`indexOf`) that can search for an element in arrays of different data types (such as int, float, and string).

Key learning objectives:

- **Templates:** By using `template <class T>`, the function can operate on any data type, making it highly flexible.
- **Generic Programming:** The same `indexOf` function is used to search for values in arrays of integers, floats, and strings, illustrating the power of generic programming.
- **Code Reusability:** Templates eliminate the need to write separate functions for each data type, promoting code reuse and reducing redundancy.
- **Array Search Logic:** The program reinforces the concept of searching for an element in an array and returning its index, or `-1` if the element is not found.
- **Practical Example:** The main function provides practical examples of using the template function with different data types.

Overall, this program teaches how C++ templates enable you to write flexible, reusable, and type-independent code.
*/