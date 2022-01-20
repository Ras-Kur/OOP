#include<iostream>
class Massiv2
{
	int* arr = new int[2];
public:
	Massiv2() { std::cout << "constr"; };
	Massiv2(const Massiv2& cop_ob)
	{
		arr = new int[2];
	}
	~Massiv2() {
		std::cout << "destr";
		delete[] arr;
		arr = nullptr;
	};
	void print()
	{
		for (size_t i = 0; i < 2; i++)
		{
			std::cout << arr << "     ";
		}
		std::cout << "\n";
	};

	
};
void Func(Massiv2 obj)
{
	obj.print();
};
int main()
{
	Massiv2 array;
	array.print();
	Func(array);
}
