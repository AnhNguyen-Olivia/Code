#include <iostream>
using namespace std;

template <class T>

long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++)
    if (searchVal == table[i])
      return i;
  return -1;
}

class Student {
  long id;
public:
  Student( long idVal ) { id = idVal; }
  int operator ==( const Student & s2 ) const {
    return id == s2.id;
  }
};

int main() {
  const unsigned sc = 5;
  Student sTable[sc] = { 10000, 11111, 20000, 22222, 30000 };
  Student s( 20000 );
  cout << indexOf( s, sTable, sc ) << endl;     // print "3"
  return 0;
}
