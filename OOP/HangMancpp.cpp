/*Создайте консольную версию игры «Виселица».

Важно:
■■ Слово выбирается компьютером из списка слов.
■■ Список слов находится в файле в зашифрованном виде.
■■ По завершении игры на экран выводится статистика игры:
• количество времени;
• количество попыток;
• искомое слово;
• буквы игрока.


■■ Слово выбирается компьютером из списка слов.
-------для этого я буду использовать текстовый файл "с набором слов".

■■ Список слов находится в файле в зашифрованном виде.
-------программа преобразует все мои слова из файла "с набором слов" к шифр каждое слово
-------после чего перепишет в новый файл "с закодированными словами"


■■ По завершении игры на экран выводится статистика игры:
-------игра это класс. - "class Game".
-------каждая игра это новый обьект класса. таким образом мы сможем сохранить
• количество времени;
• количество попыток;
• искомое слово;
• буквы игрока.

+++++++    ОБ ИГРЕ     ++++++++++
--------------в главном меню будет:
- новая игра.
- продолжить игру.
- Выбор бонусов.
- статистика игр и очков.
- опции.
- выход.

----------------в опциях:
- Выбор языка.
- Выбор сложности.
- титры с создателями.

*/

#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<random>
#include<stack>

std::string RandomWord(bool lang); // рандом достает из файла строку

std::string LevelWord(int lvl_diff, std::string text, bool lang); //сложность по кол-ву букв в слове


class Game
{
	std::string g_word;	//сохранение слов
	char user_input;//ввод пользователя
	int size; // для количества попыток
public:
	Game() {};
	bool GamePlay(std::string ng_word, int lvl_diff, bool lang) // сам движок игры или что это
	{
		//system("chcp 65001");
		bool flag = false;
		bool flag_size = false;
		bool gameover;
		int correct_result = 0;
		if (lvl_diff == 1) { size = 9; }
		if (lvl_diff == 2) { size = 8; } // сдожность влияет на кол-во попыток
		if (lvl_diff == 3) { size = 7; }
		std::string check; // для попыток угадать
		std::string user_check; // пользовательский ввод статистика.
		int r_size = ng_word.size();// что бы предлагалас одна буква
		int r_int = rand() % r_size;// для этого же

		for (size_t i = 0; i < ng_word.size(); i++)//что бы выводились "_ _ _"
			check.push_back('_');

		for (int i = 0; i < ng_word.size(); i++)
		{
			if (i == r_int)
				check.at(i) = ng_word.at(i); // нижние слеши с одной буквой для вывода
		}

		do
		{
			system("cls");

			

			std::cout << "\n\t"; // вывод нижнего слеша с буквой.
			for (size_t i = 0; i < check.size(); i++)
				std::cout << check.at(i) << " ";
			lang == true ?
				std::cout << "\n\n your letters : " ://ваши буквы
				std::cout << "\n\n ваши буквы : ";

			for (int i = 0; i < user_check.size(); i++)
				std::cout << user_check.at(i) << " ";
			lang == true ?
				std::cout << "\n\n try to guess the letter -> " :// 
				std::cout << "\n\n попробуйте угадать букву -> ";
				std::cin >> user_input;//ввод буквы пользователем
			std::cout << "\b\n";
			user_check.push_back(user_input);
			
			for (int i = 0; i < ng_word.size(); i++)
			{
				if (user_input == ng_word.at(i)) //если введенная буква есть в слове
				{
					check.at(i) = user_input;
					std::cout << check.at(i) << "\n"; 
					flag_size=true;
				}
			}
			
			if (!flag_size)
				size--;

			flag_size = false;

			for (int i = 0; i < ng_word.size(); i++)
			{
				if (check.at(i)==ng_word.at(i))           
					correct_result++;
			}
			if (correct_result == static_cast<int>(ng_word.size()))
			{
				flag = true;
				gameover = true;
			}
			correct_result = 0;
			if (size == 0)
				flag = true;
		} while (!flag);

		if (size == 0)
		 gameover = false; 

		if (gameover==true) 
		 std::cout << "\n WINER!!!!"; 
		else 
		 std::cout << "\n loser!"; 
		
		return flag;
	}
	
};


