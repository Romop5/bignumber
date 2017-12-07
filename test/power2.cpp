#include "bignumber.h"

int main()
{
	using T = unsigned char;
	Number<T> start(1);

	// print first 32 powers of 2
	for(size_t i = 0; i < 10000;i++)
	{
		start = start << 1;
		std::string value = NumberConversion<T> (start).getValue();
		std::cout << "I: " << i << " : " << value << std::endl;
	}
}
