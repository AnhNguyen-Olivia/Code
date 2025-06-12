#include <iostream> // Include the input/output stream library for console operations
using namespace std; // Use the standard namespace

// Define a base class Felid
class Felid {
    public:
        // Virtual function for meowing, can be overridden by derived classes
        virtual void meow() {
            std::cout<<"Meowing likes a regular cat!"<<endl; // Print default meow message
        };
};

// Define a derived class Cats, inherits from Felid
class Cats: public Felid {
    // Inherits meow() from Felid without overriding
};

// Define a derived class Tigers, inherits from Felid
class Tigers: public Felid {
    public:
        // Override meow() to provide Tiger-specific message
        void meow() {
            std::cout<<"Meowing likes a tiger"<<endl; // Print tiger meow message
        };
};

// Define a derived class Ocelot, inherits from Felid
class Ocelot: public Felid {
    public:
        // Override meow() to provide Ocelot-specific message
        void meow() {
            std::cout<<"Meowing like a Ocelot!"<<endl; // Print ocelot meow message
        };
};

// Function that takes a pointer to Felid and calls its meow() method
void do_meowing(Felid* felid)
{
    felid->meow(); // Call the appropriate meow() based on the actual object type (polymorphism)
}

int main()
{
    // Create an array of pointers to Felid, each pointing to a different derived class object.
    // This demonstrates how base class pointers can refer to derived class objects.
    Felid* felidae[] = { new Cats(), new Tigers(), new Ocelot() };

    // Loop through the array and call do_meowing for each object.
    // Thanks to the virtual function, the correct meow() implementation is called for each object.
    for (int i = 0; i < 3; i++)
        do_meowing(felidae[i]); // Calls the appropriate meow() for Cats, Tigers, and Ocelot.

    // Note: The program does not delete the allocated memory, which may cause memory leaks.
}
/*

This program demonstrates **runtime polymorphism** in C++ using inheritance and virtual functions.

- **Base Class (Felid):** Declares a virtual function `meow()` that can be overridden by derived classes.
- **Derived Classes (Cats, Tigers, Ocelot):**
    - `Cats` uses the base class implementation of `meow()`.
    - `Tigers` and `Ocelot` override `meow()` to provide their own specific messages.
- **Polymorphism in Action:**
    - An array of `Felid*` pointers is created, each pointing to a different derived class object.
    - The function `do_meowing` takes a `Felid*` and calls `meow()`.
    - When `do_meowing` is called for each object, the correct `meow()` function is called based on the actual object type, not just the pointer type.

**Summary:**  
The program shows how virtual functions enable you to call the correct overridden method for derived classes using base class pointers, demonstrating runtime polymorphism in C++.
*/