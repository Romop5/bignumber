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

	public:
	std::string getValue()
	{
		return result;
	}
	
	void multiplyByTwo(std::vector<unsigned char> &digits)
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

	void addOne(std::vector<unsigned char> &digits)
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


	void displayBits(std::vector<unsigned char> &digits, const Sector<T>& sec)
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
	NumberConversion(const Number<T>& num) 
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

		// print result
		std::cout << result << std::endl;	
	}
};
#endif

