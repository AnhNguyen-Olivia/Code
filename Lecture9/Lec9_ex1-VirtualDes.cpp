#include <iostream> // Provides input/output functionality
using namespace std; // Allows use of standard library names without std:: prefix

// Base class definition
class Base 
{
public: 
    // Virtual destructor ensures proper cleanup of derived objects
    virtual ~Base() { 
        cout << "Calling Destructor of Base\n"; // Message when Base destructor is called
    }
    // If the destructor above is not virtual (see commented line below),
    // deleting a derived object through a base pointer will NOT call the derived destructor
    //~Base() { cout << "Calling Destructor of Base\n"; } // Non-virtual version (for demonstration)
};

// Derived class inherits from Base
class Derived : public Base
{
public:
    // Destructor for Derived class
    ~Derived() 
    {
       // Place for cleanup code specific to Derived
       cout << "Calling Destructor of Derived\n"; // Message when Derived destructor is called
    }
};

int main() {
  // Create a Derived object, but store its address in a Base class pointer
  Base *b = new Derived(); 

  // ... (object could be used here)

  // Deleting through a base pointer:
  // If Base's destructor is NOT virtual, only Base's destructor runs,
  // and Derived's destructor is skipped (BAD: can cause resource leaks)
  // If Base's destructor IS virtual, both destructors run in order: Derived, then Base (GOOD)
  delete b; 
}

/*
Code Explanation:
- Demonstrates the importance of virtual destructors in base classes for proper cleanup.
- When deleting a derived object through a base pointer, a non-virtual base destructor will skip the derived destructor.
- This can cause incomplete cleanup and resource leaks.
- Making the base destructor virtual ensures both destructors are called in the correct order.
- Always declare destructors virtual in base classes intended for polymorphic use.
*/