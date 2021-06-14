#include <iostream>
#include <iomanip>
#include "multmatrix.hpp"

//заполнение массива случайными числами от -5 до 5
void initArr(int** x, int row, int col)
{
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			x[i][j] = rand() % 11 - 5;
		}
	}
}

//печать массива в консоль
void printArr(int** x, int row, int col)
{
    for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << std::setw(6) << x[i][j] << std::setw(8);
		std::cout << std::endl;
	}
}

//перемножение матриц
template<typename T>
void mulMatrix(T** a,int x,int y,T** b,int n,int m)
{
    T **result = new T *[n];
    for (int i = 0; i < n; i++)
        result[i] = new T[m];
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < m; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < y; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printArr(result, n, m);

    for (int i = 0; i < n; i++)
        delete[] result[i];
    delete[] result;
}

template void mulMatrix<int>(int** ,int ,int ,int** ,int ,int );

//специализация для int
/*
template<>
void mulMatrix(int** a, int x, int y, int** b, int n, int m)
{
    int **result = new int *[n];
    for (int i = 0; i < n; i++)
        result[i] = new int[m];
    for(int i = 0; i < x;i++)
    {
        for(int j = 0;j < y; j++)
        {
             result[i][j]=a[i][j]+b[i][j];
        }
    }
}
*/
