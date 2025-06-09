#include <iostream>              
using namespace std;            

int main() {                     
  int a, b;                    
  float f; 
  char ch;                     

  cout << "Enter two integers, one float, and a char: ";
  cin >> a >> b >> f >> ch;      // Read two ints, a float, and a char from user

  // Display the values entered by the user
  cout << "a = " << a << ", b = " << b 
       << ", f = " << f << ", ch = " << ch << endl; 

  char name[80];                 // Array to store name (max 79 chars + null terminator)
  ch = '\0';                     // Initialize ch to null character
  int i = 0;                     // Index for name array

  cout << "Enter your name (with '#' at the end): \n";
  // Read characters one by one until '#' is entered
  while (1) {                    
    cin >> ch;                   // Read a character (skips whitespace) 
    // ch = cin.get();           // Alternative: read all characters including whitespace
    if (ch == '#') break;        // Stop if '#' is entered
    name[i++] = ch;              // Store character in name array
  }
  name[i]= '\0';                 // Null-terminate the string

  cout << name << endl;          // Output the entered name
  return 0;                      // Indicate successful program end
}

/*
==========================================================
 Program Description:
 ---------------------------------------------------------
 1. Reads and displays basic data types:
    - Prompts the user to enter two integers, a float, and a character.
    - Reads these values using: cin >> a >> b >> f >> ch;
    - Displays the entered values.

 2. Reads and displays a name until a special character:
    - Prompts the user to enter their name, ending with the '#' character.
    - Reads one character at a time (skipping whitespace) and stores each character in the name array.
    - Stops reading when '#' is entered, then null-terminates the string.
    - Prints the entered name (excluding the '#').

 ---------------------------------------------------------
 Summary:
 Demonstrates how to use cin for reading different data types
 and how to read a string character-by-character until a 
 specific terminating character is encountered.
==========================================================
*/