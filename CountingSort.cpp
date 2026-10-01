#include <iostream>

void randomfill(int *arr, size_t size)
{
    int min = 1;
    int max = 9;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void print(int *arr, size_t size)
{
    std::cout << " Your array: " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\t';
    }
}

void countingSort(int *arr, size_t size)
{
    if (size <= 1)
    {
        return;
    }
    // 1. Находим максимальный элемент, чтобы узнать размер массива счетчиков
    int max_value = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    // 2. Создаем массив счетчиков и сразу обнуляем его (фигурные скобки {} в конце)
    int *count = new int[max_value + 1]{};
    // 3. Считаем, сколько раз встречается каждое число
    for (size_t i = 0; i < size; ++i)
    {
        count[arr[i]]++;
    }
    // 4. Перезаписываем исходный массив отсортированными значениями
    size_t index = 0;
    for (int i = 0; i <= max_value; ++i)
    {
        // Пока счетчик числа i больше нуля, записываем его в массив
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
    delete[] count;
}

int main()
{
    size_t size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    int *arr = new int[size];
    randomfill(arr, size);
    print(arr, size);
    countingSort(arr, size);
    std::cout << " Sorted array: " << '\n';
    print(arr, size);
    return 0;
}