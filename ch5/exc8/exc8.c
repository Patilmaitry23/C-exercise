#include <stdio.h>

/* daytab: days in months for normal and leap years */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: return day of year; returns -1 if error */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || month > 12)
        return -1;      /* invalid month */

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day < 1 || day > daytab[leap][month])
        return -1;      /* invalid day for this month */

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month and day from day of year; return -1 if error */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 365))
        return -1;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
    return 0;
}

/* test the functions */
int main(void)
{
    int year = 2025, month = 2, day = 30;
    int doy;
    int m, d;

    doy = day_of_year(year, month, day);
    if (doy == -1)
        printf("Error: invalid date %d/%d/%d\n", year, month, day);
    else
        printf("%d/%d/%d is day %d of the year\n", year, month, day, doy);

    if (month_day(year, 308, &m, &d) == -1)
        printf("Error: invalid day of year %d for year %d\n", 366, year);
    else
        printf("Day 366 of %d is %d/%d/%d\n", year, year, m, d);

    return 0;
}

