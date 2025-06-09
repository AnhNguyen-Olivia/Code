#include<iostream>
#include<conio.h>
using namespace std;
void init(char c);
void add_one(void);
struct counter_type {
	char counter_char;
	int counter;
} my_counter;
main()
{
	char in_char;
	init('A');
	cout<<"Type a few A's and q to quit: ";
	do{
		if ((in_char=getche())==my_counter.counter_char) add_one();
	}while (toupper(in_char)!='Q');
	cout<<"\nNumber of "<<my_counter.counter_char<<"'s: "<<my_counter.counter;
}
void init(char c)
{
	my_counter.counter_char=c;
	my_counter.counter=0;
}
void add_one()
{
	my_counter.counter++;
}
