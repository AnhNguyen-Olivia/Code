#include <iostream>
using namespace std;

// This file demonstrates how to pass an argument by reference
// and how to modify the argument in the caller's scope.

// Originally, the function was declared as void:
// void incrementByRef(int &);
// Here, we change the function signature to return int
// and return the modified value.
int incrementByRef(int &);

int main()
{
    int z = 9;
    cout << "z = " << z << " before incrementByRef\n"; // Print the value of z before calling the function
    incrementByRef(z); // Call the function to increment z by 10
    // The function modifies the value of z in the caller's scope
    cout << "z = " << z << " after incrementByRef\n"; // Print the value of z after calling the function
}

// Note: You cannot overload functions distinguished by return type alone in C++.
// Either remove the return type, change the function name, or change the parameter type to pass by value.
int incrementByRef(int &a)
{
    return a += 10; // Increment 'a' by 10 and return the new value
    // The caller's argument is modified directly
}

/* 
  This program demonstrates pass-by-reference in C++.

  How it works:
  -------------
  1. Variable Initialization:
     - An integer variable z is initialized to 9.

  2. Before Function Call:
     - The value of z is printed: "z = 9 before incrementByRef"
     - The function incrementByRef(z) is called.

  3. Inside the Function:
     - z is passed by reference, so any changes to 'a' inside the function affect z in main.
     - The statement a += 10 increases z by 10 (z becomes 19).
     - The function returns the new value (19), but the return value is not used in main.

  4. After Function Call:
     - The value of z is printed again: "z = 19 after incrementByRef"

  Key Points:
  -----------
  - The function modifies the caller’s variable directly because it uses a reference parameter (int &a).
  - The return value is not used in this code, but the function does return the new value of z.
  - You cannot overload functions based only on return type in C++.

  Summary:
  --------
  Passing by reference allows a function to modify a variable in the caller’s scope.
*/

