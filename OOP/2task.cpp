/*�������� ���������� "���������� �����". ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ����-
��. ��������� ����� �����������-�������, �������-
��-�������, ��������������, inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������
��� ���. ������������ ������������ ����������� ��-
������� ����� ���������, ������� ���������, ������ ���-
������ �� ���, ���������� ���� ���������, ���������
���������� � ���� � ��������� �� �����.*/
#include<iostream>
#include<string>
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
	};
	~PhoneBook() {};
	inline PhoneBook create(std::string n_name, int n_home, int n_work, int n_mobile, std::string n_info)
	{
		name = n_name;
		home_phone = n_home;
		work_phone = n_work;
		mobile_phone = n_mobile;
		additional_contact_information = n_info;
	}


};
int main()
{

}

