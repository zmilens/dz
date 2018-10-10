// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//указатель(pointer) - переменная, хранящая адресс(смещение) каких-либо данных, перемменных в оперативной памяти.

//1.СИНТАКСИС
//указатель объявляется как обычная переменная, но добавляется звёздочка 
//"тип_данных" * "имя_указателя (int * ptr_a);"

//фактически указатель - это unsigned int или unsigned long long c адрессом, 
//так как дробных или отрицательных адрессов нет
//ptr_a = &a;унарный оператор амперсент - оператор получения адресса 



//2.РАЗМЕР УКАЗАТЕЛЯ
// все указатели всегда одной и той разрядности(размера)
// каким бы ни был огромным тип данных (строка, объект, массив)
// указатель на него всегда будет занимать 4/8 байт, что и является основным
//преимуществом указателей std:: cout << "int pointer size = " sizeof(ptr_int) <<




//в случае сборки на х64 размер указателей будет 8 бaйт (64-разрядная адрессация)


//3.СОДЕРЖИМОЕ УКАЗАТЕЛЯ
std::cout << "ptr_int = " << ptr_int << std::endl;
std::cout << "ptr_dbl= " << ptr_dbl << std::endl;

//содержимое указателей

#include "pch.h"
#include <iostream>


int main()
{
		int arr1D[10] = { 1, 50, 11, 12, 101 };
		int b;
		double dbl;
		int * ptr_int = &b;
		double * ptr_double = &dbl;
	
		std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
		std::cout << "double pointer size = " << sizeof(ptr_double) << std::endl;
		std::cout << "char pointer size = " << sizeof(char *) << std::endl;
		std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
		std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;
		
		std::cout << "arr = " << arr1D << std::endl;
		std::cout << "*arr = arr[0] " << *arr1D << std::endl;
		std::cout << "*(arr1D+4) = arr[4] = " << *(arr1D+4) << std::endl;

		//выход за границы допустимой памяти i+-10000
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
