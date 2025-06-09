#include <iostream>
#include <fstream>
void inputFile();
int fileSum();
main()
{
	inputFile();
	int sum;
	sum=fileSum();
	std::cout<<"Sum:"<<sum;
}//ex2_Sum.cpp
void inputFile()
{
	int n, x;
	std::ofstream fout("Ex2file");
	std::cout<<"Input the number of integers:";
	std::cin >> n;
	fout<<n<<std::endl;
	std::cout<<"Input an array of integers:";
	for (int i=0; i<n;i++)
	{
		std::cin>>x;
		fout<<x<<" ";
	}
	fout.close();
}
int fileSum()
{
	std::ifstream infile("Ex2file");
	int value, n;
	int sum=0;
	//Read the number of integers
	infile>>n;
	//Read members
	int i=0;
	while (i<n)
	{
		infile>>value;
		sum=sum+value;
		i++;
	}
	return sum;
	infile.close();
}
