#include <iostream>

void fill(int *arr, int size)
{
    std::cout << " fill the array " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

void insert(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int timeindex = i;
        while (timeindex > 0 && arr[timeindex] < arr[timeindex - 1])
        {
            std::swap(arr[timeindex], arr[timeindex - 1]);
            --timeindex;
        }
    }
}

void print(int *arr, int size)
{
    std::cout << " Your sorted array is " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    int size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;

    int *arr = new int[size];
    fill(arr, size);
    insert(arr, size);
    print(arr, size);

    return 0;
}