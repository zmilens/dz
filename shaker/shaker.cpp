// shaker.cpp 
//

#include "pch.h"
#include <iostream>

int a, left, right, size;
int *b;
int func()
{
	left = 0;
	right = size - 1;
	while (left < right) {
		for (int i = left; i < right; i++) {
			if (b[i] > b[i + 1]) {
				a  = b[i];
				b[i] = b[i + 1];
				b[i + 1] = a;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (b[i - 1] > b[i]) {
				a = b[i];
				b[i] = b[i - 1];
				b[i - 1] = a;
			}
		}
		left++;
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


