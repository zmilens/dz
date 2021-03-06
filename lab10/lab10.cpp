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
#include <sstream>


class matrix
{
private:
	int columns;
	int rows;
	double * matr = new double[rows*columns];
	double * res = new double[rows*columns];
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
	matrix matrA, matrB, res;
	matrA.input();
	matrB.input();
	(matrA+matrB).print();
	(matrA * matrB).print();
	(matrA - matrB).print();
	return 0;
}
matrix::matrix() {}
matrix::~matrix() {}

matrix operator+(const matrix & matr1, matrix & matr2)
{
	std::cout << "matrA+matrB" << std::endl;
	if (matr1.rows == matr2.rows && matr1.columns == matr2.columns)
	{
		matrix res;
		res.rows = matr1.rows;
		res.columns = matr1.columns;
		res.matr = new double[res.rows * res.columns];
		for (int i = 0; i < matr1.rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				res.matr[i*matr1.columns + j] = matr2.getElem(i, j) + matr2.getElem(i,j);
			}
		}
		return res;
	}
	else
	{
		std::cout << "ERROR!" << std::endl;
		return matr1;
	}
}
matrix operator*(const matrix & matr1, matrix & matr2)
{
	std::cout << "matrA*matrB" << std::endl;
	if (matr1.rows == matr2.columns)
	{
		matrix res;
		res.rows = matr1.rows;
		res.columns = matr2.columns;
		res.matr = new double[res.rows * res.columns];
		for (int i = 0; i < matr1.rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int summ = 0;
				for (int p = 0; p < matr2.columns; p++)
				{
					summ += matr1.matr[i*matr2.rows + p] * matr2.getElem(p, j);
				}
				res.matr[i*matr2.getColumns() + j] = summ;
			}
		}
		return res;
	}
	else
	{
		std::cout << "ERROR!";
		return matr1;
	}
}
matrix operator-(const matrix & matr1, matrix & matr2) 
{
	std::cout << "matrA-matrB" << std::endl;
	if (matr1.rows == matr2.rows && matr1.columns == matr2.columns)
	{
		matrix res;
		res.rows = matr1.rows;
		res.columns = matr1.columns;
		res.matr = new double[res.rows * res.columns];
		for (int i = 0; i < matr1.rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				res.matr[i*res.columns + j] = matr1.matr[i*res.columns+j] - matr2.getElem(i, j);
			}
		}
		return res;
	}
	else return matr1;
}
std::ostream & operator <<(std::ostream&os, matrix &matr2)
{
	for (int i = 0; i < matr2.rows; i++)
	{
		for (int j = 0; j < matr2.columns; j++)
		{
			os << matr2.matr[i*matr2.columns + j] << ' ';
		}
		os << '\n';
	}
	return os;
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
}