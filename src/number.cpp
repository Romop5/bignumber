#ifndef _NUMBER_CPP
#define _NUMBER_CPP
#ifndef _NUMBER_H
#include "number.h"
#endif

template<typename T>
void Number<T>::shiftLeft()
{
	bool carry = false;
	bool nextCarry = false;
	for(auto it = value.begin(); it != value.end(); it++)
	{
		// get leftmost bit from lower sector
		nextCarry = (it->value & (1 << (std::numeric_limits<T>::digits-1)));
		// shit lower sector
		it->value <<= 1;
		// apply current carry
		if(carry)
			it->value |= 1;
		// rotate carry for next round
		carry = nextCarry;
	}
	// extend number in case of last carry
	if(carry)
		value.push_back(1);
}

template<typename T>
void Number<T>::shiftRight()
{
	bool carry = false;
	bool nextCarry = false;
	for(auto it = value.rbegin(); it != value.rend(); it++)
	{
		// get rightmost bit from lower sector
		nextCarry = (it->value & 1);

		it->value >>= 1;
		// apply current carry
		if(carry)
			it->value |= (1 << (std::numeric_limits<T>::digits-1));
		// rotate carry for next round
		carry = nextCarry;
	}
	if(value.back().value == 0)
		value.pop_back();
}


template<typename T>
Number<T>::Number(T start)
{
	//TODO algorithm
	value.push_back(Sector<T>(start));
}

template<typename T>
Number<T> Number<T>::operator+(const Number<T>& second)
{
	Number<T> result = (*this > second)?*this:second;
	const Number<T>& addition = (*this > second)?second:*this;

	bool overflow = false;
	for(size_t i = 0; i < result.value.size(); i++)
	{
		bool  currentOverflow = false;
		if(addition.value.size() > i)
		{
			currentOverflow = result.value[i]+addition.value[i];
			
		}
		// corrent with overflow
		currentOverflow |= result.value[i]+overflow;
		if(addition.value.size() <= i && currentOverflow == false)
		{
			overflow = currentOverflow;
			break;
		}
		overflow = currentOverflow;
	}
	if(overflow == 1)
		result.value.push_back(Sector<T>(1));
	return result;
}

template<typename T>
Number<T> Number<T>::operator*(const Number<T>& second)
{
	// let a be > than b
	Number<T> a = (*this > second)?*this:second;
	Number<T> b = (!(*this > second))?*this:second;

	if(b == Number<T>(0))
		return Number<T>(0);

	while(b.isEven())
	{
		b.shiftRight();
		a.shiftLeft();
	}
	static Number<T> one(1);
	if(b == one)
		return a;
	b.setBit(0,0);
	return ((a*b)+a);
}

template<typename T>
Number<T> Number<T>::operator++()
{
	Number<T> result = *this;
	bool carry = true;
	for(size_t i = 0; i < result.value.size(); i++)
	{
		if(!carry)
			break;

		carry = result.value[i] + carry;
	}
	if(carry)
		result.value.push_back(0);
}



template<typename T>
bool Number<T>::getBit(size_t pos) const
{
	size_t chunkId = pos/std::numeric_limits<T>::digits;
	size_t chunkSubPosition = pos%std::numeric_limits<T>::digits;
	

	if(chunkId >= this->value.size())
		return 0;

	return ((this->value[chunkId].value & (1 << chunkSubPosition)) != 0);

}

template<typename T>
void Number<T>::setBit(size_t pos, bool value)
{
	size_t chunkId = pos/std::numeric_limits<T>::digits;
	size_t chunkSubPosition = pos%std::numeric_limits<T>::digits;

	// Extended number to match chunks
	for(size_t i = this->value.size(); i <= chunkId; i++)
	{
		this->value.push_back(Sector<T>(0));
	}

	if(value)
	{
		this->value[chunkId].value |= 1 << chunkSubPosition;
	} else {
		this->value[chunkId].value &= ~(1 << chunkSubPosition);
	}
}


template<typename T>
bool Number<T>::operator==(const Number<T>& second) const
{
	if(this->value.size() != second.value.size())
		return false;
	for(size_t i= 0; i < this->value.size(); i++)
	{
		if(this->value[i] != second.value[i])
			return false;
	}
	return true;
}

template<typename T>
bool Number<T>::operator>(const Number<T>& second) const
{
	if(this->value.size() > second.value.size())
		return true;
	if(this->value.size() < second.value.size())
		return false;
	for(size_t i= 0; i < this->value.size(); i++)
	{
		if(this->value[i] > second.value[i])
			return true; 
		else if(this->value[i] < second.value[i])
			return false;
	}
	// they are equal
	return false;
}


template<typename T>
Number<T> Number<T>::operator<<(const size_t shift)
{
	Number<T> result = *this;
	size_t count = shift;
	while(count--)
	{
		result.shiftLeft();
	}
	return result;
}

template<typename T>
Number<T> Number<T>::operator>>(const size_t shift)
{
	Number<T> result = *this;
	size_t count = shift;
	while(count--)
	{
		result.shiftRight();
	}
	return result;
}
#endif

