/*
 * 用指针方式代替数组下标方式改写函数day_of_year和month_day
 */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;
    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
    p = day[leap];
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > p[month])
        return -1;
    while (--month)
        day += *++p;
    return day;
}

/* month_day: set month, day form day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    char *p;
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    if (i > 12 && yearday > daytab[leap][12]) {
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = p - *(daytab + leap);
        *pday = yearday;
    }
}
