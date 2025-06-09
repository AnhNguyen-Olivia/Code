#include <iostream>
using namespace std;
class Point {
	protected:
		int x, y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
};
class Point3D: public Point {
	protected:
		int z;
	public:
		Point3D()
		{
			z=0;
		}
};
main() 
{
	Point3D *cp=new Point3D;
	Point3D *cp1;
	Point *p;
	p=cp;
	cp1= (Point3D*) p;
}

