#include <iostream> // Includes the input/output stream library for using cout
using namespace std; // Allows usage of standard namespace (so we can use cout without std:: prefix)

// Function to display an integer
void display (int x) { 
  cout << "Int!!!\n"; // Prints "Int!!!" if an int is passed
} // version 1

// Function to display a float
void display (float y) { 
  cout << "Float!!!\n"; // Prints "Float!!!" if a float is passed
}  // version 2

int main() {
  int i = 0;        // Declare and initialize an integer variable i to 0
  float f = 0.0;    // Declare and initialize a float variable f to 0.0
  double d = 0.0;   // Declare and initialize a double variable d to 0.0

  display(i); // Calls display(int), prints "Int!!!"
  display(f); // Calls display(float), prints "Float!!!"

  // Uncomment the below to see the effect
  //display(d); // Ambiguous: double can be converted to both int and float, compiler error
  //display(0.0); // Same as above: 0.0 is a double literal, ambiguous call

  // Program ends
}

/* 
  This program demonstrates function overloading and type coercion in C++. 
  It defines two overloaded functions named display: one takes an int, the other a float.

  In main(), variables of type int, float, and double are declared and initialized. 
  When display is called with the int and float variables, the corresponding overloaded function is invoked, 
  printing either "Int!!!" or "Float!!!" as expected.

  The commented-out lines show what happens if you try to call display with a double variable or a double literal (0.0). 
  Since there is no display(double) function, the compiler attempts to convert the double to either int or float. 
  Both conversions are equally valid, resulting in ambiguity and a compiler error.

  This example illustrates how C++ resolves overloaded function calls and highlights the potential for ambiguity 
  when implicit type conversions could match multiple overloads.
*/