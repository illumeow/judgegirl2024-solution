#include <stdio.h>

int isLeapYear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            return (year % 400 == 0)?1:0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

int main(){
    /* 0: Sun, 1: Mon, ..., 6: Sat */
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year, day_of_week;
    scanf("%d%d", &year, &day_of_week);
    if(isLeapYear(year)) days[2] = 29;
    int n;
    scanf("%d", &n);

    int month, day, gap;
    while(n--){
        scanf("%d%d", &month, &day);
        gap = day;
        if(month < 1 || month > 12){
            printf("-1\n");
            continue;
        }else if(day > days[month] || day < 1){
            printf("-2\n");
            continue;
        }
        for(int i = 1; i < month; i++) gap += days[i];

        printf("%d\n", (day_of_week+(gap-1)%7)%7);
    }
}