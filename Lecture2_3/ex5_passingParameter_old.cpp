#include <iostream>
using namespace std;
int incrementByRef(int &);
main()
{
	int z = 9;
	 cout << "z = " << z << " before incrementByRef\n";
		incrementByRef(z);
		cout << "z = " << z << " after incrementByRef\n";
}
int incrementByRef(int &a)
{
	return a += 10;
	// caller's argument modified
}

// I have already talk about this code in the previous program.
// Re read the comments in ex2_cout.cpp
// The only difference is that I have changed the function signature to return int