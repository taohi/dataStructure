#include <stdio.h> 
static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day)
{
    int i,leap;
    leap = year%4 == 0 && year%100 !=0 ||year%400 == 0;
    for(i=1;i<month;i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year,int yearday,int *pmonth,int *pday)
{
    int i,leap;
    leap = year%4 ==0 && year%100!=0 || year%400 ==0;
    for(i=1;yearday> daytab[leap][i];i++)
        yearday -=daytab[leap][i];
    *pday = yearday;
    *pmonth = i;
}

void main()
{
    int year,month,day,yearday;
    int *pday,*pmonth;
    year=2014;
    month=4;
    day=3;
    printf("%d-%d-%d is the %d day of the year.\n",year,month,day,day_of_year(year,month,day));

    yearday=93;
    month_day(year,yearday,pmonth,pday);
    printf("%d day of %d is Month:%d,day:%d\n",yearday,year,pmonth,pday);
}
