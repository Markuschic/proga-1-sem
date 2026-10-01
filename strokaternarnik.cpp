#include <iostream>
#include <string>
int main()
{

    int digit;
    std::cout << " Enter " << '\n';
    std::cin >> digit;

    std::string message1 = ( (digit > 0 && digit != 5) ? " TOP " : " LOX " ); // оператор и ( ПРИОРИТЕТ И ВЫШЕ ЧЕМ ИЛИ )
    std::string message2 = ( (digit == 15 || digit == 20) ? " LOX " : " TOP " ); // оператор или
    std::cout << message1;
    return 0;
}