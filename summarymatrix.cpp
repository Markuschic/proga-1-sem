#include <iostream>

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void fill(int **matrix, int rows, int cols, int min, int max)
{
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = randint(min, max);
        }
    }
}

void summary(int **matrix1, int **matrix2, int **matrix3, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void print(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void delmatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int rows1, cols1;
    std::cout << " Enter the size of the 1 matrix " << '\n';
    std::cin >> rows1 >> cols1;

    int **matrix1 = new int *[rows1];

    int min, max;
    std::cout << " Enter the min and max values of the range " << '\n';
    std::cin >> min >> max;

    fill(matrix1, rows1, cols1, min, max);
    std::cout << " 1 matrix is " << '\n';
    print(matrix1, rows1, cols1);

    int rows2, cols2;
    std::cout << " Enter the size of the 2 matrix " << '\n';
    std::cin >> rows2 >> cols2;

    if (rows1 != rows2 || cols1 != cols2)
    {
        std::cout << " ERROR " << '\n';
        return 0;
    }

    int **matrix2 = new int *[rows2];

    fill(matrix2, rows2, cols2, min, max);
    std::cout << " 2 matrix is " << '\n';
    print(matrix2, rows2, cols2);

    int **matrix3 = new int *[rows1];
    for (int i = 0; i < rows1; ++i)
    {
        matrix3[i] = new int[cols1];
    }

    summary(matrix1, matrix2, matrix3, rows1, cols1);
    std::cout << " final matrix is " << '\n';
    print(matrix3, rows1, cols1);

    delmatrix(matrix1, rows1, cols1);
    delmatrix(matrix2, rows2, cols2);
    delmatrix(matrix3, rows1, cols1);

    return 0;
}