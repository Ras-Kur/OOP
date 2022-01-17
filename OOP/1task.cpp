/*���������� ����� �����. ���������� ������� ���������
� ����������� � �������� ����������-������. ����������
�������-����� ��� ����� ������ � ����������-�����,
��� ���������� �������������� �������� (��������,
���������, ���������, �������, � �.�.).*/
#include<iostream>
#include <conio.h>
   
class Fraction // fraction - ����������� ��� "�������, ����, �����, �����, �������, �������"
{
	int numerator = -1; // numerator ����������� ��� "���������, ���������, ��������� �����, �������, �����������"
	
	int denominator = -1; // denominator ����������� ��� "�����������, ��������"
	
public:
	Fraction() {};
	Fraction(int new_numerator, int new_denominator)
	{
		numerator = new_numerator;
		denominator = new_denominator;
	}
	void  EnteringFractions()// -���� �����
	{
		std::cin >> numerator;
		std::cout << "   /\n   ";
		std::cin >> denominator;
	};
	void ShowFraction()// - �������� �����.
	{
		std::cout << "\n"<< numerator << "/" << denominator << "\n";
	};
	
	Fraction �ompute(Fraction* fraction1, Fraction* fraction2, int selected_symbol)
	{	  // compute - ����������
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
	
	std::cout << "\n please enter the first fraction\n > ";//����������, ������� ������ �����
	new_fraction1.EnteringFractions();
	std::cout << "\n ";
	new_fraction1.ShowFraction();
	
	std::cout << "\n please enter the second fraction\n > ";//����������, ������� ������ �����
	new_fraction2.EnteringFractions();
	std::cout << "\n ";
	new_fraction2.ShowFraction();
	
	std::cout << "\n select arithmetic sign\n (1 = +, 2 = -, 3 = *, 4 = /.) \n > ";//�������� �������������� ����
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
	new_fraction3.�ompute(&new_fraction1, &new_fraction2, symbol).ShowFraction();
	
	std::cout << "\n press any key to exit\n"; //������� ����� �������, ��� �� �����
	std::cin.get();
	std::cin.get();
	
	system("cls");
	//system("pause"); ����� ������������ ������ ��������� 4 �����.
	return 0;
}