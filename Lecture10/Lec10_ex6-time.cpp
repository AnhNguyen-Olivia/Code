#include <iostream>      // For input/output stream operations
#include <iomanip>       // For formatted output (e.g., setw, fill)


using namespace std;     // Use the standard namespace

const unsigned HOURMAX = 23;   // Maximum value for hours (24-hour format)
const unsigned MINUTEMAX = 59; // Maximum value for minutes

// Definition of the Time class
class Time {
  unsigned hours;        // Stores the hour component
  unsigned minutes;      // Stores the minute component
public:
  Time(unsigned c = 0);              // Constructor with default value
  Time(const Time & t);              // Copy constructor
  void setHours(unsigned h);         // Set hours with validation
  void setMinutes(unsigned m);       // Set minutes with validation
  Time & operator ++();              // Prefix increment operator
  Time operator ++(int);             // Postfix increment operator
  Time & operator += (unsigned n);   // Add minutes operator
  void display() const;              // Display time in hh:mm format
};

// Constructor: initializes time from a 4-digit integer (e.g., 1845 for 18:45)
Time::Time(unsigned tv) {
  // 1845 to represent 18:45
  setHours(tv / 100);    // Extract hours (e.g., 1845 / 100 = 18)
  setMinutes(tv % 100);  // Extract minutes (e.g., 1845 % 100 = 45)
}

// Copy constructor: copies hours and minutes from another Time object
Time::Time(const Time & t2) {
  minutes = t2.minutes;
  hours = t2.hours;
}

// Sets the hours, aborts if value is invalid
void Time::setHours(unsigned h) {
  if (h > HOURMAX) {
    cout << "ERROR: input hour is greater than HOURMAX!!\n";
    abort();
  }
  hours = h;
}

// Sets the minutes, aborts if value is invalid
void Time::setMinutes(unsigned m) {
  if (m > MINUTEMAX) {
    cout << "ERROR: input minute is greater than MINUTEMAX!!\n";
    abort();
  }
  minutes = m;
}

// Prefix increment: ++obj; increments minutes, rolls over to next hour if needed
Time & Time::operator ++() {
  if (++minutes > MINUTEMAX) {           // Increment minutes, check for overflow
    minutes = 0;                         // Reset minutes to 0
    hours = (hours + 1) % (HOURMAX + 1); // Increment hour, wrap around after 23
  }
  return *this;                          // Return reference to current object
}

// Postfix increment: obj++; returns old value, then increments
Time Time::operator ++(int) {
  Time save(*this); // Make a copy of current object
  operator ++();    // Use prefix increment to update time
  return save;      // Return the copy (old value)
}

// Adds n minutes to the time, handles overflow for hours and minutes
Time & Time::operator += (unsigned n) {
  unsigned t = minutes + n;              // Total minutes
  minutes = t % (MINUTEMAX + 1);         // Set minutes, handle overflow
  hours += t / (MINUTEMAX + 1);          // Add extra hours from overflow
  hours = hours % (HOURMAX + 1);         // Wrap around if hours exceed 23
  return *this;                          // Return reference to current object
}

// Displays the time in hh:mm format with leading zeros
void Time::display() const {
  cout.fill('0');                        // Fill with '0' for single digits
  cout << setw(2) << hours << ":" << setw(2) << minutes << endl;
}

// Main function to demonstrate the Time class
int main() {
  Time a;                // Default time: 00:00
  Time b(1845);          // Time: 18:45
  Time c(2359);          // Time: 23:59
  (++a).display();       // Increment a, display: 00:01
  (b++).display();       // Display b (18:45), then increment to 18:46
  (c += 15).display();   // Add 15 minutes to c, display: 00:14 (rolls over)
  (b += 20).display();   // Add 20 minutes to b, display: 19:06
  Time d(1230);          // Time: 12:30

  // Increment d 50 times, displaying each new value
  for(unsigned i = 0; i < 50; i++)
    (++d).display();
}

/*

This code demonstrates several foundational C++ programming concepts through the implementation of a simple Time class:

1. **Class Design and Encapsulation:**
   - The `Time` class models a clock using private data members for hours and minutes.
   - It provides public member functions to manipulate and display time, illustrating encapsulation and data hiding.

2. **Constructors (Default, Parameterized, and Copy):**
   - The class includes a default constructor (with a default argument), a parameterized constructor (to convert a 4-digit integer into hours and minutes), and a copy constructor.
   - This shows how to initialize objects in different ways and how to copy objects safely.

3. **Operator Overloading:**
   - The code overloads the prefix (`++obj`) and postfix (`obj++`) increment operators to add one minute to the time, handling minute and hour roll-over.
   - The `+=` operator is overloaded to add an arbitrary number of minutes, demonstrating how custom types can behave like built-in types.

4. **Input Validation:**
   - The `setHours` and `setMinutes` functions check for valid input and abort the program if invalid values are provided.
   - This enforces class invariants and demonstrates defensive programming.

5. **Formatted Output:**
   - The `display` function uses `iomanip` to print the time in a consistent `hh:mm` format with leading zeros, showing how to produce user-friendly output.

6. **Separation of Interface and Implementation:**
   - The code separates the class declaration from the function definitions, promoting modular and maintainable code.

7. **Testing and Demonstration:**
   - The `main` function creates several `Time` objects and demonstrates the use of constructors, operator overloads, and the display function.
   - It also tests time roll-over and repeated increments in a loop.

**Summary:**
This example teaches how to design a robust, user-friendly C++ class with encapsulation, input validation, operator overloading, and formatted output, all while modeling a real-world concept (time). It also encourages good programming practices such as modularity and defensive coding.

*/