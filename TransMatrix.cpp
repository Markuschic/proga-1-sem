#include <iostream>

void fill(int **matrix, size_t rows, size_t cols, int min = 1, int max = 9)
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void transpose(int **matrix, size_t rows, size_t cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = i + 1; j < cols; ++j)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void print(int **matrix, size_t rows, size_t cols)
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

void delmatrix(int **matrix, size_t rows, size_t cols)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    size_t rows;
    size_t cols;
    std::cout << "Enter the size of matrix" << '\n';
    std::cin >> rows >> cols;
    int **matrix = new int *[rows];
    fill(matrix, rows, cols);
    print(matrix, rows, cols);
    std::cout << '\n';
    transpose(matrix, rows, cols);
    print(matrix, rows, cols);
    return 0;
}