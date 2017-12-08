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

TEST_CASE("Hardcore")
{

	StringConversion<unsigned char> litA("32000"), litB("32100");

	Number<unsigned char> a (100),b;

	b = litB;
	REQUIRE((a+litA) == b);

}
	

TEST_CASE("Conversion back and forth")
{
	std::string testHouseNumero = "1337";

	using T = unsigned char;
	StringConversion<T> input(testHouseNumero);

	NumberConversion<T> output(input);

	// Strings should be equal
	REQUIRE(testHouseNumero == output.getValue());
}

TEST_CASE("Big game")
{
	using T = unsigned char;
	Number<T> a(StringConversion<T>("150 000 000 000 000 000 000 000 000"));

	std::string result = NumberConversion<T>(a+a);

	REQUIRE(result == "300000000000000000000000000");
}

Number<unsigned char> num(const std::string & str)
{
	return Number<unsigned char>(StringConversion<unsigned char>(str));
}
TEST_CASE("Multiplication")
{
	REQUIRE(num("1") * num("1")  == num("1"));
	REQUIRE(num("2") * num("1")  == num("2"));
	REQUIRE(num("1") * num("2")  == num("2"));
	REQUIRE(num("50") * num("10")  == num("500"));
	REQUIRE(num("11") * num("10")  == num("110"));
	REQUIRE(num("12000") * num("10")  == num("120000"));
	REQUIRE(num("1500000000") * num("10")  == num("15000000000"));
	REQUIRE(num("666666666666666") * num("10")  == num("6666666666666660"));
	REQUIRE(num("123456789") * num("123456789")  == num("15241578750190521"));

	REQUIRE(num("1000000000") * num("1000000")  			== num("1000000000000000"));
	REQUIRE(num("10000000000") * num("10000000")  			== num("100000000000000000"));
	REQUIRE(num("1000000000000") * num("1000000000")  		== num("1000000000000000000000"));
	REQUIRE(num("100000000000000") * num("100000000000")  		== num("100000000000000000000000"));
	REQUIRE(num("10000000000000000") * num("10000000000000")  	== num("1000000000000000000000000000"));

}
