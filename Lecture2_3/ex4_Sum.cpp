#include <iostream>                  
#include <fstream>                   // Includes file stream library for file operations

void inputFile();                    // Function prototype for inputFile
int fileSum();                       // Function prototype for fileSum

main()                               // Main function (should be int main())
{
    inputFile();                     // Calls inputFile to get user input and write to file
    int sum;                         // Declares variable to store the sum
    sum = fileSum();                 // Calls fileSum to read numbers from file and sum them
    std::cout << "Sum:" << sum;      // Outputs the sum to the console
}//ex2_Sum.cpp

void inputFile()                     // Function to get input and write to file
{
    int n, x;                        // n: number of integers, x: current integer
    std::ofstream fout("Ex2file");   // Opens file "Ex2file" for writing
    std::cout << "Input the number of integers:"; // Prompts user
    std::cin >> n;                   // Reads number of integers from user
    fout << n << std::endl;          // Writes n to file
    std::cout << "Input an array of integers:"; // Prompts user for integers
    for (int i = 0; i < n; i++)     // Loops n times
    {
        std::cin >> x;               // Reads integer from user
        fout << x << " ";            // Writes integer to file
    }
    fout.close();                    // Closes the file
}

int fileSum()                        // Function to read numbers from file and sum them
{
    std::ifstream infile("Ex2file"); // Opens file "Ex2file" for reading
    int value, n;                    // value: current integer, n: number of integers
    int sum = 0;                     // Initializes sum to 0
    //Read the number of integers
    infile >> n;                     // Reads n from file
    //Read members
    int i = 0;                       // Initializes counter
    while (i < n)                    // Loops n times
    {
        infile >> value;             // Reads integer from file
        sum = sum + value;           // Adds value to sum
        i++;                         // Increments counter
    }
    return sum;                      // Returns the sum
    infile.close();                  // (Unreachable) Closes the file
}


/*
===============================================================================
  Program: ex4_Sum.cpp
  Purpose: Reads a list of integers from the user, writes them to a file,
           then reads them back from the file and computes their sum.
===============================================================================

  main() function:
    - Calls inputFile() to prompt the user for input and write the numbers to
      a file named "Ex2file".
    - Calls fileSum() to read the numbers from the file and calculate their sum.
    - Prints the sum to the console.

  inputFile() function:
    - Prompts the user to enter how many integers they want to input.
    - Reads that many integers from the user.
    - Writes the count and the integers to the file "Ex2file".

  fileSum() function:
    - Opens the file "Ex2file" for reading.
    - Reads the first value (the count of numbers).
    - Reads each integer from the file, adding them to a running total.
    - Returns the sum.

-------------------------------------------------------------------------------
  Summary:
    This program demonstrates basic file I/O in C++. It collects numbers from
    the user, saves them to a file, then reads them back and computes their sum.
===============================================================================
*/
