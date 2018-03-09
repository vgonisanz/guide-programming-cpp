#include <iostream>

int dayOfYear(int month, int dayOfMonth, int year)
{
    if (month == 2)
    {
        dayOfMonth += 31;
    } else if (month == 3)
    {
        dayOfMonth += 59;
    } else if (month == 4)
    {
        dayOfMonth += 90;
    } else if (month == 5)
    {
        dayOfMonth += 31 + 28 + 31 + 30;
    } else if (month == 6)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31;
    } else if (month == 7)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30;
    } else if (month == 8)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30 + 31;
    } else if (month == 9)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
    } else if (month == 10)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    } else if (month == 11)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    } else if (month == 12)
    {
        dayOfMonth += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 31;
    }
    return dayOfMonth;
}

int main()
{
    /* TODO */

    int month = 12;
    int goodDayOfMonth = 31;
    int goodYear = 1985;

    int badDayOfMonth = 53;
    int badYear = 3;

    //dayOfYear();
    //std::cout << "The good result is: " << dayOfYear(month, goodDayOfMonth, goodYear) << std::endl;
    //std::cout << "The bad result is: " << dayOfYear(month, badDayOfMonth, badYear) << std::endl;
    return 0;
}
