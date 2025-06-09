#include <iostream>
class A {
private:
    int a;
public:
    A() { a=10; }
    void seta(int value);
	friend class B;     // Friend Class
};
void A::seta(int value) 
{
	a=value;
} 
 
class B {
private:
    int b;
public:
    void showA(A x) {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a=" << x.a;
    }
};
 
int main() {
   A a;
   B b;
   a.seta(15);
   b.showA(a);
   return 0;
}
