#ifndef _STRINGCONVERSION_H
#define _STRINGCONVERSION_H
#include "number.h"
#include <ctype.h>
#include <vector>
#include <iostream>

template <typename T = unsigned long long>
class StringConversion 
{
	public:
	Number<T> number;
	
	std::vector<unsigned char> toDigits(char* string) const;
	
	std::vector<unsigned char> digitsToBits(std::vector<unsigned char>& digits) const;
	public:
	StringConversion(char* string);

	StringConversion(std::string string);
	
	operator Number<T>() const { return number; }
};

#include "stringconversion.cpp"

#endif
