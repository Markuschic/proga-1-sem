#include <iostream>
int main()
{
    unsigned int numb;
    unsigned long fact = 1;
    std::cout << " Введите целое число:" <<'\n';
    std::cin >> numb;
    for(int a=numb; a>0; --a)
    {
        fact *= a;
    }
    std::cout << " Факториал числа равен " << fact <<'\n';
    return 0;
}





#include <iostream>
int main()
{
    int a;
    int fact = 1;
    std::cout << " Введите целое число:" <<'\n';
    std::cin >> a;
    for(int b=1; b<=a; ++b)
    {
        fact *= b;
    }
    std::cout << " Факториал числа равен " << fact <<'\n';
    return 0;
}