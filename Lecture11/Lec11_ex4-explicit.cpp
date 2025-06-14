#include <iostream>      // Include the standard input/output stream library
#include <cstring>       // Include the C string manipulation library

using namespace std;     // Use the standard namespace

// Template function to find the index of a value in an array
template <class T>
long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++)      // Loop through each element in the array
    if (searchVal == table[i])             // If the current element matches the search value
      return i;                            // Return the index
  return -1;                               // Return -1 if not found
}

// Overloaded function for searching C-style string arrays
long indexOf( const char * searchVal, char * table[], unsigned size ) {
  for(unsigned i = 0; i < size; i++)           // Loop through each string in the array
    if( strcmp(searchVal, table[i]) == 0 )     // Compare strings for equality
      return i;                                // Return the index if found
  return -1;                                   // Return -1 if not found
}

int main() {  
  const unsigned iCount = 10, nCount = 5;      // Define the sizes of the integer and string arrays
  int iTable[iCount] = { 0,10,20,30,40,50,60,70,80,90 }; // Initialize an integer array with 10 elements
  cout << indexOf( 20, iTable, iCount )  << endl; // Search for the value 20 in the integer array and print its index (should print 2)
  
  const char * names[nCount] = { "John", "Mary", "Sue", "Dan", "Bob" }; // Initialize an array of C-style strings
  const char * key = "Dan";                    // The string value to search for in the names array
  cout << indexOf( key, names, nCount ) << endl; // Search for "Dan" in the names array and print its index (should print 3)
  
  return 0;                                    // Indicate successful program termination
}//ex4-expicit.cpp

/*
This code demonstrates the use of function templates and function overloading in C++.

Key Concepts Illustrated:

1. Function Templates:
   - The template function `indexOf` allows searching for the index of a value in an array of any type (e.g., int, double).
   - This shows how templates enable writing generic, reusable code.

2. Function Overloading for Special Cases:
   - There is a specialized (overloaded) version of `indexOf` for arrays of C-style strings (`char*[]`).
   - This is necessary because comparing C-style strings with `==` only compares their addresses (pointers), not their contents.
   - The overloaded function uses `strcmp` to compare the actual string values.

3. Practical Usage:
   - In `main()`, the code demonstrates using the template for an integer array and the overloaded function for a C-style string array.

Takeaways:
- Use templates to write generic code that works for many types.
- Provide overloads for types that require special handling (like C-style strings).
- Understand the difference between comparing values (e.g., integers) and comparing pointers (e.g., C-style strings) in C++.
*/