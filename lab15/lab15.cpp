// lab15.cpp 
#include "pch.h"
#include <iostream>
#include <string>
#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива

int main()
{
	setlocale(LC_ALL, "rus");
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).
	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.
	Достоинство: операции удаления и добавления элемента делаются за const время.
	*/
	/*std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека 
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: "<<std::endl;
	while (i != 5) 
	{
		std:: cin >> a;
		stackInt.push(a); // добавляем введенное число 
		i++;
	}
	if (stackInt.empty()) // проверяем пуст ли стек (нет) 
		std::cout << "Стек не пуст";
	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop(); // удаляем верхний элемент 
	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;
	// ЗАДАНИЕ 1 
	/*
	Проверить правильность расстановки скобок (,),[,],{,}
	в введенном пользователем выражении за линейное время
	(один просмотр выражения).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/
	//решение 
	/*
	Считываем элемент.
	Если это (,[ или {, то помещаем ее в стек.
	Если это ),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.
	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/
	std::cout << "Zadanie 1" << std::endl;
	std::stack <char> z1;
	char a;
	while (1)
	{
		std::cin >> a;
		if (a == 'q')
		{
			std::cout << "yes";
			break;
		}
		if (a == '(' || a == '{' || a == '[') z1.push(a);
		if (a == ')')
		{
			if ('(' == z1.top())
			{
				z1.pop();
			}
			else
			{
				std::cout << "no";
				break;
			}
		}
		if (a == ']')
		{
			if ('[' == z1.top())
			{
				z1.pop();
			}
			else
			{
				std::cout << "no";
				break;
			}
		}	
	}
	
	/*
	if (stackInt.empty())
		std::cout << " ";
	std::cout << " " << stackInt.top() << std::endl;
	stackInt.pop();
	std::cout << " " << stackInt.top() << std::endl;
	/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/
	/*std::queue <int> MyQueue; // создали очередь 
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // добавляем в очередь элементы 
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // удаляем элемент из очереди 
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;
	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет) 
		std::cout << "Очередь не пуста!";
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/
	/*std::priority_queue <int> priority_q; // объявляем приоритетную очередь 
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // добавляем элементы в очередь 
	}
	// выводим первый 
	std::cout << "Первый элемент очереди: " << priority_q.top();
	// ЗАДАНИЕ 2 
	/*
	Программа на вход получает список школьников.
	В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
	затем (через пробел) – фамилия.
	Необходимо вывести список по классам:
	сначала всех учащихся 9 класса, затем – 10, затем – 11.
	Внутри одного класса порядок вывода должен быть таким же, как на входе.

	*/
	/*
	Создаем 3 очереди (свою для каждого класса).
	Считываем очередную строку. В зависимости от класса
	добавляем фамилию в соответствующую очередь
	Когда все считали, выводим очереди последовательно:
	сначала для 9 класса, затем очередь 10 класса,
	а в самом конце очередь 11 класса.
	*/
	std::cout << "Zadanie 2" << std::endl;
	std::queue <std::string> class9;
	std::queue <std::string> class10;
	std::queue <std::string> class11;
	std::string n;
	int c;
	std::cin >> c;
	for (;;) 
	{
		if (c == 0)
			break;
		else 
		{
			getline(std::cin, n);
			switch (c)
			{
			case9:
				class9.push(n);
				break;
			case10:
				class10.push(n);
				break;
			case11:
				class11.push(n);
				break;
			}
			std::cin >> c;
		}
	}
	std::cout << '9' << std::endl;
	while (!class9.empty())
	{
		std::cout << class9.front() << std::endl;
		class9.pop();
	}
	std::cout << '10' << std::endl;
	while (!class10.empty())
	{
		std::cout << class10.front() << std::endl;
		class10.pop();
	}
	std::cout << '11' << std::endl;
	while (!class11.empty())
	{
		std::cout << class11.front() << std::endl;
		class11.pop();
	}
	/*
	Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно
	удалять и добавлять элементы
как в начало, так и в конец.
Дек хранится в памяти так же, как и очередь.
*/
	/*std::deque<int> dequeInt; //deque <тип данных> <имя>; - создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел:" << std::endl;
	while (i != 5)
	{
		std::cin >> a;
		deque.push_back(a); //добавляем введенное число
		deque.push_front(a);
		i++;
	}
	if (deque.empty()) //проверяем пуст ли дек (нет)
		std::cout << "Дек не пуст";
	std::cout << "Верхний элемент дека" << deque.back() << std::endl;
	deque.pop_back(); //удаляем верхний элемеент
	std::cout << "Новй элемент дека:" << deque.back() << std::endl;
//ЗАДАЧА 3 
/*
Проверить, является ли введенная строка палиндромом
(читается одинаково слева направо и справа налево). Использовать дек.
*/
std::cout << "Zadanie 3" << std::endl;
std::deque <char> sl;
char a;
std::cin >> a;
for (;;)
{
	if (a == '.')
		break;
	else
		sl.push_front(a);
		std::cin >> a;
}
while (!sl.empty())
{
	if (sl.front() != sl.back())
		break;
	else if (sl.front() == sl.back())
	{
		sl.pop_back();
		if (!sl.empty())
			sl.pop_front();
	}
}
if (sl.empty())
	std::cout << "yes" << std::endl;
