#include "bignumber.h"

int main()
{
	Number<unsigned short> a(~0), b(10),c;

	c = a+b;

	
	std::cout << "A: \n";
	a.print();
	std::cout << "B: \n";
	b.print();
	std::cout << "C: \n";
	c.print();

	
	c = c + c;
	std::cout << "C: \n";
	c.print();


	std::cout << "Is C == C ? " << (c == c) << std::endl;
	std::cout << "Is C > A ? " << (c > a) << std::endl;


};
