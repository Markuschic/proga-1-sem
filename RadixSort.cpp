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

// Вспомогательная функция: сортировка подсчетом, но только для конкретного разряда (exp)
void countSortByDigit(int *arr, size_t size, int exp)
{
    int *output = new int[size]; // Массив для результата
    int count[10] = {0};         // Счетчики для цифр 0-9 (всегда размер 10!)
    // 1. Считаем, сколько раз встречается каждая ЦИФРА в текущем разряде
    for (size_t i = 0; i < size; ++i)
    {
        int digit = (arr[i] / exp) % 10; // Извлекаем нужную цифру
        count[digit]++;
    }
    // 2. Преобразуем счетчики в позиции (prefix sum)
    // Теперь count[i] хранит ПОЗИЦИЮ, куда должен встать элемент с цифрой i
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }
    // 3. Заполняем output, идя по исходному массиву С КОНЦА (для устойчивости)
    for (int i = static_cast<int>(size) - 1; i >= 0; --i)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    // 4. Копируем результат обратно в исходный массив
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = output[i];
    }
    delete[] output;
}

// Основная функция Radix Sort
void radixSort(int *arr, size_t size)
{
    if (size <= 1)
    {
        return;
    }

    // Находим максимальное число, чтобы знать, сколько разрядов нужно обработать
    int max_val = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    // Проходим по каждому разряду: единицы (1), десятки (10), сотни (100)...
    // exp = 1 -> последняя цифра, exp = 10 -> предпоследняя и т.д.
    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countSortByDigit(arr, size, exp);
    }
}

int main()
{
    size_t size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    int *arr = new int[size];
    randomfill(arr, size);
    print(arr, size);
    radixSort(arr, size);
    std::cout << " Sorted array: " << '\n';
    print(arr, size);
    return 0;
}