// caesar.cpp 


#include "pch.h"
#include <iostream>

char a[40] = {};
char func()
{
	for (int b = 0; b < strlen(a); b++) {
		a[b] += 3;
		if (((a[b] > 'Z') && (a[b] < 'a')) || (a[b] > 'z'))
			a[b] = a[b] - 26;
	}
	return 0;
}


int main()
{
	std::cin >> a;
	func();
	std::cout << a;
}



