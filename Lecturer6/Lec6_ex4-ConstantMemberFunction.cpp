// Constant member function
// for the console application.
//
#include <iostream>
using namespace std;
 
class CRect
{
//Sample 01: Private Members
private:
    int m_len;
    int m_width;
 
public:
//Sample 02: Constructor
	//int a;
    CRect(int L, int W)
    {
        m_len = L;
        m_width = W;
    }
 
//Sample 03: Print data members
    void print() 
    {
        cout << "Lenght = " << m_len 
<< " Width = "<< m_width << endl ;
    }
 
//Sample 04: Const Member Function
    int GetArea() const
    {
        m_len++ ;
        //a++;
        return m_len * m_width;
    }
 
 
};
 
int main()
{
    //Sample 05: Create Rectangle Object
    CRect rct(10,5);
 
    //Sample 06: Print the dimension
    rct.print();
 
    //Sample 07: Print the Area of Rectangle
    cout << "Area = " << rct.GetArea();
}
