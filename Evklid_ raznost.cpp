#include <iostream>
int main()
{
int16_t a;
int16_t b;
int16_t c;
int16_t d;
std::cout << " Введите два числа " <<'\n';
std::cin >> a >> b;
    c = a;
    d = b;
    while ( a != b)
    {
        if ( a > b)
        {
            a -= b;
        }
        else
            b -= a;
    }
    std::cout << " NOD " << a << '\n';
    return 0;
}