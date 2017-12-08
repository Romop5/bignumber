#include <limits>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T = unsigned long long>
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

