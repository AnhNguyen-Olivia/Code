#include <iostream>
class A {
protected:
    int a;
public:
    A() { a=10; }
    void seta(int value);
};
void A::seta(int value) 
{
	a=value;
} 
 
class B: public A {
private:
    int b;
public:
    void showA(A x) {
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
