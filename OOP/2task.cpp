/*Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего клас-
са. Наполните класс переменными-членами, функция-
ми-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность до-
бавлять новых абонентов, удалять абонентов, искать або-
нентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

class PhoneBook
{
	std::string name;
	int home_phone;
	int work_phone;
	int mobile_phone;
	std::string additional_contact_information;

public:

	PhoneBook()
	{
		name = "unknown";
		home_phone = {};
		work_phone = {};
		mobile_phone = {};
		additional_contact_information = "unknown info";
		std::cout << name << "\n";
	};

	~PhoneBook() {};

	void Create()
	{
		std::cout << "\n enter name subscriber..\n>> ";
		std::cin >> name;
		std::cout << "\n enter home phone number..\n>> ";
		std::cin >> home_phone;
		std::cout << "\n enter work phone number subscriber..\n>> ";
		std::cin >> work_phone;
		std::cout << "\n enter mobile phone number subscriber..\n>> ";
		std::cin >> mobile_phone;
		std::cout << "\n enter additional contact information..\n>> ";
		std::cin >> additional_contact_information;
	}

	void PrintInfo()
	{
		std::cout << "\n\n name - " << name << "\n home_phone - " << home_phone << "\n\n work_phone - "\
			<< work_phone << "\n\n mobile_phone - " << mobile_phone << "\n\n additional_contact_information - "\
			<< additional_contact_information << "\n\n";
	}
	
	void Delete()
	{
		name = "unknown";
		home_phone = {};
		work_phone = {};
		mobile_phone = {};
		additional_contact_information = "unknown info";
		std::cout << name << "\n";
	};
};
 

int main()
{
	//std::ofstream output_file("phoneBook.txt");
	
	/*Предоставьте пользователю возможность до-
бавлять новых абонентов, удалять абонентов, искать або-
нентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.*/
	 PhoneBook subscriber [11];
	int menu=-1, i=-1;
	
do
{
	for (size_t i = 0; i < 11; i++)
	{
		//system("cls");
		std::cout << "\n \t phone Book\n\n";
		std::cout << " 1 - add a subscriber\n 2 - remove a subscriber\
		\n 3 - search for a subscriber\n 4 - show all\n 0 - exit\n\n \tYou choose.. >>";
		std::cin >> menu;

		//system("cls");
		std::cout << i;
		switch (menu)
		{
		case 1:
			subscriber[i].Create();
			break;
		case 2:
			subscriber[i].Delete();
			break;
		case 3:

			break;
		case 4:
			for (size_t j = 0; j < 11; j++)
			{
				subscriber[i].PrintInfo();
				std::cout << "\n-- -- --\n";
			}
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
	
} while (!i==10);
}

