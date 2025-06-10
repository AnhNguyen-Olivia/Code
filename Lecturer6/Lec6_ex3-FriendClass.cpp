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

/*
Difference Between Class A and Class B

Class A:
- Contains a private member variable 'a'.
- Provides a public constructor to initialize 'a' and a public method 'seta' to modify its value.
- Declares 'friend class B;', which allows class B to access its private and protected members.

Class B:
- Contains its own private member variable 'b' (not used in this example).
- Provides a public method 'showA' that takes an object of type A and accesses its private member 'a' directly.
- Is declared as a friend of class A, so it can access A’s private members. However, A cannot access B’s private members unless B also declares A as a friend.

Summary:
- Class A encapsulates its data and restricts access to its private members, but grants special access to class B through friendship.
- Class B uses this friendship to access and display A’s private data.
- Friendship in C++ is one-way and not inherited: only the friend class gets access, not the other way around.
*/