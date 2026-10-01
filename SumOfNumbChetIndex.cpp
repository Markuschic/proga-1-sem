#include <iostream>

int chetIndex ( int number )
{
    int temp = 0;
    for ( int index = 0; index < number; ++index )
    {
        if ( index %2 == 0)
        {
            temp += number % 10;
        }
        number /= 10;
    }
    return temp;
}

int main()
{
    int number;
    std::cout << " Enter the number " << '\n';
    std::cin >> number;
    std::cout << " Сумма цифр на четных индексах равна : " << '\n';
    std::cout << chetIndex (number) << '\n';
    return 0;

}