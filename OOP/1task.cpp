/*Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).*/
#include<iostream>
class Drobi
{
	int x, y;
	
public:
	Drobi() {};
	Drobi(int new_x, int new_y)
	{
		x = new_x;
		y = new_y;
	}
	void  Enter_drob()
	{
		std::cin >> x;
		std::cin >> y;
	};
	void Print_drob()
	{
		std::cout << x << "/" << y;
	};
	
	Drobi Znaki(Drobi* nd1, Drobi* nd2, int entr_znak)
	{
		Drobi result_drob;
		if (entr_znak == 1)
		{
			result_drob.x = (nd1->x * nd2->y)+(nd2->x*nd1->y);
			result_drob.y = nd1->y * nd2->y;
		}if (entr_znak==2)
		{
			result_drob.x = (nd1->x * nd2->y) - (nd2->x * nd1->y);
			result_drob.y = nd1->y * nd2->y;
		}if (entr_znak==3)
		{
			result_drob.x = nd1->x * nd2->x;
			result_drob.y = nd1->y * nd2->y;
		}if (entr_znak==4)
		{
			result_drob.x = nd1->x * nd2->y;
			result_drob.y = nd1->y * nd2->x;
		}
		return result_drob;
	}
	
	
};

int main()
{
	int znak =0;
	char znak_simbol = '.';
	Drobi d1;
	Drobi d2;
	std::cout << "\npleas enter drob №1>\n>";
	d1.Enter_drob();
	d1.Print_drob();
	std::cout << "\npleas enter drob №2>\n>";
	d2.Enter_drob();
	d2.Print_drob();
	std::cout << "\ngo to arifmetik znak(1 = +, 2 = -, 3 = *, 4 = /.) >\n";
	std::cin >> znak;
	if (znak == 1)
		znak_simbol = '+';
	if (znak == 2)
		znak_simbol = '-';
	if (znak == 3)
		znak_simbol = '*';
	if (znak == 4)
		znak_simbol = '/';


	d1.Print_drob();
	std::cout << (char)znak_simbol;
	d2.Print_drob();
	std::cout << " = ";
	Drobi d3;
	d3.Znaki(&d1, &d2, znak).Print_drob();
	//d3.Print_drob();
	

}