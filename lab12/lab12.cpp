// lab12.cpp 

#include "pch.h"
#include <iostream>
#include <Windows.h> //для использования типа CALLBACK, HINSTANCE
//явное связывание - отдаётся специальная команда на подгрузку dll внутри приложения

typedef int(CALLBACK*FUNC)(int,int,int); 
//прототип или объявление функции - инструкция для компилятора
//в каком порядке и какого размера передавать в стек параметры и какой выходной параметр

//_stdcall - компилятор передаёт параметры в стек по порядку
//_cddecl - компилятор передаёт параметры в обратном порядке
//CALLBACK - псевдоним для _stdcall
int main()
{
	//ЯВНОЕ ДИНАМИЧЕСКОЕ СВЯЗЫВАНИЕ С БИБЛИОТЕКОЙ
	//	1. Загрузка файла в dll d в ОП
	HINSTANCE esh; //ссылка(указатель) на загруженную DLL, которая будет загружаться
	esh = LoadLibrary(L"C:/Users/zagas/source/repos/ConsoleApplication5/x64/Debug/lab12dll.dll"); 
	//L означает использование 16-битных символов(только х64)
	//	2. Поиск в загруженной DLL функции по строковому имени
	FUNC fnc1 = (FUNC)GetProcAddress(esh, "discriment");
	//поиск и возвращение указателя на функцию
	std::cout << esh << std::endl; //проверка, загрузилась ли библиотека (0 - не загрузилась)
	//	3. Вызов внешней функции
	//std::cout << "FROM explicit DLL:\tfnc(10,5)=" << fnc2explicit(10.0, 5) << end;
	//getchar();

}
