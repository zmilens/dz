// bubbles.cpp 
//

#include "pch.h"
#include <iostream>

int size, a;
int *b;
int func() {
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size - i - 1; k++) {
			if (b[k] > b[k + 1]) {
				a = b[k];
				b[k] = b[k + 1];
				b[k + 1] = a;
			}
		} 
	}
	return 0;
}


int main()
{
	std::cin >> size;
	b = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> b[i];
	}
	func();
		for (int i = 0; i < size; i++)
			std::cout << b[i] << " ";
}


