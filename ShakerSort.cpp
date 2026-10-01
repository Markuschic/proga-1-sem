#include <iostream>

void fill ( int* arr, int size )
{
    std::cout << " Fill the array " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cin >> arr[i];
    }
}

void shaker ( int* arr, int size )
{
    int left = 0;
    int right = size - 1;
    
    while ( left < right )
    {
        for ( int i = left; i < right; ++i )
        {
            if ( arr[i] > arr[i+1] )
            {
                std::swap ( arr[i], arr[i+1] );
            }
        }
        --right;
        for ( int i = right; i > left; --i )
        {
            if ( arr[i-1] > arr[i] )
            {
                std::swap ( arr[i-1], arr[i] );
            }
        }
        ++left;
    }
}

void print ( int* arr, int size )
{
    std::cout << " Your array is " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    int size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;

    int* arr = new int [size];
    fill ( arr, size );
    shaker ( arr, size );
    print ( arr, size );

    return 0;

}