#include <stdio.h>

static int day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year = 2022;
    int month = 5;
    int day = 20;
    int yearday = 140;
    int pmonth, pday;

    printf("Day of year for %d/%d/%d: %d\n", day, month, year, day_of_year(year, month, day));

    month_day(year, yearday, &pmonth, &pday);
    printf("Date for day %d of year %d: %d/%d\n", yearday, year, pday, pmonth);

    return 0;
}

int day_of_year_withPointer(int year, int month, int day)
{
    int i, leap;
    int *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = day_tab[leap];
    for (i = 1; i < month; i++)
        day += *(p + i);
    return day;
}

void month_day_withPointer(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    int *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = day_tab[leap];
    for (i = 1; yearday > *(p + i); i++)
        yearday -= *(p + i);
    *pmonth = i;
    *pday = yearday;
}
// --------------------------------------------------------------------
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > day_tab[leap][i]; i++)
        yearday -= day_tab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += day_tab[leap][i];
    return day;
}