#include "bignumber.h"

int main()
{
	Number<unsigned int> b(1) ,c(0);

	for(size_t i = 900000000; i > 0; i--)
		c = c + b;



};
