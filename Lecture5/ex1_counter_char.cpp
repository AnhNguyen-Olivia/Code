#include<iostream>           // Includes the standard input/output stream library for using cout, cin, etc.
#include<conio.h>            // Includes console input/output functions like getche().
using namespace std;         // Allows usage of standard namespace (so you can write cout instead of std::cout).

void init(char c);           // Function prototype for initializing the counter.
void add_one(void);          // Function prototype for incrementing the counter.

struct counter_type {        // Defines a structure to hold the character to count and its count.
    char counter_char;       // Character to be counted.
    int counter;             // Number of times the character has been entered.
} my_counter;                // Declares a global variable of type counter_type.

main()                       // Main function (should be int main(), but works in some compilers).
{
    char in_char;            // Variable to store user input character.
    init('A');               // Initializes the counter to count 'A' characters.
    cout<<"Type a few A's and q to quit: "; // Prompts the user.

    do{
        if ((in_char=getche())==my_counter.counter_char) // Reads a character and checks if it matches the counter_char.
            add_one();        // If it matches, increments the counter.
    }while (toupper(in_char)!='Q'); // Continues until the user enters 'q' or 'Q'.

    cout<<"\nNumber of "<<my_counter.counter_char<<"'s: "<<my_counter.counter; // Displays the count.
}

void init(char c)            // Function to initialize the counter.
{
    my_counter.counter_char=c; // Sets the character to count.
    my_counter.counter=0;      // Resets the counter to zero.
}

void add_one()               // Function to increment the counter.
{
    my_counter.counter++;      // Increments the counter by one.
}

/* 
This program interactively counts how many times the user types the character 'A' (uppercase only) until they press 'q' or 'Q' to quit.

How it works:

1. Initialization:
   - The init('A') function sets up the counter to count the character 'A' and resets the count to zero.

2. User Prompt:
   - The program displays a message prompting the user to type some 'A's and 'q' to quit.

3. Input Loop:
   - The program enters a loop, reading each character the user types using getche() (which also echoes the character).
   - If the character matches 'A', the add_one() function increments the counter.
   - The loop continues until the user types 'q' or 'Q' (case-insensitive check using toupper).

4. Result Display:
   - After quitting, the program prints the total number of 'A's entered.

Summary:
This is a simple interactive character counter for 'A', ending when the user presses 'q' or 'Q'.
*/