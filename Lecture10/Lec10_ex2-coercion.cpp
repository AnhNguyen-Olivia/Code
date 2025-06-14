// Define an empty class named Student
class Student {
};

// Declare a function 'calculate' that takes two long and two double parameters
void calculate (long p1, long p2, double p3, double p4) {}

// Entry point of the program
int main() {
  // Declare and initialize a variable of type long
  long a1 = 12345678;
  // Declare and initialize a variable of type int
  int a2 = 1;
  // Declare and initialize a variable of type double
  double a3 = 2.3455555;
  // Declare and initialize a variable of type float
  float a4 = 3.1;
  // Call 'calculate' with the variables above.
  // Implicit type conversion will occur:
  //   - a2 (int) will be promoted to long
  //   - a4 (float) will be promoted to double
  calculate(a1, a2, a3, a4); // This call is valid due to implicit conversions

  // Create an object of type Student
  Student s;
  // The following line, if uncommented, will cause a compilation error:
  //   - 's' is a Student object, but the function expects a long as the first argument.
  //   - There is no implicit conversion from Student to long.
  // calculate(s, 10, 5.5, 6); // Compilation error: incompatible types

  // Return 0 to indicate successful execution of the program
  return 0;
}


/*
  This program demonstrates implicit type conversion (type coercion) in C++ during function calls.

  - The function 'calculate' expects two long and two double parameters.
  - In 'main', variables of types long, int, double, and float are declared.
  - When calling 'calculate(a1, a2, a3, a4);', the compiler automatically converts:
      * 'a2' (int) to long
      * 'a4' (float) to double
    so the function call matches the parameter types.
  - The program also shows that user-defined types (like Student) cannot be implicitly converted to built-in types (like long).
    Attempting to do so results in a compilation error.

  This illustrates how C++ handles type conversions for built-in types, but not for user-defined types, during function calls.
*/