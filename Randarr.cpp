#include <iostream>
#include <cstdlib>

void randomase ( int* arr, int size, int number )
{
    int min = number / 2;
    int max = number;
    for ( int i = 0; i < size; ++i )
    {
        arr[i] = min + rand() % ( max - min + 1 );
    }
}

void printarr ( int* arr, int size )
{
    std::cout << " Your random array is " << '\n';
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
    int* arr = new int[size];

    int number;
    std::cout << " Enter the number of the range " << '\n';
    std::cin >> number;

    randomase ( arr, size, number );
    printarr ( arr, size );
    return 0;


}