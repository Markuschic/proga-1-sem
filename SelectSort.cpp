#include <iostream>

int main()
{
    constexpr int length = 5;
    int array[length] = { 30, 60, 20, 50, 40};
    for ( int firstIndex = 0; firstIndex < length; ++firstIndex )
    {
        int smallest = firstIndex;
        for ( int secondIndex = firstIndex + 1; secondIndex < length; ++ secondIndex)
        {
            if ( array[secondIndex] < array[ smallest])
            {
                std::swap ( array[secondIndex], array[smallest] );
            }
        }
    }
    for ( int index = 0; index < length; ++index)
    {
        std::cout << array[index] << '\n';
    }
    return 0;
}