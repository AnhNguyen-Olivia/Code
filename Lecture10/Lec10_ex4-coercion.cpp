#include <iostream>              // Include the input/output stream library
using namespace std;             // Use the standard namespace

// Function overload: takes two floats
void print (float a, float b) {
  cout << "version 1\n";        // Prints "version 1" if this overload is called
}

// Function overload: takes a float and an int
void print(float a, int b) {
  cout << "version 2\n";        // Prints "version 2" if this overload is called
}

int main() {
  int i = 0, j = 0;             // Declare and initialize two integers
  float f = 0.0;                // Declare and initialize a float
  double d = 0.0;               // Declare and initialize a double

  print(i, j);                  // Calls print(float, int): i promoted to float, j is int → version 2
  print(i, f);                  // Calls print(float, float): i promoted to float, f is float → version 1
  print(d, f);                  // Calls print(float, float): d demoted to float, f is float → version 1 

  //print(d, 3.5);              // Would call print(float, float): d demoted to float, 3.5 is double (demoted to float)
  //print(i, 4.5);              // Would call print(float, float): i promoted to float, 4.5 is double (demoted to float)
  //print(d, 3.0);              // Would call print(float, float): d demoted to float, 3.0 is double (demoted to float)
  //print(i, d);                // Would call print(float, float): i promoted to float, d demoted to float

  print (d, float(3.5));        // Calls print(float, float): d demoted to float, 3.5 explicitly cast to float → version 1
  print (i, int(4.5));          // Calls print(float, int): i promoted to float, 4.5 explicitly cast to int → version 2
  print (d, float(3.0));        // Calls print(float, float): d demoted to float, 3.0 explicitly cast to float → version 1
  print (i, int(d));            // Calls print(float, int): i promoted to float, d explicitly cast to int → version 2

}

/*
===========================
Function Overloading and Type Coercion in C++
===========================

This program demonstrates how C++ selects between overloaded functions when arguments of different types are passed, and how type conversion (promotion/demotion) and explicit casting affect this selection.

---------------------------
Overloaded Functions
---------------------------
void print(float a, float b)   // version 1: called when both arguments are float (or can be converted to float)
void print(float a, int b)     // version 2: called when the first argument is float (or convertible), second is int (or convertible)

---------------------------
Variable Declarations
---------------------------
int i = 0, j = 0;      // Two integer variables
float f = 0.0;         // One float variable
double d = 0.0;        // One double variable

---------------------------
Function Calls and Type Conversions
---------------------------

1. print(i, j);
   - i: int, j: int
   - i is promoted to float (standard conversion), j remains int
   - Calls print(float, int) → version 2

2. print(i, f);
   - i: int, f: float
   - i is promoted to float, f is already float
   - Calls print(float, float) → version 1

3. print(d, f);
   - d: double, f: float
   - d is demoted to float, f is already float
   - Calls print(float, float) → version 1

// The following are commented out, but if enabled, would behave as described:
   // print(d, 3.5);   // d demoted to float, 3.5 (double literal) demoted to float → print(float, float)
   // print(i, 4.5);   // i promoted to float, 4.5 (double literal) demoted to float → print(float, float)
   // print(d, 3.0);   // d demoted to float, 3.0 (double literal) demoted to float → print(float, float)
   // print(i, d);     // i promoted to float, d demoted to float → print(float, float)

---------------------------
Explicit Casting and Overload Selection
---------------------------

4. print(d, float(3.5));
   - d: double, explicitly cast to float by overload resolution
   - 3.5: double literal, explicitly cast to float
   - Calls print(float, float) → version 1

5. print(i, int(4.5));
   - i: int, promoted to float
   - 4.5: double literal, explicitly cast to int (becomes 4)
   - Calls print(float, int) → version 2

6. print(d, float(3.0));
   - d: double, demoted to float
   - 3.0: double literal, explicitly cast to float
   - Calls print(float, float) → version 1

7. print(i, int(d));
   - i: int, promoted to float
   - d: double, explicitly cast to int (becomes 0)
   - Calls print(float, int) → version 2

---------------------------
Summary Table
---------------------------
| Call                   | Argument Types After Conversion | Overload Called        | Output      |
|------------------------|---------------------------------|------------------------|-------------|
| print(i, j)            | float, int                      | print(float, int)      | version 2   |
| print(i, f)            | float, float                    | print(float, float)    | version 1   |
| print(d, f)            | float, float                    | print(float, float)    | version 1   |
| print(d, float(3.5))   | float, float                    | print(float, float)    | version 1   |
| print(i, int(4.5))     | float, int                      | print(float, int)      | version 2   |
| print(d, float(3.0))   | float, float                    | print(float, float)    | version 1   |
| print(i, int(d))       | float, int                      | print(float, int)      | version 2   |

---------------------------
Key Takeaways
---------------------------
- **Function overloading:** C++ selects the best-matching overloaded function based on argument types.
- **Type promotion/demotion:** C++ automatically converts types (e.g., int to float, double to float) to match function parameters.
- **Explicit casting:** You can control which overload is called by explicitly casting arguments.

This example helps you understand how C++ resolves overloaded function calls and how type conversions and explicit casts affect that process.
*/