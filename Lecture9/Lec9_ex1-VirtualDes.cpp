#include <iostream>
using namespace std;

class Base 
{
public: 
    // some virtual functions
  // should have made this destructor virtual
  virtual ~Base() { cout << "Calling Destructor of Base\n"; }
  //~Base() { cout << "Calling Destructor of Base\n"; }
};

class Derived : public Base
{
public:
    ~Derived()
    {
       // Do some important cleanup
       cout << "Calling Destructor of Derived\n";
    }
};

int main() {
  Base *b = new Derived();
  // use b
  delete b; // Here's the problem!
}
