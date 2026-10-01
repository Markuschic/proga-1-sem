#include <iostream>


void filling ( int*array, int size )
{
    for ( int index = 0; index < size; ++index)
    {
        std::cin >> array[index];
    }
}

int binarySearch ( int*array, int size, int digit )
{
    int half = size / 2;
    int leftborder = 0;
    int rightborder = size - 1;
    while ( (rightborder - leftborder) != 2 )
    {
        if ( digit < array[half])
        {
            rightborder = half - 1;
            half = (rightborder - leftborder + 1) / 2;
            continue;
        }
        if ( digit > array[half] )
        {
            leftborder = half + 1;
            half = leftborder + (rightborder - leftborder + 1) / 2;
        }
        if ( digit == array[half] )
        {
            return half;
        }
    }
    if ( array[leftborder] == digit )
    {
        return leftborder;
    }
    if ( array[rightborder] == digit )
    {
        return rightborder;
    }
    
   return -1;
}

int main()

{
    int size;
    std::cout << " Enter the size of array " << '\n';
    std::cin >> size;
    int *array = new int[size];
    std::cout << " Enter your array " << '\n';
    filling ( array, size );
    int digit;
    std::cout << " Enter the digit " << '\n';
    std::cin >> digit;
    std::cout << binarySearch ( array, size, digit ) << '\n';
    return 0;
}