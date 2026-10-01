#include <iostream>

void filling ( int* arr, int size )
{
    std::cout << " Fill the array " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cin >> arr[i];
    }
}

void shift ( int* arr, int size, int number )
{
   for ( int i = 0; i < size; ++i )
   {
    arr[i] = arr[i+number];
   }
   std::cout << " Your shifted array is " << '\n';
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

    int* arr = new int[size];
    int number;
    std::cout << " Enter the number, which you want to shift your array " << '\n';
    std::cin >> number;

    filling ( arr, size ); 
    shift ( arr, size, number );
    return 0;
}