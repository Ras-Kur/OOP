/*Создать имитационную модель "остановка маршрутных такси". Необходимо вводить следующую информацию:
среднее время между появлениями пассажиров на остановке в разное время суток, среднее время между появ-
лениями маршруток на остановке в разное время суток, тип остановки (конечная или нет). Необходимо опреде-
лить: среднее время пребывание человека на остановке, достаточный интервал времени между приходами марш-
руток, чтобы на остановке находилось не более N людей одновременно. Количество свободных мест в маршрутке
является случайной величиной.

Задание 2.
Разработать приложение, имитирующее очередь печати принтера. Должны быть клиенты, посылающие запросы
на принтер, у каждого из которых есть свой приоритет. Каждый новый клиент попадает в очередь в зависимости
от своего приоритета. Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.*/

#include<iostream>
#include<queue>
#include<string>
	//очередь, очередь с пиоритетами

/*		// задание первое
class Bus
{const int size = 20;
	std::queue<int> que;
	que=(int size);
	 
public:
	Bus()
	{
		std::cout <<  ;
	}
};
class BusStop
{
	bool ending_station;// конечная станция или не конечная
	int day_people;//количество людей
	int day_bus;//количество маршруток
	int day_people_time;// как часто приходят
	int day_bus_time;//как часто приезжает
	int night_people;//количество людей
	int night_bus;//количество маршруток
	int night_people_time;// как часто приходят
	int night_bus_time;//как часто приезжает
public:
	BusStop() :ending_station(false), day_people(0), day_bus(0), day_people_time(0), day_bus_time(0),
		night_people(0), night_bus(0), night_people_time(0), night_bus_time(0) {};
	BusStop(bool e_s,int day_p_t,int day_b_t, int night_p_t, int night_b_t):BusStop() 
	{//передаю время днем людей и автобусов и ночью сразу
		ending_station = e_s;
		day_people_time = day_p_t; day_bus_time = day_b_t;
		night_people_time = night_p_t; night_bus_time = night_b_t;
	};
	void PrintInfo()
	{
		std::cout << "\n ending? - " << (ending_station == true ?  " yes " :  " no ");// булевый результат в текст.
		std::cout << "\n day - time - people - " << day_people_time;
		std::cout << "\n day - time - bus - " << day_bus_time << "\n night - time - people - " << night_people_time;
		std::cout << "\n night - time - bus - " << night_bus_time << "\n";
	}
	

//определить:
//среднее время пребывание человека на остановке

//достаточный интервал времени между приходами марш-руток,
//чтобы на остановке находилось не более N людей одновременно.

//Количество свободных мест в маршрутке
//является случайной величиной


};
int main()
{
	BusStop bs1(true, 5, 15, 12, 30);
	bs1.PrintInfo();
	BusStop bs2(false, 3, 20, 25, 35);
	BusStop bs3(false, 10, 10, 22, 20);
	BusStop bs4(false, 7, 30, 30, 40);
	BusStop bs5(true, 5, 17, 19, 25);
	int n;
	n = 7;//количество н людей.
	int x;
	x = 15/5;// среднее время ожидания на остановке
	int y;
	y = x * n;
}*/                       //не смог победить очередь, слишком долго содел над задачей. не могу продолжать терять время.

			//  Задание 2.
class Client // клиент
{
	std::string query; // запрос
	int priority;     // приоритет
	int office;      // офис
public:
	Client() :query("unknown"), priority(0), office(0) {};
	Client(std::string query, int priority, int office) :Client()
	{
		this->query = query; this->priority = priority; this->office = office;
	}
	Client(int priority, int office) :Client()
	{
		this->priority = priority;
		this->office = office;
	}
	void ClQuerty(std::string str) { query = str; }
	int GetOffice() { return office; }
};
class Printer // принтер
{
	friend class Client;
	std::queue <Client> clients;
	std::priority_queue <Client> client_query;
	int* attached_offices; // прикрепленные офисы
public:
	Printer() :clients(), client_query(), attached_offices(nullptr) {};
	Printer(int* a_o_n)
	{
		for (int i = 0; i < 3; i++) {attached_offices[i] = a_o_n[i];}
	}
	int GetPQ() { return client_query.size(); }
	void Print()
	{
		for (int i = 0; i < client_query.size(); i++)
		{
			client_query.top(); client_query.pop();
		}
		
	}
	void Print_queue(Client query_print) // принтер ставит в очередь по приоретету
	{
		if ( query_print.GetOffice() == attached_offices[0] ||
			 query_print.GetOffice() == attached_offices[1] ||
			 query_print.GetOffice() == attached_offices[2]    ) //если привязан к офису
		{
			clients.push(query_print);
			client_query.push(query_print);
			std::cout << "\n document in queue, waiting for printing...\n";
		}
		else
		{
			std::cout << "\n  !!! user does not have access to this printer !!!\n";
			//			 "!!! у пользователя нет доступа к данному принтеру !!!"
		}
		if(GetPQ()==5)
		{
			std::cout << "\n document sent for printing\n"; // докумерт отправлен на печать
			Print();
		}
	}
	
};

int main()
{
	Client people1(30, 5), people2(15, 2), people3(16, 1), people4(10, 6), people5(6, 2), people6(12, 3), people7("helo world", 25, 1),
		people8("good-luck world", 12, 4), people9(22, 5), people10(3, 6), people11(" I am King!", 31, 1), people12(11, 6);
	people1.ClQuerty("people1"); people2.ClQuerty("people2"); people3.ClQuerty("people3"); people4.ClQuerty("people4");
	people5.ClQuerty("people5"); people6.ClQuerty("people6"); people7.ClQuerty("people7"); people8.ClQuerty("people8");
	people9.ClQuerty("people9"); people10.ClQuerty("people10"); people11.ClQuerty("people11"); people12.ClQuerty("people12");
	int* arr_pr1 = new int[3]{ 1,2,3 };
	int* arr_pr2 = new int[3]{ 2,3,4 };
	int* arr_pr3 = new int[3]{ 4,5,6 };
	Printer pr1(arr_pr1), pr2(arr_pr2), pr3(arr_pr3);
	pr1.Print_queue(people1); pr1.Print_queue(people2); pr1.Print_queue(people3); pr1.Print_queue(people4); pr1.Print_queue(people5);
	pr1.Print_queue(people6); pr1.Print_queue(people7); pr1.Print_queue(people8); pr1.Print_queue(people9); pr1.Print_queue(people10);
	pr1.Print_queue(people11); pr1.Print_queue(people12);

	pr2.Print_queue(people1); pr2.Print_queue(people2); pr2.Print_queue(people3); pr2.Print_queue(people4); pr2.Print_queue(people5);
	pr2.Print_queue(people6); pr2.Print_queue(people7); pr2.Print_queue(people8); pr2.Print_queue(people9); pr2.Print_queue(people10);
	pr2.Print_queue(people11); pr2.Print_queue(people12);

	pr3.Print_queue(people1); pr3.Print_queue(people2); pr3.Print_queue(people3); pr3.Print_queue(people4); pr3.Print_queue(people5);
	pr3.Print_queue(people6); pr3.Print_queue(people7); pr3.Print_queue(people8); pr3.Print_queue(people9); pr3.Print_queue(people10);
	pr3.Print_queue(people11); pr3.Print_queue(people12);

	std::cout << "\n\n\n all print doc...\n";
	pr1.Print(); pr2.Print(); pr3.Print();
		

	// не работает. ошибка непонятная.

}
