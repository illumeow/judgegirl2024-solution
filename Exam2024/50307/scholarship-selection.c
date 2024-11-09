#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "scholarship.h"
 
inline bool fcmp(double a, double b){
    return fabs(a - b) < (double)1e-9;
} 
 
double score2gpa(int score){
    if(score >= 90) return 4.3;
    if(score >= 85) return 4.0;
    if(score >= 80) return 3.7;
    if(score >= 77) return 3.3;
    if(score >= 73) return 3.0;
    if(score >= 70) return 2.7;
    if(score >= 67) return 2.3;
    if(score >= 63) return 2.0;
    if(score >= 60) return 1.7;
    return 0;
}

bool cmp(struct Student *s1, struct Student *s2){
    if(!fcmp(s1->gpa_avg, s2->gpa_avg) &&
       s1->gpa_avg > s2->gpa_avg) return true;
    else if(fcmp(s1->gpa_avg, s2->gpa_avg) &&
            !fcmp(s1->comp_avg, s2->comp_avg) &&
            s1->comp_avg > s2->comp_avg ) return true;
    else if(fcmp(s1->gpa_avg, s2->gpa_avg) &&
            fcmp(s1->comp_avg, s2->comp_avg) &&
            !fcmp(s1->elec_avg, s2->elec_avg) &&
            s1->elec_avg > s2->elec_avg) return true;
    else if(fcmp(s1->gpa_avg, s2->gpa_avg) &&
            fcmp(s1->comp_avg, s2->comp_avg) &&
            fcmp(s1->elec_avg, s2->elec_avg) &&
            s1->major > s2->major) return true;
    else if(fcmp(s1->gpa_avg, s2->gpa_avg) &&
            fcmp(s1->comp_avg, s2->comp_avg) &&
            fcmp(s1->elec_avg, s2->elec_avg) &&
            s1->major == s2->major &&
            s1->total > s2->total) return true;
    return false;                                                              
}

void scholarship(int n, struct Student students[]){
    for(int i = 0; i < n; i++){
        struct Student *student = &(students[i]);
        double gpa_sum = 0, comp_sum = 0, elec_sum = 0;
        int comp_credit = 0, elec_credit = 0, total_credit = 0;
        for(int j = 0; j < student->k; j++){
            struct Class class = student->classes[j];
            gpa_sum += class.credit * score2gpa(class.score);
            if(class.type == 0){
                comp_sum += class.credit * class.score;
                comp_credit += class.credit;
            }
            else if(class.type == 1){
                elec_sum += class.credit * class.score;
                elec_credit += class.credit;
            }
            total_credit += class.credit;
        }
        student->gpa_avg = gpa_sum / total_credit;
        student->comp_avg = comp_sum / comp_credit;
        student->elec_avg = elec_sum / elec_credit;
        student->major = comp_credit + elec_credit;
        student->total = total_credit;
    }

    int num_of_scholor = (n-1)/20 + 1;
    printf("%d\n", num_of_scholor);
    
    bool visited[505] = {};
    int max;
    for(int j = 0; j < num_of_scholor; j++){
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                max = i;
                break;
            }
        }
        for(int i = max+1; i < n; i++)
            if(!visited[i] && cmp(&students[i], &students[max]))
                max = i;
        visited[max] = true;
        printf("%s\n", students[max].id);
    }
}