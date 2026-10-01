#include <iostream>

void filling(int **matrix, int n, int m, int number)
{
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = number;
        }
    }
}

void print(int **matrix, int n, int m)
{
    std::cout << " Your matrix is " << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void deletemtrx(int **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int n, m;
    std::cout << " Enter the size of matrix " << '\n';
    std::cin >> n >> m;

    int **matrix = new int *[n];

    int number;
    std::cout << " Enter the number to fill your matrix " << '\n';
    std::cin >> number;

    filling(matrix, n, m, number);
    print(matrix, n, m);

    return 0;
}