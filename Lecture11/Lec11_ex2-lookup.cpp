#include <iostream>
using namespace std;

template <class T>

long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++)
    if (searchVal == table[i])
      return i;
  return -1;
}

int main() {
  const unsigned iCount = 10, fCount = 5;
  int iTable[iCount] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  float fTable[fCount] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
  cout << indexOf( 20, iTable, iCount )   << endl;
  cout << indexOf( 2.2f, fTable, fCount ) << endl;  
  const unsigned sCount = 5;
  string names[sCount] = { "John","Mary","Sue","Dan","Bob" };
  cout << indexOf( (string) "Dan", names, sCount ) << endl; 
  return 0;
}
