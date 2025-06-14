#include <iostream> // Include the standard input/output stream library

// Define a class template S with a type parameter T
template <class T>
class S {
  T x; // Member variable of type T to store a value
public:
  // Constructor that initializes x with the given value xx
  S(const T & xx) { x = xx; }

  // Static member variable shared among all instances of S<T>
  static double something_relevant;

  // Member function to display x and the static variable
  void display() {
    std::cout << "x = " << x << ", st = " << something_relevant << "\n";
  }
};

// Define and initialize the static member variable for the template class
template <class T>
double S<T>::something_relevant = 1.5;

int main() {
  S<int> a(10); // Create an instance of S<int> with x initialized to 10
  a.display();  // Call the display function to print x and something_relevant
  return 0;     // Indicate successful program termination
}

/*
This program demonstrates how static member variables work in C++ class templates.

Key Concepts Illustrated:

1. Static Member in Templates:
   - The static variable `something_relevant` is declared inside the template class `S<T>`.
   - For each unique type `T` used with the template, a separate static variable is created.
     (For example, `S<int>::something_relevant` is independent from `S<double>::something_relevant`.)

2. Initialization of Static Members:
   - The static member is defined and initialized outside the class template using:
     `template <class T> double S<T>::something_relevant = 1.5;`
   - This ensures each instantiation of the template has its own static variable, initialized to 1.5.

3. Accessing Static and Non-static Members:
   - The `display()` member function prints both the instance variable `x` and the static variable `something_relevant`.
   - This shows how both static and non-static members can be accessed from within a member function.

4. Template Instantiation and Usage:
   - In `main()`, an instance of `S<int>` is created and initialized.
   - The `display()` function is called to show the values of `x` and `something_relevant`.

Summary:
- Each template instantiation (`S<int>`, `S<double>`, etc.) gets its own static variable.
- The program shows how to declare, define, initialize, and use static members in template classes.
- This is useful for cases where you want a value shared among all objects of a specific template type, but not across different types.
*/