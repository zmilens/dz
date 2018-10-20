// matrix.cpp 
//

#include "pch.h"
#include <iostream>
using namespace std;
class matrix
{
private:
	//свойства класса
	double matr[10][10];
	int rows;
	int columns;
	int result[10][10];
public:
	matrix();
	~matrix();

	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	void transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	int getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get elenent. Index Error!\n";
		return -1;
	}
	void printM()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i][j];
			}
		}
	};
	void printR()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << result[i][j];
			}
		}
	};
};
class vector
{
private:
	int vec[10];
	int n;
public:
	int getN() 
	{
		return n;
	}
	int getEl(int n);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			cout << vec[i];
		}
	};
	bool multvec(vector vec2);
};

int main()
{
	matrix matrA, matrB;
	vector vecA, vecB;
	/*matrA.input();
	matrB.input();
	matrA.transp(); matrA.print();
	matrA.summMatrix(matrB); matrA.print();
	matrA.multMatrix(matrB); matrA.print();
	*/
	vecA.enter();
	int k;
	cout << "k="; 
	cin >> k;
	vecA.kvec(k);
	return 0;
}

matrix::matrix()
{
}
matrix::~matrix()
{
}
bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
		return true;
		printM();
	}
	else
		return false;
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < matr2.getRows(); i++)
		{
			for (int j = 0; j < columns; j++)
			{
				int summ = 0;
				for (int k = 0; k < rows; k++)
				{
					summ += matr[i][k] * matr2.getElem(k, j);
				}
				result[i][j] = summ;
			}
		}
		printR();
		return true;
	}
	else return false;
}
void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[i][j];
		}
	}
}

bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	if (rows < 1 && rows >10) { return false; }
	cout << "columns";
	cin >> columns;
	if (columns < 1 || columns>10) { return false; }
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j << columns; j++)
		{
			cin >> matr[i][j];
		}
	}
	return true;
}
int vector::getEl(int n)
{
	if (n < 11 && n>0)
		return vec[n];
	else
	{
		cout << "error";
		return -1;
	}
}
bool vector::enter()
{
	cout << "n=";
	cin >> n;
	if (n < 1 || n>10)
		return false;
	for (int j = 0; j < n; j++)
	{
		cin >> vec[j];
	}
	return true;
}
bool vector::multvec(vector vec2)
{
	int s = 0;
	if (n = vec2.getN())
	{
		for (int i = 0; i < n; i++)
		{
			s += vec[i] * vec2.getEl(i);
		}
		cout << s;
	}
	else return false;
}











