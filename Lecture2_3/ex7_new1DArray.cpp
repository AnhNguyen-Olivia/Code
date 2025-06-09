#include <iostream> 
using namespace std;             

// This program demonstrates dynamic allocation, initialization, usage, and deallocation of a 1D array in C++.
// Steps:
// 1. Dynamically allocate memory for an array of 5 integers.
// 2. Initialize each element to 10 times its index (0, 10, 20, 30, 40).
// 3. Print all elements of the array, separated by spaces.
// 4. Release the allocated memory to prevent memory leaks.

int main()                           
{
    int *p = new int[5];           // Allocate memory for 5 integers on the heap.
    for (int j = 0; j < 5; ++j)    // Initialize each element.
        *(p + j) = 10 * j;         // Set value to 10 times the index.
    for (int j = 0; j < 5; j++)    // Print each element.
        cout << p[j] << " ";       
    delete [] p;                   // Free the allocated memory.
    return 0;                      // Indicate successful program termination.
}

/*
Program Explanation:

1. Dynamic Allocation:
   int *p = new int[5];
   - Allocates memory for an array of 5 integers on the heap.
   - 'p' points to the first element of this array.

2. Initialization:
   - The first for loop assigns each element a value equal to 10 times its index.
   - Resulting array: [0, 10, 20, 30, 40]

3. Output:
   - The second for loop prints each element, separated by spaces.
   - Output: 0 10 20 30 40

4. Memory Deallocation:
   delete [] p;
   - Frees the dynamically allocated memory to prevent memory leaks.

Note:
- For standard compliance, use 'int main()' and return 0.
*/