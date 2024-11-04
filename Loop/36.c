#include <stdio.h>

int main(){
    int year, month, week_of_day;
    scanf("%d%d%d", &year, &month, &week_of_day);
    if(month < 1 || month > 12 || week_of_day < 0 || week_of_day > 6){
        printf("invalid\n");
        return 0;
    }
    int days;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) days = 29;
            else days = 28;
            break;
        default: break;
    }
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    for(int i = 0; i < week_of_day; i++) printf("   ");
    for(int i = 1; i <= days; i++){
        if(week_of_day > 6){
            printf("\n");
            week_of_day = 0;
        }
        printf("%3d", i);
        week_of_day++;
    }
    printf("\n=====================\n");
}