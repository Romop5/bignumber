#ifndef _NUMBERCONVERSION_CPP
#define _NUMBERCONVERSION_CPP
#ifndef _NUMBERCONVERSION_H
#include "numberconversion.h"
#endif

template<typename T>
void NumberConversion<T>::multiplyByTwo(std::vector<unsigned char> &digits)
{
	bool carry = false;
	for(size_t i = 0; i < digits.size(); i++)
	{
		digits[i] *= 2;
		digits[i] += carry;
		carry = (digits[i] / 10 != 0);
		digits[i] %= 10;
	}
	if(carry)
		digits.push_back(1);
}

template<typename T>
void NumberConversion<T>::addOne(std::vector<unsigned char> &digits)
{
	bool carry = true;
	for(size_t i = 0; i < digits.size(); i++)
	{
		digits[i] += carry;
		carry = (digits[i] / 10 != 0);
		digits[i] %= 10;
		if(carry == false)
			break;
	}
	if(carry)
		digits.push_back(1);
}

template<typename T>
void NumberConversion<T>::displayBits(std::vector<unsigned char> &digits, const Sector<T>& sec)
{
	for(size_t index = std::numeric_limits<T>::digits; index > 0; index--)
	{
		multiplyByTwo(digits);
		if(sec.value & (1 << (index-1)))
		{
			addOne(digits);
		}
	}
}

template<typename T>
NumberConversion<T>::NumberConversion(const Number<T>& num) 
{
	
	
	std::vector<unsigned char> digits;
	digits.push_back(0);

	// Display chunks to digits
	for(auto it = num.value.rbegin(); it != num.value.rend(); it++)
	{
		displayBits(digits,*it);
	}

	// Convert digits to string
	for(auto it = digits.rbegin(); it != digits.rend(); it++)
		result.push_back('0'+(*it));

}
#endif
