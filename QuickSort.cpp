#include <iostream>
void fill(int *arr, int size)
{
    std::cout << " Fill the array " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

void quick(int *arr, int size, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int half = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (arr[i] < half)
        {
            ++i;
        }
        while (arr[j] > half)
        {
            --j;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    quick(arr, size, left, j); /*рекурсивный вызов сорт двух частей массива, остались после того, как выбрали и поставили на место опорный элемент*/
    quick(arr, size, i, right);
}

void print(int *arr, int size)
{
    std::cout << " Your array is " << '\n';
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

    quick(arr, size, 0, size - 1);
    print(arr, size);

    return 0;
}