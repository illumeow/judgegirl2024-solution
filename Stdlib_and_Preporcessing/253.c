#include <stdio.h>
#include "time.h"

void initTime(Time *time){
    time->hour = time->minute = time->second = 0;
}

void setTime(Time *time, int hour, int minute, int second){
    time->hour = hour; time->minute = minute; time->second = second;
}

void addTime(Time *time, int hour, int minute, int second){
    time->hour += hour; time->minute += minute; time->second += second;
    while(time->second >= 60){
        time->minute++;
        time->second -= 60;
    }
    while(time->minute >= 60){
        time->hour++;
        time->minute -= 60;
    }
    while(time->hour >= 24){
        time->hour -= 24;
    }
}

void printTime(Time *time){
    #ifdef H24
    printf("%02d:%02d:%02d\n", time->hour, time->minute, time->second);
    #endif
    #ifndef H24
    if(0 <= time->hour && time->hour <= 11){
        printf("%02dam:%02d:%02d\n", (time->hour == 0)? 12: time->hour, time->minute, time->second);
    }else{
        printf("%02dpm:%02d:%02d\n", (time->hour == 12)? 12: time->hour-12, time->minute, time->second);
    }
    #endif
}