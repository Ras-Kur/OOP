/*Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название». Класс должен содержать:
конструктор по умолчанию, конструктор с параметрами, при необходимости реализовать деструктор и конструктор копирования.\

Добавить методы для: 
1. Определения приблизительного объема (ширина * длина * максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).

Написать интерфейс для работы с классом. Реализовать динамический массив объектов класса с возможностью добавления,
удаления объектов из массива. Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.

Используйте explicit конструктор и константные функции-члены (например, для отображения данных о водоёме и т.д.).*/

#include<iostream>
#include<string>


class Reservoir //Разработать класс Reservoir (водоем).
{
	std::string name; // Класс должен обязательно иметь поле «название».
	int width, length, maximum_depth; // ширина,  длина,  максимальная глубина
	std::string class_reservoir;
	int buff_size = 0; // для сравнение жижи

public:

	Reservoir() :name{ "unknown" }, width{ 0 }, length{ 0 }, maximum_depth{ 0 }, class_reservoir{ "unknown" } {};//конструктор по умолчанию,
	
	Reservoir(std::string n_name, int n_w, int n_l, int n_m, std::string n_c) //конструктор с параметрами,
	{
		name = n_name, width = n_w, length = n_l, maximum_depth = n_m, class_reservoir = n_c;
	};
	Reservoir(std::string class_reservoir) : Reservoir { name,width,length,maximum_depth, class_reservoir }
	{
		ClassReservoir();
	}
	~Reservoir() {}; //при необходимости реализовать деструктор

	//Добавить методы для:

	int Volume() // 1. Определения приблизительного объема (ширина * длина * максимальная глубина);
	{
		int volume = width * length * maximum_depth;
		return volume;
	}

	int SurfaceArea() //2. Определения площади водной поверхности;
	{
		int surface_area = width * length;
		return surface_area;

	}
	std::string ClassReservoir() //определение класса водоема по формуле обьем на площадь поверхности.
	{
		
		int full_size; // тыс км
		full_size = (Volume()) * (SurfaceArea());// не уверен, но взял в скобки, что бы наверняка.
		if (full_size >= 270000000)
		{
			buff_size = 5;
			return "Ocean";		//океан
		}if (full_size < 270000000 && full_size >= 410)
		{
			buff_size = 4;
			return "Sea";		//море
		}if (full_size < 410 && full_size >= 2)
		{
			buff_size = 3;
			return "mere";		//озеро
		}if (full_size < 2 && full_size >= 0.0018)
		{
			buff_size = 2;
			return "pond";		//водоем
		}
		else
		{
			buff_size = 1;
			return "puddle";	//лужа
		}
	};



};


int main()
{
	Reservoir ar, ar2;
	if ()
	{

	}
	

	return 0;

}