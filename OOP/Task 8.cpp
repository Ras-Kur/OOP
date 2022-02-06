#include<iostream>
#include<string>
/*         
Тема: Конструктор переноса

Задание 1.
Добавить в уже существующий класс String конструктор переноса.

Задание 2.
Добавить в уже существующий класс Array конструктор переноса.
*/

class String
{
	int length;
	std::string str{ 0 };
public:
	
	String() :length(1), str("unknown") {};
	String(int lenght, std::string str):String()
	{
		this->length = lenght;
		this->str = str;
	}
	~String()
	{
		
		str = " ";
		length = 0;
	};
	String& operator=(String& object)
	{
		this->length = object.length;
		this->str = object.str;
		object.length = 0;
		object.str = "unknown";
		return *this;
	}

	
	
	friend std::ostream& operator <<(std::ostream& output, String& object);
};
std::ostream& operator <<(std::ostream& output, String& object)
{
	output << "\nsize str - " << object.length << "\n" << "name str - " << object.str << "\n";
	return output;
}
int main()
{
	String obj1(1, "obj1"), obj2(2, "obj2");
	std::cout <<(obj1);
	obj1=(obj2);
	 std::cout << (obj1);
	 std::cout << (obj2);
	 std::cout << (obj1);
	 std::cout << (obj2);
	return 0;
}