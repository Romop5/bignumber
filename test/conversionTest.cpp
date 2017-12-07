#include "bignumber.h"

int main()
{

	StringConversion<unsigned int> litA("32000"), litB("32100");

	Number<unsigned int> a (100),b;

	std::cout << "This should be equal: \n";

	b = litB;
	std::cout << ((a+litA) == b) << std::endl;


	// Test 2
	StringConversion<unsigned int> lib("10 000 000 000");

	Number<unsigned int> c(100000),result(0);

	for(size_t i = 0; i < 100000; i++)
	{
		result = result + c;
	}

	std::cout << "This should be equal: \n";
	std::cout << (result == lib) << std::endl;

	result.print();
	std::cout << "vs\n";
	Number<unsigned int>(lib).print();

	
};
