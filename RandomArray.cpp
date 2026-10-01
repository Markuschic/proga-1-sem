#include <iostream>

void randint(int *arr, int size, int min, int max)
{
    srand(time(0));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void print(int *arr, int size)
{
    std::cout << " Ваш массив : " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    int size;
    std::cout << " Введите размер массива " << '\n';
    std::cin >> size;

    int number;
    std::cout << " Введите число для диапазона " << '\n';
    std::cin >> number;

    int min = (-number) / 2;
    int max = number + 5;

    int *arr = new int[size];
    randint(arr, size, min, max);
    print(arr, size);

    return 0;
}