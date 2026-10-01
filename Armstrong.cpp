#include <iostream>
int number_of_digits(int n)
{
    int number_of_digits{0};
    while(n!=0)
    {
     ++number_of_digits;
    n/=10;
    }
    return number_of_digits;
}
int degree(int a, int b)
{
    int number = a;
    for( int i = 1; i<b; ++i)
    {
        a*= number;
    }
    return a;
}
void proverka(int c)
{
    int temp;
    int sum = 0;
    int time; // временная переменная для работы с number_of_digits
    for(int i = 0; i<=c; ++i)
    {
        temp = i;
        time = number_of_digits(i);
        while(temp!=0)
        {
         sum += degree(temp%10, time);
         temp/=10;
        }
        if(sum==i)
        {
            std::cout << i << ' ';
        }
        sum=0;
    }
}
int main()
{
    int d;
    std::cout << "Введите число" <<'\n';
    std::cin >> d;
    proverka(d);
    return 0;
}