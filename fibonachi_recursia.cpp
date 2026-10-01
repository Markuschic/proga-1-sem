#include <iostream>

int fibonacci(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    std::cout << "Enter number" <<'\n';
    int n;
    std::cin >> n;
    std::cout << "your number Fibonacci: " << fibonacci(n) << std::endl;
    return 0;
}
