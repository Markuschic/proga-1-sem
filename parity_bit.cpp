#include <iostream>

int parity ( uint8_t n )
{
    int counter = 0;
    while ( n > 0 )
    {
        counter += ( n & 1);
        n = n >> 1;
    }
    return counter % 2;
}

int main()
{

    uint8_t n = 0b00000101;

    std::cout << parity (n) << '\n';
    return 0;

}