
#include "pch.h"
#include <iostream>
#include "lib.h"
int main()
{
	matrix matrA, matrB, res;
	matrA.input();
	matrB.input();
	(matrA + matrB).print();
	(matrA * matrB).print();
	(matrA - matrB).print();
	return 0;
}