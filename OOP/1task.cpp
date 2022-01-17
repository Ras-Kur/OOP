/*Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).*/
#include<iostream>
#include <conio.h>
   
class Fraction // fraction - переводится как "фракция, доля, часть, дробь, частица, крупица"
{
	int numerator = -1; // numerator переводится как "числитель, нумератор, числитель дроби, счетчик, вычислитель"
	
	int denominator = -1; // denominator переводится как "знаменатель, делитель"
	
public:
	Fraction() {};
	Fraction(int new_numerator, int new_denominator)
	{
		numerator = new_numerator;
		denominator = new_denominator;
	}
	void  EnteringFractions()// -ввод дроби
	{
		std::cin >> numerator;
		std::cout << "   /\n   ";
		std::cin >> denominator;
	};
	void ShowFraction()// - показать дробь.
	{
		std::cout << "\n"<< numerator << "/" << denominator << "\n";
	};
	
	Fraction Сompute(Fraction* fraction1, Fraction* fraction2, int selected_symbol)
	{	  // compute - вычисление
		Fraction result;
		if (selected_symbol == 1)
		{
			result.numerator = (fraction1->numerator * fraction2->denominator)+(fraction2->numerator*fraction1->denominator);
			result.denominator = fraction1->denominator * fraction2->denominator;
		}if (selected_symbol==2)
		{
			result.numerator = (fraction1->numerator * fraction2->denominator) - (fraction2->numerator * fraction1->denominator);
			result.denominator = fraction1->denominator * fraction2->denominator;
		}if (selected_symbol==3)
		{
			result.numerator = fraction1->numerator * fraction2->numerator;
			result.denominator = fraction1->denominator * fraction2->denominator;
		}if (selected_symbol==4)
		{
			result.numerator = fraction1->numerator * fraction2->denominator;
			result.denominator = fraction1->denominator * fraction2->numerator;
		}
		return result;
	}
	
	
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
	
	if (symbol == 1)
		ch_symbol = '+';
	if (symbol == 2)
		ch_symbol = '-';
	if (symbol == 3)
		ch_symbol = '*';
	if (symbol == 4)
		ch_symbol = '/';


	new_fraction1.ShowFraction();
	std::cout << (char)ch_symbol;
	new_fraction2.ShowFraction();
	std::cout << " = ";
	Fraction new_fraction3;
	new_fraction3.Сompute(&new_fraction1, &new_fraction2, symbol).ShowFraction();
	
	std::cout << "\n press any key to exit\n"; //нажмите любую клавишу, что бы выйти
	std::cin.get();
	std::cin.get();
	
	system("cls");
	//system("pause"); можно использовать вместо последних 4 строк.
	return 0;
}