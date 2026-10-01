#include <iostream>

void filling ( int*array, int size )
{
    for ( int index = 0; index < size; ++index)
    {
        std::cin >> array[index];
    }
}


int search ( int*array, int size, int digit)
{
    for (int index = 0; index < size; ++index )
    {
        if ( array[index] == digit )
        {
        return index;
        }
    }
    return -1;
}

int main()
{
    int size;
    std::cout << " Enter your size " << '\n';
    std::cin >> size;
   int *array = new int [size];
    std::cout << " Enter your array " << '\n';
    filling ( array, size );
     int digit;
    std::cout << " Enter digit " << '\n';
    std::cin >> digit;
    std::cout << search ( array, size, digit) << '\n';
    return 0;
}