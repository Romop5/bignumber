#ifndef _STRINGCONVERSION_CPP
#define _STRINGCONVERSION_CPP
#ifndef _STRINGCONVERSION_H
#include "stringconversion.h"
#endif
template<typename T>
std::vector<unsigned char> StringConversion<T>::toDigits(char* string) const
{
	std::vector<unsigned char> digits;
	// Convert cstring to vector of unsigned bytes
	char* stringIterator = string;
	while(*stringIterator != '\0')
	{
		// skip whitespaces, etc.
		if(isdigit(*stringIterator))
			digits.push_back(*stringIterator-'0');
		stringIterator++;
	}

	return digits;
}

template<typename T>
std::vector<unsigned char> StringConversion<T>::digitsToBits(std::vector<unsigned char>& digits) const
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

template<typename T>
StringConversion<T>::StringConversion(char* string)
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

template<typename T>
StringConversion<T>::StringConversion(std::string string)
{
	
	std::vector<unsigned char> digits;
	for(auto &x: string)
		digits.push_back((x)-'0');

	// Convert to binary with division by 2
	auto bits= digitsToBits(digits);

	// Make up a number from bits
	for(size_t i = 0; i < bits.size();i++)
	{
		number.setBit(i,bits[i]);
	}
}
#endif
