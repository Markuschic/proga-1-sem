#include <iostream>

int main()
{
        int a;
        int b;
        int c;
        std::cout << " Enter three numbers " << '\n';
        std::cin >> a >> b >> c;
        int max =  a > b ? ( a > c ? a : c ) : ( b > c ? b : c );
        std::cout << " Большее из чисел : " << max << '\n';
        return 0;

}