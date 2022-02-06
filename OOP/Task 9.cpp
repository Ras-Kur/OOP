
#include<iostream>
#include<string>
class String
{
	std::string* str;
	int length;
public:
	
	String() :str(nullptr), length(0) {};
	String(int leght, std::string stra )
	{
		this->length = leght;
		this->str[leght];
		for (size_t i = 0; i < length; i++)
			this->str[i] = str[i];
		this->str[length] = '\0';
	}
	~String()
	{
		delete[] this->str;
	}
	int & operator[](int index)
	{
		return  str[index];
	}
	
	bool operator()(char search)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (search==str[i])
			{
				return true;
			}
			else
			{
				
			}
		}
		return false;
	};
	
};

int nain()
{
	String str1(6,' ');
	//str1('f');

	return 0;
}