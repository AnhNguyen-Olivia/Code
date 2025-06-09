#include <iostream>
using namespace std;
main() 
{
	int *p = new  int[5] ;
	for (int j=0; j < 5; ++j)
		*(p + j) = 10 * j;
	for (int j=0 ; j < 5; j++ )
		cout  <<  p[ j ]<<" ";
	delete [] p;
}

