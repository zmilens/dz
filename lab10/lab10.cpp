// lab10.cpp 
//ПЕРЕГРУЗКА ФУНКЦИЙ, МЕТОДОВ И ОПЕРАТОРОВ
//Перегрузка (overloading) - объявление нескольких функций, а также методов 
//классов и операторов, которые тоже являются функциями с одинаковыми именами, 
//но разным набором аргументов.

//унарные и бинарные операторы перегружаются по-разному.
//унарные - в самом классе (получается новый метод класса)
//бинарные - как отдельная функция
	
//бинарные операторы прописываются вне класса, так как результат не обязательно 
//записывается в один из операндов, а может записываться в некий третий объект 

//в унарных операторах результат записывается в тот же самый объект, 
//для которого вызван оператор, поэтому унарный стоит отнести к методам класса.


#include "pch.h"
#include <iostream>


class matrix
{
private:
	int columns;
	int rows;
	double * matr = new double[rows*columns];
	double * result = new double[rows*columns];
public:
	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool input();
	void transp();
	friend matrix operator+ (const matrix& matr1, matrix &matr2);
	friend matrix operator* (const matrix& matr1, matrix &matr2);
	friend matrix operator- (const matrix& matr1, matrix &matr2);
	friend std::ostream & operator << (std::ostream & ost, matrix &matr2);
	void print();
	matrix();
	~matrix();

};
int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	(matrA+matrB).print();
	(matrA * matrB).print();
	(matrA - matrB).print();
	matrA.print();
	matrB.print();
	return 0;
}
matrix::matrix() {}
matrix::~matrix() {}
/*{
	std::cout << "matrA+matrB" << std::endl;
	if (matr1.rows == matr2.rows() && (matr1.columns == matr2.columns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		return true;
	}
	else
	{
		std::cout << "columns and rows aren't equal" << std::endl;
		return false;
	}
}
bool matrix::multMatrix(matrix matr2)
{
	std::cout << "multMatrix" << std::endl;
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int summ = 0;
				for (int p = 0; p < columns; p++)
				{
					summ += matr[i*columns + p] * matr2.getElem(p, j);
				}
				result[i*matr2.getColumns() + j] = summ;
				std::cout << result[i*matr2.getColumns() + j] << ' ';

			}
			std::cout << std::endl;
		}
		return true;
	}
	else
	{
		std::cout << "columns1!=rows2";
		return false;
	}
}
int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col > -1)
	{
		return matr[row*columns + col];
	}
	else
	{
		std::cout << "ERROR\n";
		return -1;
	}
}
bool matrix::input()
{
	std::cout << "rows=";
	std::cin >> rows;
	std::cout << "columns=";
	std::cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << "matr[" << i << "][" << j << "]=";
			std::cin >> matr[i*columns + j];
		}
		std::cout << std::endl;
	}
	return true;
}
void matrix::transp()
{
	double temporary;
	std::cout << "transpMatrix" << std::endl;
	for (int i = 0; i < columns; i++)
	{
		for (int j = i; j < rows; j++)
		{
			temporary = matr[j*columns + i];
			matr[j*columns + i] = matr[i*rows + j];
			matr[i*rows + j] = temporary;
		}
	}
}
void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i*columns + j] << '\t';
		}
		std::cout << '\n';
	}
}*/