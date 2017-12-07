class StringToNumber
{
	StringToNumber(char* string)
	{
		std::vector<unsigned char> digits;
		// Convert cstring to vector of unsigned bytes
		char* stringIterator = string;
		while(*stringIterator != '0')
		{
			digits.push_back(*stringIterator-'0');
		}

		// Convert to binary with division by 2
		
		unsigned char rest = 0;
		do {
		for(auto it = digits.begin(); it != digits.end(); it++)
		{
			if(rest)
				*it += 10;
			rest = *it % 2;
			*it /= 2;
		}
		std::cout << rest;
		if(digits.size() > 0)
			if(digit[0] == '0')
				digits.erase(0);
		} while(digits.size());
	}
};


int main()
{
	StringToNumber stn("127");
};
