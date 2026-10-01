#include <iostream>
#include <cmath>
void kvadrat(double a, double b, double c)
{
    double D;
    D = b*b - 4*a*c;
    if (D>0)
    { 
    double x1 = ((-b) + sqrt(D))/2*a;
    double x2 = ((-b) - sqrt(D))/2*a;
    std::cout << x1;
    std::cout << x2;
    return;
    }
    if (D==0)
    {
        double x3 = (-b)/2*a; 
        std::cout << x3;
    return;
    }
}
int main()
{
    std::cout << "Enter 3 numbers" <<'\n';
    double a;
    double b;
    double c;
    std::cin >> a >> b >> c;
    kvadrat(a,b,c);
    return 0;
}