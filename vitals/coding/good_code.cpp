#include <iostream>
#include <map>

const int ERROR_CODE = -1;   /* Error code */

/**
 * Month names enum.
 * This identify unambiguously month names as parameter, error at compile time with errors.
 */
enum months
{
    JANUARY = 0,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
};

/**
 * Static const lenght initialization for month length.
 * const --> you cannot access with operator[], only at(element), is valid.
 */
const std::map<enum months, int> length
{
    std::make_pair(JANUARY, 31),
    std::make_pair(FEBRUARY, 28),
    std::make_pair(MARCH, 31),
    std::make_pair(APRIL, 30),
    std::make_pair(MAY, 31),
    std::make_pair(JUNE, 30),
    std::make_pair(JULY, 31),
    std::make_pair(AUGUST, 31),
    std::make_pair(SEPTEMBER, 30),
    std::make_pair(OCTOBER, 31),
    std::make_pair(NOVEMBER, 30),
    std::make_pair(DECEMBER, 31),
};

/* No comment needed, It is enought clear */
bool checkValidMonthDay(months month, int day)
{
    if( (day <= 0) || (day > length.at(month) ) )
        return false;
    return true;
}

/**
 * \brief Calculate the day of the year for any day and month.
 * \param[in] month : enum with a valid month.
 * \param[in] dayOfMonth: A number between 1 and max days of a month.
 * \return day of year: Valid day of year or ERROR_CODE if a problem exist with data.
 */
int dayOfYear(months month, int dayOfMonth/*, int year*/)
{
    if(!checkValidMonthDay(month, dayOfMonth))
        return ERROR_CODE;

    int result = dayOfMonth;
    int currentMonth = static_cast<int>(month);

    /* add day for each month before current */
    while(currentMonth > JANUARY)
    {
        currentMonth -= 1;
        result += length.at(static_cast<months>(currentMonth));
    }
    return result;
}

int main()
{
    months month = DECEMBER;
    int goodDayOfMonth = 31;
    int goodYear = 1985;
    int badDayOfMonth = 53;
    int badYear = 3;

    std::cout << "The good result is: " << dayOfYear(month, goodDayOfMonth/*, goodYear*/) << std::endl;
    std::cout << "The bad result I is: " << dayOfYear(month, badDayOfMonth/*, goodYear*/) << std::endl;
    //std::cout << "The bad result II is: " << dayOfYear(month, goodDayOfMonth, badYear) << std::endl;
    return 0;
}
