#include <iostream>
int main()
{
    int a,b;
    std::cout << "Enter 2 numbers\n";
    std::cin >> a >> b;

    int c;

    while (b!=0)
    {
        if(a>b)
        {
            c=a;
            a=b;
            b=c%a;
        }
        else{
            int temp;
            temp = b;
            b = a;
            a = temp;
        }
        }
        std::cout << "GCD is "<< a;
        return 0;

    } 