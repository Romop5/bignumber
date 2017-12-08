#ifndef _NUMBERCONVERSION_H
#define _NUMBERCONVERSION_H
#include "number.h"
#include <ctype.h>
#include <vector>
#include <iostream>
#include "stringconversion.h"

template <typename T = unsigned long long>
class NumberConversion 
{
	std::string result;

	void multiplyByTwo(std::vector<unsigned char> &digits);

	void addOne(std::vector<unsigned char> &digits);

	void displayBits(std::vector<unsigned char> &digits, const Sector<T>& sec);
	

	public:
	std::string getValue() const { return result; }

	operator std::string ()	{ return result; }
	
	NumberConversion(const Number<T>& num);
};

#include "numberconversion.cpp"
#endif

