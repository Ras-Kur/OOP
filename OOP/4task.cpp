/*�������� ���������, ����������� ���������������
���. ���������� ����� ������ ��������, ����������,
����. ����� ���������� �������� ������������ ������
�������� ������ ��������. ����� ���� �������� ������
�������� ������ ����������.
������ �� ������� �������� ����������-����� � �������-�����, ������� ���������� ��� ���������� �������
������. �������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������. ��������, ���
��� � ������ ��������. �� ��������� ���������� ������
���������� �������������� (����������� �����������
����������), �������������. � main �������������� ������ ����������� ������ �������.*/

#include<iostream>
#include<string>

class House //����
{
	int floors;	// ���-�� ������
	int porch;  // ���-�� ���������
	int floor_apartments; // ���-�� ������� �� ����� �����
	std::string material; // �� ���� ���

	//Apartment* arr_apart = new Apartment[porch * floors * floor_apartments]{}; // ������ ������� c � ������ ������ ����

public:

	House()
	{
		floors = 5;
		porch = 5;
		floor_apartments = 3;
		material = "brick";// ���������
	}
	~House() {};

	House(const House& copy)//����������� �����������
	{
		floors = copy.floors;
		porch = copy.porch;
		floor_apartments = copy.floor_apartments;
		material = copy.material;
		//arr_apart = copy.arr_apart;
	}


	void Redact(int r_floors, int r_porch, int r_floor_apartaments, std::string r_material)
	{
		floors = r_floors;
		porch = r_porch;
		floor_apartments = r_floor_apartaments;
		material = r_material;

	}

	void PrintInfo()
	{
		std::cout << "\t\tHOUSE\n" << "\n material - " << material << "\n number of entrances - " << porch
					<< "\n number of floors - " << floors << "\n floor apartments - "<< floor_apartments 
					<< "\n total apartments in the house - "<< porch * floors * floor_apartments << "\n\n";
	}
};



class Apartment //����������
{
	int rooms; // ���-�� ������
	bool balcony; //������� �������
	//Human* arr_hum = new Human[];

public:
	
	Apartment()
	{
		rooms = 2;
		balcony = true;
	}
	~Apartment() {};

	Apartment(const Apartment& copy)//����������� �����������
	{
		rooms = copy.rooms;
		balcony = copy.balcony;
		//arr_hum = copy.arr_hum;

	}
	void Redact(int r_rooms, bool r_balcony)
	{
		rooms = r_rooms;
		balcony = r_balcony;
	}

	void PrintInfo()
	{
		std::string balcony_bool;
		if (balcony==true)
		{
			balcony_bool = "there is";
		}
		else
		{
			balcony_bool = "not present";
		}
		std::cout << "\n\t\t APARTAMENT\n" << "\n number of rooms -" << rooms
			<< "\n the presence of a balcony - " << balcony_bool << "\n";
		 
	}
};



class Human //��������
{
	std::string gender{};
	std::string name{};
	int age;
	bool proprietary; // ����� ������������� ��������. (�������� ��� ���)

public:

	Human()
	{
		gender = "unknown";
		name = "unknown unknown unknown";
		age = 00;
		proprietary = false;
	}
	~Human() {};

	Human(const Human& copy)//����������� �����������
	{
		gender = copy.gender;
		name = copy.name;
		age = copy.age;
		proprietary = copy.proprietary;

	}

	void Redact(std::string	n_gender, std::string n_name, int n_age, bool n_proprietary)
	{
		gender = n_gender;
		name = n_name;
		age = n_age;
		proprietary = n_proprietary;
	}

	void PrintInfo()
	{
		std::string proprietary_bool;
		if (proprietary==true)
		{
			proprietary_bool = "owner";
		}
		else
		{
			proprietary_bool = "not owner";
		}
		std::cout << "\n\t\t HUMAN\n" << "\n gender - " << gender << "\n name - " << name << "\n age - "
			<< age << "\n proprietary - " << proprietary_bool;
	}
};

int main()
{
	Human men1, men2, men3, men4;
	Apartment amt1, amt2, amt3;
	House h1, h2,h3;
	h2.Redact(2, 1, 3, "block");
	h1.PrintInfo(); h2.PrintInfo(); h3.PrintInfo();

	amt2.Redact(15, false);
	amt1.PrintInfo(); amt2.PrintInfo(); amt3.PrintInfo();

	men3.Redact("male", "Ivanov Ivan Ivanovich", 33, true);
	men1.PrintInfo();
	men2.PrintInfo();
	men3.PrintInfo();
	men4.PrintInfo();


}
