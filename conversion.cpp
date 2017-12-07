#include "addition.h"
#include <vector>
#include <iostream>

template<typename T>
class StringToNumber
{
	public:
	Number<T> number;
	
	std::vector<unsigned char> toDigits(char* string)
	{
		std::vector<unsigned char> digits;
		// Convert cstring to vector of unsigned bytes
		char* stringIterator = string;
		while(*stringIterator != '\0')
		{
			digits.push_back(*stringIterator-'0');
			stringIterator++;
		}

		return digits;
	}
	std::vector<unsigned char> digitsToBits(std::vector<unsigned char>& digits)
	{
		std::vector<unsigned char> bits;
		unsigned char rest = 0;
		do {
			rest = 0;
			for(auto it = digits.begin(); it != digits.end(); it++)
			{
				if(rest)
					*it += 10;
				rest = *it % 2;
				*it /= 2;
			}
			bits.push_back(rest);
			int cislo = rest;
			std::cout << cislo;
			if(digits.size() > 0)
				if(digits[0] == 0)
					digits.erase(digits.begin());
		} while(digits.size());
		std::cout << std::endl;

		return bits;

	}
	public:
	StringToNumber(char* string)
	{
		
		// Convert cstring digits to binary digits
		auto digits = toDigits(string);

		// Convert to binary with division by 2
		auto bits= digitsToBits(digits);

		// Make up a number from bits
		for(size_t i = 0; i < bits.size();i++)
		{
			number.setBit(i,bits[i]);
		}
	}

	operator Number<T>() const
	{
		std::cout << "returned";
		number.print();
		std::cout << std::endl;
		return number;
	}
};


int main()
{
	StringToNumber<unsigned short> stn("281474976710656");
	Number<unsigned short> a(1),b(0);

	((a+stn)+stn).print();
};
