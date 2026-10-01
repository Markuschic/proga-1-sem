#include <iostream>

int stepen ( int a, int b )
{
    int temp = a;
    for ( int i = 1; i < b; ++i )
    {
        a = a * temp;
    }
    return a;
}

void calc ( int a, int b, char op )
{
    switch (op)
    {
        case '+' :
        std::cout << a << "+" << b << "=" << a+b << '\n';
        break;

        case '-' :
        std::cout << a << "-" << b << "=" << a-b << '\n';
        break;

        case '*' :
        std::cout << a << "*" << b << "=" << a*b << '\n';
        break;

        case '/' :
        std::cout << a << "/" << b << "=" << a/b << '\n';

        case '^' :
        std::cout << a << "^" << b << "=" << stepen ( a, b ) << '\n';
        break;

        default :
        std::cout << " Error, invalid operation " << '\n';
    }
}

int main()
{
    int x,y;
    std::cout << " Enter the numbers " << '\n';
    std::cin >> x >> y;
    char op;
    std::cout << " Enter the operation : + , - , * , / , ^ " << '\n';
    std::cin >> op;
    calc ( x,y,op );
    return 0;
}