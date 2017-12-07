#include "bignumber.h"

int main()
{
	using T = unsigned char;
	Number<T> start(1);

	size_t i = 0;
	// print first 32 powers of 2
	for(i = 0; i < 100000;i++)
	{
		start = start << 1;
	}
	std::string value = NumberConversion<T> (start).getValue();
	std::cout << "I: " << i << " : " << value << std::endl;
}