int main()
{
	
	srand(time(NULL));
	bool lang = true;  //lang != true ? std::cout << "ru" : std::cout << "en";
	int lvl_difficulty = 1;
	system("chcp 65001"); system("cls");// для вывода в консоль кириллицы
	//std::cout << RandomWord(lang) << "\n\t";
			  //<< LevelWord(lvl_difficulty, RandomWord(lang),lang);
	

	//Game g1; g1.GamePlay(LevelWord(lvl_difficulty, RandomWord(lang), lang), lvl_difficulty,lang);
	lang = false;
	lvl_difficulty = 2;
	Game g2; g2.GamePlay(LevelWord(lvl_difficulty, RandomWord(lang), lang), lvl_difficulty,lang);
}

std::string RandomWord(bool lang) // рандом достает из файла строку
{
	std::mt19937 engine;			 //	два часа искал
	engine.seed(std::time(nullptr)); // что бы был рандом
	std::random_device device;		 // из чисел больше чем
	engine.seed(device());			 // 32'767 - это предел для "rand()"

	std::ifstream file; // создал переменную для чтения файла
	// переменная для пути к файлу
	if (lang)
	{
		std::string way_n("Word_en.txt"); // английский сборник слов
		file.open(way_n);
	}
	else
	{
		std::string way_n("Word_ru.txt"); // русский сборник слов
		file.open(way_n);
	}
	std::string text;	// для записи строки из файла в память
		// открываю файл
	if (!file.is_open())	//проверка на открытие файла
		std::cout << "\n\n File not open! (Файл не открыт!)\n\n";	//если ошибка
	else
	{		// случайно выбираем строку со словом.
		long long  random = lang != true ? engine() % 67774 : engine() % 3000;//русский или английский
		for (size_t i = 0; i < random; i++)
		{
			std::getline(file, text);//записываем строку в переменную
			if (i == random - 1)
				return text;
		}
	}
	file.close();
}

std::string LevelWord(int lvl_diff, std::string text, bool lang) //сложность по кол-ву букв в слове
{
	if (lang)  // язык влияет на количество букв в сложности
	{  // сейчас английский( если true )
		std::string buff = text; // сохраняем значение из рандома что бы потом вернуть
		switch (lvl_diff) // три уровня сложности
		{
		case 1:
			if (buff.size() > 1 && buff.size() < 5)//от 2 до 4 букв
				return buff;
			else
			{     // если иф не отработал, то перезапускаем рандом пока не подойдет начение
				do { buff = RandomWord(lang); } while (buff.size() < 2 || buff.size() > 4);
				return buff;
			} break;
		case 2:
			if (buff.size() > 3 && buff.size() < 7) //от 4 до 6
				return buff;
			else
			{
				do { buff = RandomWord(lang); } while (buff.size() < 4 || buff.size() > 6);
				return buff;
			} break;
		case 3:
			if (buff.size() > 6 && buff.size() < 12) // от7 до 11 - это хард левел)
				return buff;
			else
			{
				do { buff = RandomWord(lang); } while (buff.size() < 7 || buff.size() > 11);
				return buff;
			} break;
		}
	}
	else
	{  // тут уже русский ( если false )
		std::string buff = text; // сохраняем значение из рандома что бы потом вернуть
		switch (lvl_diff) // три уровня сложности
		{
		case 1:
			if (buff.size() > 2 && buff.size() < 6)//от 3 до 5 букв
				return buff;
			else
			{     // если иф не отработал, то перезапускаем рандом пока не подойдет начение
				do { buff = RandomWord(lang); } while (buff.size() < 3 || buff.size() > 5);
				return buff;
			} break;
		case 2:
			if (buff.size() > 4 && buff.size() < 9) //от 5 до 8
				return buff;
			else
			{
				do { buff = RandomWord(lang); } while (buff.size() < 5 || buff.size() > 7);
				return buff;
			} break;
		case 3:
			if (buff.size() > 8 && buff.size() < 15) // от 9 до 14 - это хард левел)
				return buff;
			else
			{
				do { buff = RandomWord(lang); } while (buff.size() < 9 || buff.size() > 14);
				return buff;
			} break;
		}
	}
}