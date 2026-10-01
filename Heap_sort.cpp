#include <iostream>

int randomase(int min, int max)
{
    return min + rand() % (max - min + 1);
}
void fill(int *arr, size_t size, int min, int max)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = randomase(min, max);
    }
}

void print(int *arr, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

template <class T>
bool comparator(const T &a, const T &b)
{
    return a < b;
}

int leftchild(int number)
{
    return 2 * number + 1;
}

int rightchild(int number)
{
    return 2 * number + 2;
}

template <class T>
void heapify(T *arr, size_t size, int root, bool (*compare)(const T &a, const T &b))
{
    int left = leftchild(root);
    int right = rightchild(root);
    int largest = root;
    if (left < size && compare(arr[largest], arr[left]))
    {
        largest = left;
    }
    if (right < size && compare(arr[largest], arr[right]))
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(arr[largest], arr[root]);
        heapify(arr, size, largest, compare);
    }
}

template <class T>
void heap_build(T *arr, size_t size, bool (*compare)(const T &a, const T &b))
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(arr, size, i, compare);
    }
}

template <class T>
void heap_sort(T *arr, size_t size, bool (*compare)(const T &a, const T &b))
{
    heap_build(arr, size, compare);
    for (int i = size - 1; i > 0; --i)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0, compare);
    }
}

int main()
{
    size_t size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    int min = 0;
    int max = 9;
    int *arr = new int[size];
    fill(arr, size, min, max);
    print(arr, size);
    heap_sort(arr, size, comparator);
    std::cout << " Sorted " << '\n';
    print(arr, size);
}