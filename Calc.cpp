#include <iostream>
int main ()
{
    int32_t a, b;
    char op;
    std::cout << "Enter 2 numbers\n";
    std::cin >> a >> b;
    std::cout << "Enter operation\n";
    std::cin >> op;
    if(op=='+')
    {
        std::cout << a << "+" << b << "=" << a+b;
        return 0;
    }
    if(op=='-')
    {
        std::cout << a << "-" << b << "=" << a-b;
        return 0;
    }
    if(op=='*')
    {
        std::cout << a << "*" << b << "=" << a*b;
        return 0;
    }
    if(op=='/')
    {
        std::cout << a << "/" << b << "=" << a/b;
        return 0;
    }
    if(op=='^')
    {
        int32_t c = a;
        for(int32_t i = 1; i < b; i++)
        {
            a = a * c; 
        }
        std::cout << c << "^" << b << "=" << a;
        return 0;
    }
    return 0;
}

















#include <iostream>


double funcResult ( char op, double c, double d )
{
    double result;
    if (op == '+')
    {
        result = c+d;
    }
    if (op == '-')
    {
        result = c-d;
    }
    if (op == '*')
    {
        result = c*d;
    }
    if (op == '/')
    {
        result = c/d;
    }
    return result;
}

int main()
{
    char operation;
    double a;
    double b;
    std::cout << " Enter 2 numbers " << '\n';
    std::cin >> a >> b;
    std::cout << " Enter math operation " << '\n';
    std::cin >> operation;
    funcResult(operation, a, b);
    std::cout << " Result = " << funcResult(operation, a, b) << '\n';
    return 0;

}