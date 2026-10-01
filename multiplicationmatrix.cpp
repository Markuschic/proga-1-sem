#include <iostream>
#include <iomanip>

int randint(int max, int min)
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
            matrix[i][j] = randint(max, min);
        }
    }
}

void multiple(int **matrix1, int **matrix2, int **matrix3, int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            for (int k = 0; k < cols1; ++k)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void print(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << std::setw(5) << matrix[i][j] << ' ';
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
    std::cout << '\n';
    print(matrix1, rows1, cols1);

    int rows2, cols2;
    std::cout << " Enter the size of the 2 matrix " << '\n';
    std::cin >> rows2 >> cols2;

    if (cols1 != rows2)
    {
        std::cout << " ERROR " << '\n';
        return 0;
    }

    int **matrix2 = new int *[rows2];

    fill(matrix2, rows2, cols2, min, max);
    std::cout << " 2 matrix is " << '\n';
    print(matrix2, rows2, cols2);

    int **matrix3 = new int *[cols1];
    for (int i = 0; i < cols2; ++i)
    {
        matrix3[i] = new int[cols2];
    }

    multiple(matrix1, matrix2, matrix3, rows1, cols1, cols2);
    std::cout << " final matrix is " << '\n';
    print(matrix3, rows1, cols2);

    delmatrix(matrix1, rows1, cols1);
    delmatrix(matrix2, rows2, cols2);
    delmatrix(matrix3, cols1, cols2);

    return 0;
}