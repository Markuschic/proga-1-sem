#include <iostream>

int parity ( int x )
{
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 1;
}

int main()
{
    int a = 0b00001101;                 // 8 бит, значит начинаем сдвиг на 4

    std::cout << parity (a) << '\n';

    return 0;
}