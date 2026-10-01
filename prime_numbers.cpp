#include <iostream>
void prime_numbers(int n)
{
    for(int i=2; i<n; ++i)
    {
    if(n %i ==0)
    {
        return;
    }
    }
    std::cout<< n << ' ';
}
int main()
{
 int a;
 std::cout << " Enter the number" <<'\n';
 std::cin >> a;
 for( int i = 2; i<= a; ++i)
    {
    prime_numbers(i);
    }
    if(a<0)
    {
    std::cout << " Error " <<'\n';
    }
    return 0;
}
