#include <iostream>
int fibonacci (int n)
{
    if(n<=1)
    {
        return n;
    }
    int f1=0;
    int f2=1;
    int Fn;
    for(int i=0; i<=n; ++i)
    {
    Fn=f1+f2;
    f2=f1;
    f1=Fn;
    }
    return Fn;
}
int main()
{
    int n;
    std::cout <<"Enter the number of Fibonacci" <<'\n';
    std::cin >> n;
    std::cout <<"Your number of Fibonacci is " << fibonacci(n) <<'\n';
    return 0;
}