#include <iostream>

void subtractionMatrix ( int** matrix1 , int** matrix2, int** matrix3, int n, int m, int s, int t, int q, int p )
{
    for ( int i = 0; i < q; ++i )
    {
        for ( int j = 0; j < p; ++j )
        {
            matrix3 [i] [j] = matrix1 [i] [j] - matrix2 [i] [j];
        }
    }
   for ( int i = 0; i < q; ++i )
   {
    for ( int j = 0; j < p; ++j )
    {
        std::cout << matrix3 [i] [j] << ' ';
    }
    std::cout << '\n';
   }
}

int main()
{
    int n, m;
    std::cout << " Enter the size of the first matrix " << '\n';
    std::cin >> n >> m;
    int** matrix1 = new int* [n];
    for ( int k = 0; k < n; ++k )
    {
        matrix1 [k] = new int [m]; 
    }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            matrix1 [i] [j] = 1489;
        }
    }
    
    int s,t;
    std:: cout <<  " Enter the size of the second matrix " << '\n';
    std::cin >> s >> t;
    int** matrix2 = new int* [s];
    for ( int i = 0; i < s; ++i )
    {
        matrix2 [i] = new int [t];
    }
    for ( int i = 0; i < s; ++i )
    {
        for ( int j = 0; j < t; ++j )
        {
            matrix2 [i] [j] = 1;
        }
    }

    int q, p;
    std::cout << " Enter the size of the third matrix " << '\n';
    std::cin >> q >> p;
    int** matrix3 = new int* [q];
    for ( int i = 0; i < q; ++i )
    {
        matrix3 [i] = new int [p];
    }
    
    subtractionMatrix( matrix1, matrix2, matrix3, n, m, s, t, q, p );
    
    return 0;
}