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

