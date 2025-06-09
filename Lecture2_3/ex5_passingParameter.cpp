#include <iostream>                
using namespace std;                 

int incrementByValue(int);           // Function prototype: pass by value
void incrementByPointer(int *);      // Function prototype: pass by pointer
void incrementByRef(int &);          // Function prototype: pass by reference
void incrementByConstRef(const int &); // Function prototype: pass by constant reference

main()                               // Main function (should be int main())
{
    int x = 5, y = 7, z = 9;         // Declare and initialize three integers

    cout << "x = " << x << " before incrementByValue\n" // Print x before function call
        << "Value returned by sqrByVal: "                // Print label for returned value
        << incrementByValue(x)                           // Call incrementByValue, print returned value
        << "\nx = " << x << " after incrementByValue\n\n"; // Print x after function call
    
    cout << "y = " << y << " before incrementByPointer\n"; // Print y before function call
    incrementByPointer(&y);                               // Call incrementByPointer, pass address of y
    cout << "y = " << y << " after incrementByPointer\n\n"; // Print y after function call
        
    cout << "z = " << z << " before incrementByRef\n";      // Print z before function call
    incrementByRef(z);                                      // Call incrementByRef, pass z by reference
    cout << "z = " << z << " after incrementByRef\n";       // Print z after function call

    cout << "z = " << z << " before incrementByConstRef\n"; // Print z before function call
    incrementByConstRef(z);                                 // Call incrementByConstRef, pass z by const reference
    cout << "z = " << z << " after incrementByConstRef\n";  // Print z after function call
}

int incrementByValue(int a)           // Function definition: pass by value
{
    return a += 10;                   // Add 10 to local copy and return it (original not changed)
    // caller's argument not modified
}

void incrementByPointer(int *bPtr)    // Function definition: pass by pointer
{
    *bPtr += 10;                      // Add 10 to the value pointed to (original is changed)
    // caller's argument modified
}

void incrementByRef(int &cRef)        // Function definition: pass by reference
{
    cRef += 10;                       // Add 10 to the reference (original is changed)
    // caller's argument modified
}

void incrementByConstRef(const int &cRef) // Function definition: pass by const reference
{
    //cRef += 10;                    // Attempt to modify would cause error (commented out)
    // caller's argument not modified
}

/*
===============================================================================
 Similarities
-------------------------------------------------------------------------------
- All functions are called with an integer argument.
- Each function attempts to add 10 to the value.
- All demonstrate how function arguments can be handled in C++.

===============================================================================
 Differences
-------------------------------------------------------------------------------
| Function                         | How Parameter is Passed         | Can Modify Original? | Syntax in Call             | Notes                                       |
|----------------------------------|---------------------------------|----------------------|----------------------------|---------------------------------------------|
| incrementByValue(int)            | By value (copy)                 |  No                	| incrementByValue(x)        | Works on a copy; original not changed.      |
| incrementByPointer(int*)         | By pointer (address)            |  Yes               	| incrementByPointer(&y)     | Uses * to access and modify original.       |
| incrementByRef(int&)             | By reference (alias)            |  Yes               	| incrementByRef(z)          | Directly modifies original variable.        |
| incrementByConstRef(const int&)  | By const reference (read-only)  |  No                	| incrementByConstRef(z)     | Cannot modify original; read-only access.   |

===============================================================================
 Summary
-------------------------------------------------------------------------------
- By value and by const reference cannot change the original variable.
- By pointer and by reference can change the original variable.
- By pointer requires passing the address (&), while by reference and by const
  reference use the variable name directly.
===============================================================================
*/



/*
===============================================================================
 Explanation of Code: Parameter Passing in C++
===============================================================================

This code demonstrates different ways to pass parameters to functions in C++:
by value, by pointer, by reference, and by constant reference.

-------------------------------------------------------------------------------
 1. Function Declarations
-------------------------------------------------------------------------------
- int incrementByValue(int);
    Passes an integer by value (makes a copy).
- void incrementByPointer(int *);
    Passes a pointer to an integer (can modify the original).
- void incrementByRef(int &);
    Passes an integer by reference (can modify the original).
- void incrementByConstRef(const int &);
    Passes an integer by constant reference (cannot modify the original).

-------------------------------------------------------------------------------
 2. Main Function
-------------------------------------------------------------------------------
- Declares three integers: x, y, z.
- Calls each function and prints the values before and after to show the effect
  of each parameter passing method.

    a. incrementByValue
        - incrementByValue(x) returns x + 10 but does NOT change x in main.
    b. incrementByPointer
        - incrementByPointer(&y) passes the address of y, so the function can
          modify y directly.
    c. incrementByRef
        - incrementByRef(z) passes z by reference, so the function can modify z
          directly.
    d. incrementByConstRef
        - incrementByConstRef(z) passes z by constant reference. The function
          cannot modify z (any attempt to do so is commented out).

-------------------------------------------------------------------------------
 3. Function Definitions
-------------------------------------------------------------------------------
- incrementByValue(int a): Returns a + 10, does not affect the original variable.
- incrementByPointer(int *bPtr): Adds 10 to the value pointed to by bPtr.
- incrementByRef(int &cRef): Adds 10 to cRef.
- incrementByConstRef(const int &cRef): Cannot modify cRef (code to do so is
  commented out).

-------------------------------------------------------------------------------
 4. Output
-------------------------------------------------------------------------------
- Shows which variables are changed by each function, illustrating the effects
  of different parameter passing methods.

-------------------------------------------------------------------------------
 5. Note
-------------------------------------------------------------------------------
- The main() function should have a return type of int for standard compliance.

===============================================================================
 Summary
-------------------------------------------------------------------------------
This code is a practical demonstration of how parameter passing works in C++
and how it affects the ability of functions to modify arguments.
===============================================================================
*/