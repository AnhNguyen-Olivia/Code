#include<iostream>           // Includes the standard input/output stream library.
#include<conio.h>            // Includes console input/output functions (like getche()).
using namespace std;         // Allows usage of standard namespace (so you can write cout instead of std::cout).

class Counter_type {         // Defines a class named Counter_type.
public:                     // Public section: members accessible from outside the class.
    char counter_char;      // Character to be counted.
    int counter;            // Integer to store the count.
    void init(char c);      // Member function to initialize the counter.
    void add_one(void);     // Member function to increment the counter.
};

main()                      // Main function (should be int main(), but works in some compilers).
{
    char in_char;           // Variable to store user input.
    Counter_type my_counter;// Creates an object of Counter_type.

    my_counter.init('A');   // Initializes the counter to count 'A'.

    cout<<"Type a few A's and q to quit: "; // Prompts the user.
    do{
        if ((in_char=getche())==my_counter.counter_char) // Reads a character and checks if it matches counter_char.
            my_counter.add_one(); // If it matches, increment the counter.
    }while (toupper(in_char)!='Q'); // Loop until user enters 'q' or 'Q'.
    cout<<"\nNumber of "<<my_counter.counter_char<<"'s: "<<my_counter.counter; // Prints the count.
}

void Counter_type::init(char c) // Defines the init function.
{
    counter_char=c;         // Sets the character to count.
    counter=0;              // Initializes the counter to 0.
}

void Counter_type::add_one() // Defines the add_one function.
{
    counter++;              // Increments the counter by 1.
}


/*
    Program: Character Counter using Class

    Description:
    This program counts how many times the user types the character 'A' (uppercase) 
    until they press 'q' or 'Q' to quit.

    How it works:
    1. Class Definition:
        - The Counter_type class has two data members:
            * counter_char: the character to count (set to 'A').
            * counter: the number of times 'A' is typed.
        - It has two member functions:
            * init(char c): sets which character to count and resets the counter.
            * add_one(): increments the counter by 1.

    2. Main Function:
        - Creates a Counter_type object called my_counter.
        - Initializes it to count 'A' using my_counter.init('A').
        - Prompts the user to type characters.
        - In a loop, reads each character as the user types (using getche() to echo input).
        - If the character matches 'A', it calls my_counter.add_one() to increment the count.
        - The loop continues until the user types 'q' or 'Q'.
        - After quitting, it prints the total number of 'A's typed.

    Summary:
    The program demonstrates a simple use of a class to encapsulate counting logic,
    and interacts with the user to count specific character input in real time.
*/