#define CATCH_CONFIG_MAIN 
#include "catch/catch.hpp"


#include "bignumber.h"

TEST_CASE("Simple additions")
{
	Number<unsigned char> a(1), b(0), c(0),max(127);

	REQUIRE((a+b) == a);

	REQUIRE((b+a) == a);

	
	REQUIRE((b+b) == c);


	for(size_t i = 0; i < 127;i++)
	{
		b = b + a;
	}

	b.print();
	max.print();
	REQUIRE(b == max);


}

TEST_CASE("Simple conversion")
{
	// Test 1
	StringConversion<unsigned int> litA("32000"), litB("32100");

	Number<unsigned int> a (100),b;

	b = litB;
	REQUIRE((a+litA) == b);


	// Test 2
	StringConversion<unsigned int> lib("10 000 000 000");

	Number<unsigned int> c(100000),result(0);

	for(size_t i = 0; i < 100000; i++)
	{
		result = result + c;
	}

	REQUIRE(result == lib);
}
	
