#include <iostream>

void fill ( int* arr, int size )
{
    std::cout << " Fill " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cin >> arr[i];
    }
}

int minelem ( int*arr, int size )
{
    int minindex = 0;
    for ( int i = 1; i < size; ++i )
    {
        if ( arr[minindex] > arr[i] )
        {
            minindex = i;
        }
    }
    return minindex;
}

int maxelem ( int* arr, int size )
{
    int maxindex = 0;
    for ( int i = 1; i < size; ++i )
    {
        if ( arr[maxindex] < arr[i] )
        {
            maxindex = i;
        }
    }
    return maxindex;
}

int summ ( int* arr, int size )
{
    int sum = 0;
    int i = minelem (arr,size);
    int j = maxelem (arr,size);
    if ( i > j )
    {
        std::swap ( i,j );
    }
    for ( int a = i+1; a < j; ++a)
    {
        sum += arr[a];
    }
    return sum;
}

void func ( int* arr, int size )
{
    int sumary = summ(arr,size);
    int boarder = 0;
    for ( int i = 0; i < size; ++i )
    {
        if ( arr[i] < sumary )
        {
            int j = i;
            while ( j != boarder )
            {
                std::swap ( arr[j], arr[j-1] );
                --j;
            }
        ++boarder;
        }
    }
    for ( int i = boarder; i < size; ++i )
    {
        if ( arr[i] == sumary )
        {
            int j = i;
            while ( j!= boarder )
            {
                std::swap ( arr[j], arr[j-1] );
                --j;
            }
            ++boarder;
        }
    }
}

void print ( int* arr, int size )
{
    std::cout << " Your array is " << '\n';
    for ( int i = 0; i < size; ++i )
    {
        std::cout << arr[i] << ' ';
    }
}


int main()
{
    int size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;

    int* arr = new int [size];
    fill ( arr, size );

    std::cout << " Minindex is " << minelem ( arr, size ) << '\n';
    std::cout << " Maxindex is " << maxelem ( arr, size ) << '\n';
    std::cout << " Summary is " << summ ( arr, size ) << '\n';
    func ( arr, size );
    print ( arr, size );

    return 0;
}