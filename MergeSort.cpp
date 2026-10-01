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

void merge(int *arr, int left, int mid, int right)
{
    size_t leftpart = mid - left + 1;
    size_t rightpart = right - mid;
    int *timeleft = new int[leftpart];
    int *timeright = new int[rightpart];
    for (size_t i = 0; i < leftpart; ++i)
    {
        timeleft[i] = arr[left + i];
    }
    for (size_t j = 0; j < rightpart; ++j)
    {
        timeright[j] = arr[mid + 1 + j];
    }
    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < leftpart && j < rightpart)
    {
        if (timeleft[i] <= timeright[j])
            arr[k++] = timeleft[i++];
        else
            arr[k++] = timeright[j++];
    }
    while (i < leftpart)
    {
        arr[k++] = timeleft[i++];
    }
    while (j < rightpart)
    {
        arr[k++] = timeright[j++];
    }
    delete[] timeleft;
    delete[] timeright;
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid{left + (right - left) / 2};
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    std::cout << " Sorted array: " << '\n';
    merge_sort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}