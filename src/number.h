#ifndef _NUMBER_H
#define _NUMBER_H

#include <limits>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
class Sector
{
	public:
	T value;
	Sector(T newvalue = 0) : value(newvalue) {};
	// Return true when overflow
	inline bool operator+(const Sector<T>& second)
	{
		bool overflow = true;
		if(std::numeric_limits<T>::max()-this->value > second.value)
			overflow = false;
		this->value += second.value;
		return overflow;
	}

	inline bool operator+(const T num)
	{
		bool overflow = true;
		if(std::numeric_limits<T>::max()-this->value > num)
			overflow = false;
		this->value += num;
		return overflow;
	}

	inline bool operator!=(const Sector<T>& second) const
	{
		return this->value != second.value;
	}

	inline bool operator>(const Sector<T>& second) const
	{
		return this->value > second.value;
	}

	inline bool operator<(const Sector<T>& second) const
	{
		return this->value > second.value;
	}


};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Sector<T>& obj)
{
    // write obj to stream
	if(obj.value == 0)
	{
		os << 0; 
		return os;
	}
    os << obj.value;
    return os;
}

template <typename T>
class Number
{
	public:
	std::vector<Sector<T>> value;
	Number(T start = 0)
	{
		//TODO algorithm
		value.push_back(Sector<T>(start));
	}
	Number<T> operator+(const Number<T>& second)
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

	void setBit(size_t pos, bool value)
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

	bool operator==(const Number<T>& second) const
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

	bool operator>(const Number<T>& second) const
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



	void print() const
	{
		for(auto it = value.rbegin(); it != value.rend(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};

class StringConverter
{
	template <typename T> 
	StringConverter(Number<T> input)
	{

	};
};


#endif
