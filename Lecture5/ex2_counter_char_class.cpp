#include<iostream>
#include<conio.h>
using namespace std;

class Counter_type {
public:
	char counter_char;
	int counter;
	void init(char c);
	void add_one(void);
};

main()
{
	char in_char;
	Counter_type my_counter;
	
	my_counter.init('A');
	
	cout<<"Type a few A's and q to quit: ";
	do{
		if ((in_char=getche())==my_counter.counter_char) my_counter.add_one();
	}while (toupper(in_char)!='Q');
	cout<<"\nNumber of "<<my_counter.counter_char<<"'s: "<<my_counter.counter;
}
void Counter_type::init(char c)
{
	counter_char=c;
	counter=0;
}
void Counter_type::add_one()
{
	counter++;
}
