#include <iostream>

int randomase ( int min, int max )
{
    return min + rand() % ( max - min + 1 );
}

void filling ( int** matrix, int n, int m, int min, int max )
{
    for ( int i = 0; i < n; ++i )
    {
        matrix[i] = new int [m];
    }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            matrix[i][j] = randomase( min, max );
        }
    }
}

void resortRows ( int** matrix, int n, int m )
{
    for ( int i = 0; i < n; ++i )
    {
    bool flag = true;
    while ( flag == true )
    {
        flag = false;
        for ( int j = m - 1; j > 0; --j )
        {
            if ( matrix[i][j] % 2 == 1 && matrix [i][j-1] % 2 == 0 )
            {
                std::swap ( matrix[i][j], matrix[i][j-1] );
                flag = true;
            }
            }
        }
    }
}

void swapcolomns ( int** matrix, int n, int j1, int j2 )
{
    
    for ( int i = 0; i < n; ++i )
    {
        std::swap ( matrix[i][j1], matrix[i][j2] );
    }
}

int summary ( int** matrix, int n, int j )
{
    int sum = 0;
    for ( int i = 0; i < n; ++i )
    {
        sum += matrix[i][j];
    }
    return sum;
}
void sortcolomns ( int** matrix, int n, int m )
{
    bool flag = true;
    while ( flag == true )
    {
        flag = false;
        for ( int i = 0; i < m - 1; ++i )
        {
            if ( summary (matrix,n,i) < summary (matrix,n,i+1) )
            {
                swapcolomns (matrix, n, i, i+1);
                flag = true;
            }
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

void delmatrix ( int** matrix, int n, int m )
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

    int min;
    int max;
    std::cout << " Enter the diapazone " << '\n';
    std::cin >> min >> max;
    filling ( matrix, n, m, min, max );
    std::cout << " First matrix is " << '\n';
    print ( matrix, n , m );
    resortRows ( matrix, n , m );
    std::cout << " New matrix is " << '\n';
    print ( matrix, n, m );
    std::cout << " Final matrix is " << '\n';
    sortcolomns ( matrix, n, m );
    print ( matrix, n, m );
    delmatrix ( matrix, n, m );
    return 0;


}