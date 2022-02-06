/*Создайте класс с именем Date для хранения даты (или
используйте ранее созданный).
В классе должна быть функция-член, которая увеличи-
вает день на 1.
Напишите соответствующие конструкторы и функци-
и-члены.
В классе должны быть перегружены операциии ++, -- ,
!=, ==, >, <, >>, <<, =, +=, -=, ().
Используйте обычную и дружественную перегрузку.*/

#include <iostream>

class Date							//класс с именем Date для хранения даты
{
	int day, month, year;

public:

	Date() :day(1), month(1), year(2020) {}; // конструктор по умолчанию

	Date(int day, int month, int year)
	{
		this->day = day;
		this->year = year;
		this->month = month;
	}

	void DayPlus(){this->day++;}	//функция, которая увеличивает день на 1.

	friend Date operator ++(Date const obj);
	friend Date operator --(Date const obj);
	friend bool operator > (Date const obj, Date const obj2);
	friend bool operator < (Date const obj, Date const obj2);
	friend bool operator !=(Date const obj, Date const obj2);
	friend bool operator ==(Date const obj, Date const obj2);
	friend std::istream& operator >>(std::istream& input,  Date& obj);
	friend std::ostream& operator <<(std::ostream& output, Date& obj);

	Date operator ()(Date const obj) { day = obj.day;  month = obj.day;    year = obj.day;  }
	Date operator = (Date const obj) { day = obj.day;  month = obj.month;  year = obj.year; }
	Date operator -=(Date const obj) { day -= obj.day; month -= obj.month; year -= obj.year; }
	Date operator +=(Date const obj) { day += obj.day; month += obj.month; year += obj.year; }
};
Date operator ++(Date const obj)
{
	obj.day + 1;
	obj.month + 1;
	obj.year + 1;
}
Date operator --(Date const obj) 
{
	obj.day - 1;
	obj.month - 1;
	obj.year - 1;; 
}
bool operator > (Date const obj, Date const obj2) 
{
	if (obj.day > obj2.day && obj.month > obj2.month && obj.year > obj2.year)
		return true;
	else
		return false;
}
bool operator < (Date const obj, Date const obj2) {
	if (obj.day < obj2.day && obj.month < obj2.month && obj.year < obj2.year)
		return true;
	else
		return false;
}
bool operator !=(Date const obj, Date const obj2) {
	if (obj.day != obj2.day && obj.month != obj2.month && obj.year != obj2.year)
		return true;
	else
		return false;
}
bool operator ==(Date const obj, Date const obj2) {
	if (obj.day == obj2.day && obj.month == obj2.month && obj.year == obj2.year)
		return true;
	else
		return false;
}
std::istream& operator >>(std::istream& input,  Date& obj)
{
	input >> obj.day >> obj.month >> obj.year;
	return input;
}
std::ostream& operator <<(std::ostream& output, Date& obj)
{
	output << obj.day << obj.month << obj.year;
	return output;
}

