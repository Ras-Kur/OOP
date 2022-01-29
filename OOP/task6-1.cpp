/*
Задание 1.
Создайте класс Дробь(или используйте уже ранее созданный вами).Используя перегрузку операторов реализуйте
для него арифметические операции для работы с дробями
(операции + , -, *, / ).*/


#include<iostream>

class Fraction // дробь
{
	int numerator;		// числитель
	int denominator;	// знаменатель

public:
	Fraction() :numerator(1), denominator(1) {};

	void  EnteringFractions()// -ввод дроби
	{
		std::cin >> numerator;
		std::cout << "   /\n   ";
		std::cin >> denominator;
	};

	void ShowFraction()// - вывод дроби
	{
		std::cout << "\n" << numerator << "/" << denominator << "\n";
	};
	friend Fraction& operator+(Fraction const& value1, Fraction const& value2);
	friend Fraction& operator-(Fraction const& value1, Fraction const& value2);  //перегрузка.
	friend Fraction& operator*(Fraction const& value1, Fraction const& value2);
	friend Fraction& operator/(Fraction const& value1, Fraction const& value2);
};

	
int main()
{
	Fraction new_fraction1;
	Fraction new_fraction2;

	std::cout << "\n please enter the first fraction\n > ";//пожалуйста, введите первую дробь
	new_fraction1.EnteringFractions();
	std::cout << "\n ";
	new_fraction1.ShowFraction();

	std::cout << "\n please enter the second fraction\n > ";//пожалуйста, введите вторую дробь
	new_fraction2.EnteringFractions();
	std::cout << "\n ";
	new_fraction2.ShowFraction();

	std::cout << "\n select arithmetic sign\n (1 = +, 2 = -, 3 = *, 4 = /.) \n > ";//выберите арифметический знак
	int symbol = 0;
	char ch_symbol = '.';
	std::cin >> symbol;

	/*if (symbol == 1)
		std::cout << (new_fraction1 + new_fraction2);
	if (symbol == 2)
		std::cout << (new_fraction1 - new_fraction2);
	if (symbol == 3)
		std::cout << (new_fraction1 * new_fraction2);
	if (symbol == 4)
		std::cout << (new_fraction1 / new_fraction2);*/

	// не смог победить. решил вынести значения первоначальные в паблик.
	// но это не красиво. в общем, с раъименованием надо покавыряться, но я не смог.

	if (symbol == 1)
		std::cout << &(new_fraction1 + new_fraction2);
	if (symbol == 2)
		std::cout << &(new_fraction1 - new_fraction2);
	if (symbol == 3)
		std::cout << &(new_fraction1 * new_fraction2);
	if (symbol == 4)
		std::cout << &(new_fraction1 / new_fraction2);

	// рак выдает адрес.
	// я не округлял, до целого. но замечание помню ваше в предыдущей домашке.

	
	system("pause");
	return 0;
}

Fraction& operator+(Fraction const& value1, Fraction const& value2)
{
	Fraction result;
	result.numerator = (value1.numerator * value2.denominator) + (value2.numerator * value1.denominator);
	result.denominator = value1.denominator * value2.denominator;
	return result;
};

Fraction& operator-(Fraction const& value1, Fraction const& value2)
{
	Fraction result;
	result.numerator = (value1.numerator * value2.denominator) - (value2.numerator * value1.denominator);
	result.denominator = value1.denominator * value2.denominator;
	return result;
};

Fraction& operator*(Fraction const& value1, Fraction const& value2)
{
	Fraction result;
	result.numerator = value1.numerator * value2.numerator;
	result.denominator = value1.denominator * value2.denominator;
	return result;
};

Fraction& operator/(Fraction const& value1, Fraction const& value2)
{
	Fraction result;
	result.numerator = value1.numerator * value1.denominator;
	result.denominator = value1.denominator * value2.numerator;
	return result;
};
