#include <iostream>
#include <string>

using namespace std;

template <class T>
class Array {
public:
  Array( unsigned sz );
  ~Array();
  T & operator[]( unsigned i );
private:
  T * values; 
  unsigned size;
};

template<class T> Array<T>::Array( unsigned sz ) {  
  values = new T [sz]; 
  size = sz;
}

template<class T> T & Array<T>::operator[] ( unsigned i ) { 
  if( i >= size ) {
    cout << "ERROR: array index out of bound!!!\n";
    abort();
  }
  return values[i];
}

template<class T> Array<T>::~Array() {  
  delete [] values;
}

int main() {  
  const unsigned numStudents = 2;
  Array<int>     ages( numStudents );
  Array<float>   gpas( numStudents );
  Array<string>  names(numStudents);
  for(int j = 0; j < numStudents; j++) {
    // do whatever you want
    ages[j] = 20;
  }
  return 0;
} //Lec11_ex5-array.cpp
