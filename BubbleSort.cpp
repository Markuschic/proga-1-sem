#include <iostream>

void myswap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    constexpr int length = 5;
    int array[length] = {9, 5, 1, 7, 2};
    bool flag{true};
    while (flag == true)
    {
        flag = false;
        for (int firstIndex = 0; firstIndex < length - 1; ++firstIndex)
        {
            if (array[firstIndex] > array[firstIndex + 1])
            {
                myswap(array[firstIndex], array[firstIndex + 1]);
                flag = true;
            }
        }
    }
    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
    return 0;
}