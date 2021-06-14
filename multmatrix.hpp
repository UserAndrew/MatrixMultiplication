#ifndef MULTMATRIX_H_INCLUDED
#define MULTMATRIX_H_INCLUDED

//заполняем массив
void initArr(int** ,int ,int );

//распечатываем массив
void printArr(int ** , int , int );

//перемножаем матрицы
template<typename T>
void mulMatrix(T** ,int ,int ,T** ,int ,int );

#endif // MULTMATRIX_H_INCLUDED
