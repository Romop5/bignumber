#ifndef _NUMBER_H
#define _NUMBER_H

#include "sector.h"

template <typename T = unsigned long long>
class Number
{
	void shiftLeft();
	void shiftRight();

	public:
	std::vector<Sector<T>> value;
	Number(T start = 0);

	Number<T> operator+(const Number<T>& second);
	
	Number<T> operator*(const Number<T>& second);

	Number<T> operator++();
	
	inline bool isEven() const { return !getBit(0); }

	// Bit accessing 
	
	bool getBit(size_t pos) const;
	
	void setBit(size_t pos, bool value);

	// Comparison operators

	bool operator==(const Number<T>& second) const;
	
	bool operator>(const Number<T>& second) const;
	
	Number<T> operator<<(const size_t shift);

	Number<T> operator>>(const size_t shift);

	void print() const
	{
		for(auto it = value.rbegin(); it != value.rend(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};

#include "number.cpp"

#endif
