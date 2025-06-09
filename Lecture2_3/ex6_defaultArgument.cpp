#include <iostream> 
using namespace std; 

// Function to calculate the sum of integers from 'lower' to 'upper' (inclusive),
// incrementing by 'inc'. Default values: upper = 10, inc = 1.
int sum (int lower, int upper=10, int inc=1) {
    int sum = 0; // Initialize sum to 0
    for (int k = lower; k <= upper; k += inc) // Loop from lower to upper, incrementing by inc
        sum += k; // Add current value of k to sum
    return sum; // Return the computed sum
}

int main() // Main function: program execution starts here
{
    // Print the sum of integers from 1 to 10 (using default upper and inc values)
    cout << "Sum of integers from 1 to 10 is " << sum(1) << endl;
    return 0;
} // ex6-defaultArgument.cpp

/*
    This program calculates and prints the sum of integers from 1 to 10.

    - The function 'sum' takes three parameters:
        lower (start value),
        upper (end value, default 10),
        inc (increment, default 1).
    - In the main function, sum(1) is called, so it sums numbers from 1 to 10, increasing by 1.
    - The result is printed:
        Sum of integers from 1 to 10 is 55
*/



