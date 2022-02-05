#include <iostream>
#include <string>
/*Тема: Перегрузка инкремента и декремента. Перегрузка логических операторов.
        Возврат по ссылке. Перегрузка оператора присваивания.

Задание 1.
Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция = =).
2. Операцию присваивания одного объекта в другой (операция =).
3. Сравнение по цене двух пальто одного типа (операция>).

Задание 2.
Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция = =).
2. Операцию присваивания одного объекта в другой (операция =).
3. Сравнение двух квартир по цене (операция>).*/



           /*  //<-------  ( просто поставьте ( // ) перед ( /* ) )   
      
     

class Overcoat                            // Создать класс Overcoat (верхняя одежда).
{
    std::string types_of_clothing;        //типы одежды
    int price;                            //цена

public:
    Overcoat() : types_of_clothing("unknown"), price(0) {};
    Overcoat(std::string t_o_c, int price)
    {
        types_of_clothing = t_o_c;
        this->price = price;
    }

  // Проверка на равенство типов одежды (операция = =)
   bool operator ==(const Overcoat& comparison)                      // comparison = сравнение
   {
       return this->types_of_clothing == comparison.types_of_clothing;   
   }

   // Операция присваивания одного объекта в другой (операция =)
   Overcoat& operator = (const Overcoat& assignments)               // assignments = присвоение
   {
        this->types_of_clothing = assignments.types_of_clothing;
        this->price = assignments.price;
       return *this;
   }

   //Сравнение по цене двух пальто одного типа (операция > )
   bool operator >(const Overcoat& comparison)                      // comparison = сравнение
   {
       return this->types_of_clothing > comparison.types_of_clothing;
   }

   friend std::ostream& operator <<(std::ostream& output, Overcoat object); // для вывода
};


int main()
{
    Overcoat obj1("puhovik", 500), obj2("palto", 300), obj3("puhovik", 450);

    bool result;
    result = obj1 == obj2;
    result == 0 ? std::cout << "different\n" : std::cout << "identic\n"; // если false - разые; true - одинаковые
    result = obj1 == obj3;
    result == 0 ? std::cout << "different\n" : std::cout << "identic\n"; //  Проверка на равенство типов одежды
    
    std::cout << "\n"<< obj3;
    obj3 = obj1;                    // приравнивание
    std::cout << obj3 <<"\n";

     result = obj1 > obj2;          // больше или меньше.
     result == 0 ? std::cout << "less\n" : std::cout << "larger\n";     // less - меньше. larger - больше.

   
}
std::ostream& operator <<(std::ostream& output, Overcoat object)
{
    output << "\nprice - " << object.price << " $ \n" << "types_of_clothing - " << object.types_of_clothing << "\n";
    return output;
}

        //------->   */


class Flat                            // Создать класс Flat (квартира).
{ int apartment_area;                //площадь квартиры
    int price;                            //цена

public:
    Flat() : apartment_area(0), price(0) {};
    Flat(int a_a, int price)
    {
        apartment_area = a_a;
        this->price = price;
    }

    //  Проверка на равенство площадей квартир (операция = =)
    bool operator ==(const Flat& comparison)                      // comparison = сравнение
    {
        return this->apartment_area == comparison.apartment_area;
    }

    // Операция присваивания одного объекта в другой (операция =)
    Flat& operator = (const Flat& assignments)               // assignments = присвоение
    {
        this->apartment_area = assignments.apartment_area;
        this->price = assignments.price;
        return *this;
    }

    //Сравнение двух квартир по цене (операция > )
    bool operator >(const Flat& comparison)                      // comparison = сравнение
    {
        return this->apartment_area > comparison.apartment_area;
    }

    friend std::ostream& operator <<(std::ostream& output, Flat object); // для вывода
};


int main()
{
    Flat obj1(33, 500), obj2(22, 300), obj3(33, 450);

    bool result;
    result = obj1 == obj2;
    result == 0 ? std::cout << "different\n" : std::cout << "identic\n"; // если false - разые; true - одинаковые
    result = obj1 == obj3;
    result == 0 ? std::cout << "different\n" : std::cout << "identic\n"; //  Проверка на равенство площади

    std::cout << "\n" << obj3;
    obj3 = obj1;                    // приравнивание
    std::cout << obj3 << "\n";

    result = obj1 > obj2;          // больше или меньше.
    result == 0 ? std::cout << "less\n" : std::cout << "larger\n";     // less - меньше. larger - больше.


}
std::ostream& operator <<(std::ostream& output, Flat object)
{
    output << "\nprice - " << object.price << " $ \n" << "types_of_clothing - " << object.apartment_area << "\n";
    return output;
}
