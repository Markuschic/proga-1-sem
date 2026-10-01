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

// Простая сортировка вставками для одного ведра
void insertionSort(int *bucket, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            --j;
        }
        bucket[j + 1] = key;
    }
}

// Основная функция Bucket Sort
void bucketSort(int *arr, size_t size)
{
    if (size <= 1)
    {
        return;
    }
    int bucketCount = 10; // Количество ведер
    // 1. Находим мин и макс для определения диапазона
    int min_val = arr[0], max_val = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[i] < min_val)
            min_val = arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    // 2. Выделяем память для ведер
    //    Каждое ведро может вместить до size элементов (худший случай)
    int **buckets = new int *[bucketCount];
    int *bucketSizes = new int[bucketCount]{}; // Обнуляем размеры

    for (int i = 0; i < bucketCount; ++i)
    {
        buckets[i] = new int[size];
    }
    // 3. Распределяем элементы по ведрам
    int range = max_val - min_val + 1;
    for (size_t i = 0; i < size; ++i)
    {
        int bucketIndex = (arr[i] - min_val) * bucketCount / range;

        // Защита: если элемент == max_val, индекс может получиться == bucketCount
        if (bucketIndex >= bucketCount)
            bucketIndex = bucketCount - 1;

        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    // 4. Сортируем каждое ведро и собираем обратно в массив
    size_t index = 0;
    for (int i = 0; i < bucketCount; ++i)
    {
        if (bucketSizes[i] > 0)
        {
            insertionSort(buckets[i], bucketSizes[i]);

            for (int j = 0; j < bucketSizes[i]; ++j)
            {
                arr[index++] = buckets[i][j];
            }
        }
    }
    // 5. Освобождаем память
    for (int i = 0; i < bucketCount; ++i)
    {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}

int main()
{
    size_t size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    int *arr = new int[size];
    randomfill(arr, size);
    print(arr, size);
    bucketSort(arr, size);
    std::cout << " Sorted array: " << '\n';
    print(arr, size);
    return 0;
}