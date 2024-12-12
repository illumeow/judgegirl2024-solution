#include <stdio.h>

#ifdef APLUS
char *rank(int grade){
    if(grade >= 90) return "A+";
    if(grade >= 85) return "A";
    if(grade >= 80) return "A-";
    if(grade >= 77) return "B+";
    if(grade >= 73) return "B";
    if(grade >= 70) return "B-";
    if(grade >= 67) return "C+";
    if(grade >= 63) return "C";
    if(grade >= 60) return "C-";
    return "F";
}

double GPA(int grade){
    if(grade >= 90) return 4.3;
    if(grade >= 85) return 4.0;
    if(grade >= 80) return 3.7;
    if(grade >= 77) return 3.3;
    if(grade >= 73) return 3.0;
    if(grade >= 70) return 2.7;
    if(grade >= 67) return 2.3;
    if(grade >= 63) return 2.0;
    if(grade >= 60) return 1.7;
    return 0.0;
}

int GPAgrade(int grade){
    if(grade >= 90) return 95;
    if(grade >= 85) return 87;
    if(grade >= 80) return 82;
    if(grade >= 77) return 78;
    if(grade >= 73) return 75;
    if(grade >= 70) return 70;
    if(grade >= 67) return 68;
    if(grade >= 63) return 65;
    if(grade >= 60) return 60;
    return 50;
}
#endif

int main(){
    #ifdef HUNDRED
    int score, sum = 0, cnt = 0;
    while(scanf("%d", &score) == 1){
        printf("%d ", score);
        sum += score;
        cnt++;
    }
    printf("%.1lf", (double)sum/cnt);
    #endif
    #ifdef APLUS
    int score, GPAgradesum = 0, cnt = 0;
    double GPAsum = 0.0;
    while(scanf("%d", &score) == 1){
        printf("%s ", rank(score));
        GPAsum += GPA(score);
        GPAgradesum += GPAgrade(score);
        cnt++;
    }
    printf("%.1lf %.1lf", GPAsum/cnt,(double)GPAgradesum/cnt);
    #endif
}