#include <iostream>
using namespace std;
class A {
private:
    int a;
public:
    A() { 
		cout<<" Constructor A\n"; 
	}
	~A()
	{
		cout<<"Destructor A\n";
	}
};
 
class B {
public:
	B() { 
		cout<<" Constructor B\n"; 
	}
	~B()
	{
		cout<<"Destructor B\n";
	}
};
class C {
private:
	A a;
	B b;
public:
	~C()
	{
		cout<<"Destructor C\n";
	}
	C() { 
		cout<<" Constructor C\n"; 
	}
};
int main() {
   C c;
 }
