#include <iostream>
#include<time.h>
#include<algorithm>

/*Реализуйте шаблонные функции для поиска максимума,
минимума, сортировки массива (любым алгоритмом со-
ртировки), двоичного поиска в массиве, замены элемента
массива на переданное значение.*/

template<typename T>
T funcMax(T* arr, T size)		//для поиска максимума
{
	T max=-100;
	for (size_t i = 0; i < size; i++)
	if (max < arr[i]) max = arr[i];
	return max;
}
template<typename T>			//для поиска минимума
T funcMin(T* arr, T size)
{
	T min = 100;
	for (size_t i = 0; i < size; i++)
	if (min > arr[i]) min = arr[i];
	return min;
}
template<typename T>			// сортировки массива
T FuncSort(T *arr, T size)
{
	std::sort (arr, arr + size);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " -> ";
			if (i == 2 || i == 5)
				std::cout << "\n";
		}
		return *arr;
}

template<typename T>			//двоичного поиска в массиве
T funcSearch(T *arr, T size, T num)
{
	bool flag = false;

	T left = 0;
	T right = 8;
	T mid;

	while ((left <= right) && (flag != true))
	{
		mid = (left + right) / 2; 

		if (arr[mid] == num) flag = true;
		if (arr[mid] > num) right = mid - 1;
		else left = mid + 1;
	}

	if (flag) std::cout << "element " << num << " ot  nachala budet " << mid + 1 << "\n\n";
	else std::cout << " \nunknown object.\n\n";
	return 0;
}
template<typename T>			//замены элемента массива на переданное значение.
T funcShift(T* arr, T entr,  T n_num)
{
	arr[entr-1] = n_num;
	return *arr;
}

int main()
{

	int size=9;
	int* arr = new int(size);
	srand(time(NULL));
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 30 + 10;
		std::cout << arr[i] << " -> ";
		if (i==2||i==5)
			std::cout << "\n";
	}
	std::cout << "\n\n";
	std::cout << "Max num >> " << funcMax(arr, size) << "\n";
	std::cout << "Min num >> " << funcMin(arr, size) << "\n";
	std::cout << " \nsort up >>\n";
	FuncSort(arr, size); std::cout << "\n";
	
	int num ;
	std::cout << "\n please enter search num \n >> "; std::cin >> num;
	funcSearch(arr, size, num); std::cout << "\n";

	std::cout << "\nwhat object to replace? "; int entr;
	std::cin >> entr;
	std::cout << "\n what to replace? "; int n_num;
	std::cin >> n_num;
	funcShift(arr, entr, n_num);
	for (size_t i = 0; i < size; i++)
	{
		if (i==entr-1)
			std::cout << "{changed}";

		std::cout << arr[i] << " -> ";
		if (i == 2 || i == 5)
			std::cout << "\n";
	}
	return 0;
	
}