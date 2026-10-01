#include <iostream>

void filling1 (double* arr1, int size1)
{
    std::cout << " Enter the number ";
    for(int i = 0; i < size1; ++i)
    {
        std::cin >> arr1[i];
        std::cout << '\n';
    }
}

void change1 (double* arr1, int* arr2, int size1, int size2)
{
    for (int i = 0; i < size1; ++i)
    {
        arr2[i] = static_cast<int>(arr1[i]);
    }
}

void filling3 (double* arr1, int* arr2, double* arr3, int size1, int size2, int size3)
{
    for ( int i = 0; i < size3; ++i )
    {
        arr3[i] = arr1[i] - arr2[i];
    }
}
double compare(double* arr3, int size3)
{
    double temp = arr3[0];
    for ( int s = 1; s < size3; ++s )
    {
        if ( arr3[s] > temp )
        {
            temp = arr3[s];
        }
    }
    return temp;
}

int main()
{
    int size1;
    std::cout << " Enter the size of the first array " << '\n';
    std::cin >> size1;
    double* arr1 = new double [size1];
    filling1 (arr1, size1);
    int size2;
    std::cout << " Enter the size of the second array " << '\n';
    std::cin >> size2;
    int* arr2 = new int [size2];
    change1 ( arr1, arr2, size1, size2 );
    int size3;
    std::cout << " Enter the size of the third array " << '\n';
    std::cin >> size3;
    double* arr3 = new double [size3];
    filling3 ( arr1, arr2, arr3, size1, size2, size3 );
    compare (arr3, size3);
    std::cout << " The largest fractional part " << compare(arr3, size3) << '\n';       //число с наибольшей дробной частью
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    return 0;

    
}