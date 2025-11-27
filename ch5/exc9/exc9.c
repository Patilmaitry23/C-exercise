#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: convert month/day to day of year*/
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    /* check month range */
    if (month < 1 || month > 12)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* pointer to first month */
    p = daytab[leap] + 1;

    /* sum days of previous months */
    while (--month)
        day += *p++;

    /* check day range */
    if (day <= 0 || (leap && day > 366) || (!leap && day > 365))
        return -1;

    return day;
}

/* month_day: convert day of year to month/day */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* pointer to first month */
    p = daytab[leap] + 1;

    if ((leap && yearday < 1 || yearday > 366) || (!leap && (yearday < 1 || yearday > 365)))
        return -1;  /* invalid day */

    int month = 1;
    while (yearday > *p) {
        yearday -= *p;
        p++;
        month++;
    }

    *pmonth = month;
    *pday = yearday;
    return 0;
}

int main(void)
{
    int year = 2024;
    int month = 3, day = 1;
    int doy;
    int m, d;

    doy = day_of_year(year, month, day);
    if (doy == -1)
        printf("Invalid date %d/%d/%d\n", year, month, day);
    else
        printf("%d/%d/%d is day %d of the year\n", year, month, day, doy);

    if (month_day(year, doy, &m, &d) == -1)
        printf("Invalid day of year %d for year %d\n", doy, year);
    else
        printf("Day %d of %d is %d/%d/%d\n", doy, year, year, m, d);

    return 0;
}

