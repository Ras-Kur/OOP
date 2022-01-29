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
#include<vector>


class Reservoir //Разработать класс Reservoir (водоем).
{
	std::string name; // Класс должен обязательно иметь поле «название».
	int width, length, maximum_depth; // ширина,  длина,  максимальная глубина
	std::string class_reservoir;
	int buff_size = 0; // для сравнение жижи

public:

	Reservoir() :name{ "unknown" }, width{ 0 }, length{ 0 }, maximum_depth{ 0 }, class_reservoir{ "unknown" } {};//конструктор по умолчанию,
	
	Reservoir(std::string n_name, int n_w, int n_l, int n_m) //конструктор с параметрами,
	{
		name = n_name, width = n_w, length = n_l, maximum_depth = n_m;
	};
	
	~Reservoir() {}; //при необходимости реализовать деструктор

	//Добавить методы для:

	int Volume(Reservoir obj) // 1. Определения приблизительного объема (ширина * длина * максимальная глубина);
	{
	   int volume = obj.width * obj.length * obj.maximum_depth;
		return volume;
	}

	int SurfaceArea() //2. Определения площади водной поверхности;
	{
		int surface_area = width * length;
		return surface_area;

	}
	std::string ClassReservoir(Reservoir obj) //определение класса водоема по формуле обьем на площадь поверхности.
	{

		int full_size; // тыс км
		full_size = (Volume(obj)) * (SurfaceArea());// не уверен, но взял в скобки, что бы наверняка.
		if (full_size >= 270000000)
			buff_size = 5; return "Ocean";			//океан
		if (full_size < 270000000 && full_size >= 410)
			buff_size = 4; return "Sea";			//море
		if (full_size < 410 && full_size >= 2)
			buff_size = 3; return "mere";			//озеро
		if (full_size < 2 && full_size >= 0.0018)
			{buff_size = 2; return "pond";}			//водоем
		else
			buff_size = 1; return "puddle";			//лужа

	};
	
	friend Reservoir& CopyReservoir(Reservoir& object1, Reservoir& object2);
	void Print()
	{
		std::cout << class_reservoir << name << length << width << maximum_depth;
	}
};
void AreaComparison(Reservoir object1, Reservoir object2)		// Для сравнения площади водной поверхности водоемов одного типа;
{
	if (object1.ClassReservoir(object1) == object2.ClassReservoir(object2))
	{
		if (object1.SurfaceArea() > object2.SurfaceArea())
			std::cout << "\nobject1 > object2\n";
		if (object1.SurfaceArea() < object2.SurfaceArea())
			std::cout << "\nobject1 < object2\n";
		else
			std::cout << "\nobject1 = object2\n";
	}
}
Reservoir& CopyReservoir(Reservoir& object1, Reservoir& object2)   // Для копирования объектов;
{
	object1.class_reservoir = object2.class_reservoir;
	object1.name = object2.name;
	object1.length = object2.length;
	object1.width = object2.width;
	object1.maximum_depth = object2.maximum_depth;
	return object1;
}

int main()
{
	setlocale(LC_ALL, "ru");

	
	std::string name; int width, length, maximum_depth; std::string class_reservoir;


	                                //Написать интерфейс для работы с классом -->

	std::cout << "\n\tсоздание !!!  1  !!! обьекта - водоем.\n" << "..введите название.. ";		std::cin >> name;
	std::cout << "\n..введите ширину; длину; глубину (макс.);.. \n";		std::cin >> width;			 std::cout << "; ";
	std::cin >> length;							std::cout << "; ";		std::cin >> maximum_depth;	 std::cout << "; ";
	 Reservoir ar1(name, width, length, maximum_depth);

	 std::cout << "\n\tсоздание !!!  2  !!! обьекта - водоем.\n" << "..введите название.. ";		std::cin >> name;
	 std::cout << "\n..введите ширину; длину; глубину (макс.);..\n ";		std::cin >> width;			 std::cout << "; ";
	 std::cin >> length;							std::cout << ";\n ";		std::cin >> maximum_depth;	 std::cout << "; ";
	 Reservoir ar2(name, width, length, maximum_depth);

	 std::vector<Reservoir> object(0) ;   //Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
	// object.push_back(ar1);
	 //object.push_back(ar2);
	 //object.erase(object.begin());
	 //object.erase(object.begin()+1);

	std::cout << "1. Определения приблизительного объема (ширина * длина * максимальная глубина)\n2. Определения площади водной поверхности\
		 \n3. Метод для проверки относятся ли водоемы к одному типу(море - море; бассейн - пруд); \
		 \n4. Для сравнения площади водной поверхности водоемов одного типа \n5. Для копирования объектов \n\n\t\t >>>>_";
	int num = 0;
	std::cin >> num;
	switch (num)
	{
	case 1:
		std::cout <<ar1.Volume(ar1);

		break;
	case 2:
		std::cout << ar1.SurfaceArea();
		break;
	case 3:
		std::cout << ar1.ClassReservoir(ar1);
		break;
	case 4:
		AreaComparison(ar1, ar2);
		break;
	case 5:
		CopyReservoir(ar1, ar2).Print();

		break;
	default:
		std::cout << " \n\n\texit\n\n\n";
		return 0;
		break;
	}
	return 0;
	
	
	/////Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.

	////	Используйте explicit конструктор и константные функции - члены(например, для отображения данных о водоёме и т.д.).* /

	//  не делал. 
}