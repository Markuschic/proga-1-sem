#include <iostream>

void filling ( int* arr, int size )
{
    std::cout << " Fill the array " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cin >> arr[i];
    } 
}

void reverse ( int* arr, int size, int left, int right )
{
    while ( left < right )
    {
        std::swap ( arr[left], arr[right] );
        ++left;
        --right;
    }
}

void shiftleft ( int* arr, int size, int k )
{
   reverse ( arr, size, 0, k - 1 );
   reverse ( arr, size, k, size - 1 );
   reverse ( arr, size, 0, size - 1);
}

void shiftright ( int* arr, int size, int k )
{
    reverse ( arr, size, 0, size - 1 );
    reverse ( arr, size, 0, k - 1 );
    reverse ( arr, size, k, size - 1 );
}

void printarr ( int* arr, int size )
{
    for ( int i = 0; i < size; ++i )
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    int size;
    std::cout << " Enter the size of the array " << '\n';
    std::cin >> size;
    int* arr = new int [size];
    filling ( arr, size );

    int left;
    int right;
    int k;
    std::cout << " Enter the indexes of the array to shift " << '\n';
    std::cin >> left >> right >> k;

/* 
    shiftleft ( arr, size, k );                 // шифт влево на k
    std::cout << " Shift left is " << '\n';
    printarr ( arr, size );
*/

    shiftright ( arr, size, k );                // шифт вправо на k
    std::cout << " shift right is " << '\n';
    printarr ( arr, size );

    

    return 0;
}


