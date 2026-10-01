#include <iostream>
double lineq(double,double);

int main()
{
    std::cout<<"Enter a b"<<std::endl;
    double a;
    double b;
   std::cin>>a>>b;
    double result = lineq(a,b);
    std::cout<<result;
    
    return 0;
}

double lineq(double a, double b){
    double x;
    x = (-b)/a;
    return x;
}