#include <stdbool.h>
#include "book.h"
#include "date.h"

bool is_leap_year(unsigned int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

unsigned int date_diff_day(struct Date date_borrowed, struct Date date_returned){
    int month2day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapYearCount = 0;
    for(int year = date_borrowed.year+1; year < date_returned.year; year++)
        if(is_leap_year(year)) leapYearCount++;
    int midYearCount = date_returned.year - date_borrowed.year - 1;
    int ret = 365 * midYearCount + leapYearCount;
    for(int month = date_borrowed.month+1; month <= 12; month++)
        ret += month2day[month];
    if(is_leap_year(date_borrowed.year) && date_borrowed.month == 1) ret++;
    for(int month = 1; month < date_returned.month; month++)
        ret += month2day[month];
    if(is_leap_year(date_returned.year) && date_returned.month > 2) ret++;
    ret += month2day[date_borrowed.month]-date_borrowed.day+1;
    ret += date_returned.day;

    return ret;
}

int zero_count(unsigned int n){
    int start = -1, end = -1;
    for(int i = 31; i >= 0 && end == -1; i--){
        if((n >> i) & 1 && start == -1) start = i;
        else if((n >> i) & 1) end = i;
    }
    return start - end - 1;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int dayDiff = date_diff_day(date_borrowed, date_returned);
    int dueDate[4] = {90, 10, 100, 5};
    int overDate = dayDiff - dueDate[book.type];
    overDate = (overDate > 0)? overDate: 0;
    
    return overDate * zero_count(book.importance);
}