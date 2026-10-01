#include <iostream>

void fill ( int* arr, int size )
{
    std::cout << " Fill the array " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cin >> arr[i];
    }
} 

void rasch ( int* arr, int size )
{
    int step = size;
    bool flag = true;
    while ( flag == true || step > 1 )
    {
        flag = false;
        step = static_cast <int> ( step / 1.247 );
        for ( int i = 0; i < size - step; ++i )
        {
            if ( arr[i] > arr[i+step] )
            {
                std::swap ( arr[i], arr[i+step] );
                flag = true;
            }
        }
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
    std::cout << " enter the size " << '\n';
    std::cin >> size;

    int* arr = new int [size];
    fill ( arr, size );
    rasch ( arr, size );
    print ( arr, size );

    return 0;
}