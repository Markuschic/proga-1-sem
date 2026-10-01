#include <iostream>

void sovershen ( int number )
{
    for ( int k = 2; k <= number; ++k )
    {
        int sum = 0;
        for ( int i = 1; i < k; ++i )
        {
            if ( k % i == 0 )
            {
                sum += i;
            }
        }
            if ( sum == k )
            {
                std::cout << sum << '\n';
            }
    }
}

int main()
{
    int number = 100;
    
    
    std::cout << " Совершенные числа : " << '\n';       // числа, равные суммы своих делителей
    sovershen( number );
    return 0;
}
