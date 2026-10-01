#include <iostream>

int interpretate1( uint8_t a ) // функция переводит число из двоичного вида в десятичое
{
    int result;
    for ( int index = 0; index < a; ++index )
    {
        result = a&index;
    }
    return a;
}






int main()
{
    int result;
    int x = 5;
    uint8_t a = 0b10101100;
    result = (((a>>x) &1)&0); // обнуление последнего бита
    std::cout << result << '\n';
    return 0; 
}