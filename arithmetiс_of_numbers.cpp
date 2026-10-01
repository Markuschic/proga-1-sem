#include <iostream>
int main()
{
int month;
int day;
int total_days;
int days_per_month [12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::cout << " Введите месяц (от 1 до 12) " <<'\n';
std::cin >> month;
std::cout << " Введите день (от 1 до 31) " <<'\n';
std::cin >> day;
total_days = day;
for (int i = 0; i<month -1; ++i)
{
    total_days += days_per_month [i];
}
    std::cout << " Обшее число дней с начала года " << total_days <<'\n';
return 0;
}
