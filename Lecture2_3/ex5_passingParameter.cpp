#include <iostream>
using namespace std;
int incrementByValue(int);
void incrementByPointer(int *);
void incrementByRef(int &);
void incrementByConstRef(const int &);
main()
{
	int x = 5, y = 7, z = 9;
	cout << "x = " << x << " before incrementByValue\n"
		<< "Value returned by sqrByVal: "
		<< incrementByValue(x)
        << "\nx = " << x << " after incrementByValue\n\n";
    
    cout << "y = " << y << " before incrementByPointer\n";
		incrementByPointer(&y);
		cout << "y = " << y << " after incrementByPointer\n\n";
		
	cout << "z = " << z << " before incrementByRef\n";
		incrementByRef(z);
		cout << "z = " << z << " after incrementByRef\n";

	cout << "z = " << z << " before incrementByConstRef\n";
		incrementByConstRef(z);
		cout << "z = " << z << " after incrementByConstRef\n";
}

int incrementByValue(int a)
{
	return a += 10;
	// caller's argument not modified
}
void incrementByPointer(int *bPtr)
{
	*bPtr += 10;  
	// caller's argument modified
}
void incrementByRef(int &cRef)
{
	cRef += 10;    
	// caller's argument modified
}
void incrementByConstRef(const int &cRef)
{
	//cRef += 10;    
	// caller's argument modified
}


