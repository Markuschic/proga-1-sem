#include <iostream>

void fill ( int** matrix, int n, int m )
{
    int min, max;
    std::cout << " Enter the diapozone of randoma " << '\n';
    std::cin >> min >> max;

    srand(time(0));
    for ( int i = 0; i < n; ++i )
    {
        matrix [i] = new int [m];
    }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            matrix [i][j] = min + rand() % ( max - min + 1 );
        }
    }
}

void print ( int** matrix, int n, int m )
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void del ( int** matrix, int n, int m )
{
    for ( int i = 0; i < n; ++i )
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

int main()
{
    int n,m;
    std::cout << " Enter the size of matrix " << '\n';
    std::cin >> n >> m;

    int** matrix = new int* [n];

    fill ( matrix, n, m );
    print ( matrix, n, m );
    del ( matrix, n, m );

    return 0;
}