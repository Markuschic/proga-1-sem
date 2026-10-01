#include <iostream>

int randint ( int min, int max )
{
    return min + rand() % ( max - min + 1 );
}

void fill ( int** matrix, int rows, int cols, int min, int max )
{
    for ( int i = 0; i < rows; ++i )
    {
        matrix[i] = new int [cols];
    }
    for ( int i = 0; i < rows; ++i )
    {
        for ( int j = 0; j < cols; ++j )
        {
            matrix[i][j] = randint ( min, max );
        }
    }
}

void printrow ( int* row, int size)
{
    for ( int i = 0; i < size; ++i )
    {
        std::cout << row[i] << ' ';
    }
}
void print ( int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2 )
{
    int maxrows = std::max ( rows1, rows2 );
    for ( int i = 0; i < maxrows; ++i )
    {
        printrow ( matrix1[i], cols1);
        if ( i == maxrows / 2 )
        {
            std::cout << ' ' << ' ' << ' ';
        }
        else 
        {
            std::cout << "   ";
        }
        printrow ( matrix2[i], cols2 );
        std::cout << '\n';
    }
}

void delmtrx ( int** matrix, int rows, int cols )
{
    for ( int i = 0; i < rows; ++i )
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int main()
{
    srand(time(0));
    int rows1, cols1;
    std::cout << " Enter the size matrix1 " << '\n';
    std::cin >> rows1 >> cols1;

    int** matrix1 = new int* [rows1];

    int min, max;
    std::cout << " Enter the min and max values " << '\n';
    std::cin >> min >> max;

    fill ( matrix1, rows1, cols1, min, max );

    int rows2, cols2;
    std::cout << " Enter the size matrix2 " << '\n';
    std::cin >> rows2 >> cols2;

    int** matrix2 = new int* [rows2];
    fill ( matrix2, rows2, cols2, min, max );
    std::cout << " Your result is " << '\n';
    print ( matrix2, rows2, cols2, matrix2, rows2, cols2 );

    delmtrx ( matrix1, rows1, cols1 );
    delmtrx ( matrix2, rows2, cols2 );
    return 0;
}