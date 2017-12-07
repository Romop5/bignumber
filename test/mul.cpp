#include "bignumber.h"

Number<unsigned char> num(const std::string & str)
{
	return Number<unsigned char>(StringConversion<unsigned char>(str));
}


int main()
{
	using T = unsigned char;
	Number<T> a(128),b,c(StringConversion<T>("10000000000000000000000000000000000000"));

	a = a << 2;
	b = a >> 3;

	std::string value = NumberConversion<T> (b).getValue();
	std::cout << "Result:" << value << std::endl;


	b = c*c;		
	value = NumberConversion<T> (b).getValue();
	std::cout << "Result:" << value << std::endl;


	Number<T> res = num("12000") * num("10");

	std::cout << "Vysledok " << NumberConversion<T> (res).getValue() << std::endl;

}
