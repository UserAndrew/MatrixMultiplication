#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ciso646>
#include <ctime>
#include "multmatrix.hpp"

int main()
{
    int row1, row2, col1, col2;
    std::cout << "The program multiplies two matrices." << std::endl;
    std::cout << "Enter rows count and columns count of the first matrix separated by a space:" << std::endl;
    std::cin >> row1 >> col1;
    std::cout << "Enter rows count and columns count of the second matrix separated by a space:" << std::endl;
    std::cin >> row2 >> col2;
    if (row1 <= 0 or col1 <= 0 or row2 <= 0 or col2 <= 0 )
    {
        std::cerr << "Incorrect enter!";
        return 1;
    }
    if (col1 == row2)
    {
        //выделение памяти для первого массива
        int **pArr1 = new int *[row1];
        for (int i = 0; i < row1; i++)
            pArr1[i] = new int[col1];
        //выделение памяти для второго массива
        int **pArr2 = new int *[row2];
        for (int i = 0; i < row2; i++)
            pArr2[i] = new int[col2];
        //заполнение случайными числами
        srand(time(nullptr));
        initArr(pArr1, row1, col1);
        sleep(1);
        srand(time(nullptr));
        initArr(pArr2, row2, col2);

        //печать массивов в консоль
        std::cout << "Initial matrices:\n";
        printArr(pArr1, row1, col1);
        std::cout << std::endl;
        printArr(pArr2, row2, col2);

        //перемножение и распечатка
        std::cout << std::endl << "The product matrix:\n";
        mulMatrix(pArr1, row1, col1, pArr2, row2, col2);


        //удаление массивов в порядке, обратном созданию
        for (int i = 0; i < row1; i++)
            delete[] pArr1[i];
        delete[] pArr1;

        for (int i = 0; i < row2; i++)
            delete[] pArr2[i];
        delete[] pArr2;
    }
    else
    {
        std::cout << "Error: unable multiply matrices." << std::endl;
    }
    return 0;
}