else std::cout << "no" << std::endl;
/*
Считываем строку посимвольно. каждый символ добавляем в хвост дека.
Далее сравниваем первый и последний символ дека.
*/
//ЗАДАЧА 4 
/*
Описать структуру данных List.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление,
сортировка.
*/
std::cout << "Zadanie 4" << std::endl;
std::list <int> list;
int a;
for (int i = 0; i < 4; i++)
{
	std::cin >> a;
	if (i == 0)
		list.push_front(a);
	else list.push_back(a);
}
list.sort();
list.pop_front();
list.pop_back();
for (std::list <int>::iterator i = list.begin(); i != list.end(); i++)
{
	std::cout << *i;
}
list.clear();
//ЗАДАЧА 5 
/*
Описать структуру данных Set.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление.
*/
std::cout << "Zadanie 5" << std::endl;
std::set<int> set;
int a;
for (int i = 0; i < 5; i++) 
{
	std::cin >> a;
	set.insert(a);
}
for (std::set <int>::iterator i = set.begin(); i != set.end(); i++) 
{
	std::cout << *i << ' ';
}
set.erase(3);
std::cout << std::endl;
for (std::set<int>::iterator i = set.begin(); i != set.end(); i++) 
{
	std::cout << *i << ' ';
}
//ЗАДАЧА 6 
/*
Описать структуру данных map.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление.
*/
std::cout << "Zadanie 6" << std::endl;
std::map <char, int> map;
std::map<char, int>::iterator m;
char a;
for (int i = 0, a = 'b'; i < 5; ++i, ++a)
{
	map.insert(std::pair<char, int>(a, i));
}
for (auto t = map.begin(); t != map.end(); ++t)
{
	std::cout << (*t).first << " : " << (*t).second << std::endl;
}
std::cout << std::endl;
m = map.find('c');
std::cout << std::endl;
map.erase('d'); 
map.insert(m, std::pair<char, int>('d', 200)); 
for (auto t = map.begin(); t != map.end(); ++t)
{
	std::cout << (*t).first << " : " << (*t).second << std::endl;
}
// ЗАДАЧА 7 
/*
Составить таблицу сравнения по времени выполнения операций
для дека, стека, очереди, списка, множества, массива из n элементов.
Список операций:
добавление в начало
добавление в конец
добавление в середину
удаление из начала
удаление с конца
удаление из середины
значение элемента из начала
значение элемента с конца
значение элемента из середины
*/
	system("pause");
	return 0;
}