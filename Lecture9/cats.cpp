#include <iostream>
using namespace std;
class Felid {
	public:
		virtual void meow() {
			std::cout<<"Meowing likes a regular cat!"<<endl;
		};
};
class Cats: public Felid {
};
class Tigers: public Felid {
	public:
		void meow() {
			std::cout<<"Meowing likes a tiger"<<endl;
		};
};
class Ocelot: public Felid {
	public:
		void meow() {
			std::cout<<"Meowing like a Ocelot!"<<endl;
		};
};
void do_meowing(Felid* felid)
{
	felid->meow();
}
int main()
{
	Felid* felidae[]={new Cats(),new Tigers(), new Ocelot()};
	for (int i=0; i<3; i++)
		do_meowing(felidae[i]);
}
