#include <stdio.h>
#include <stdbool.h>
#include "scholarship.h"
#include <math.h>
 
bool fcmp(double a, double b){
    return fabs(a - b) < 0.000000001;
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
 
void scholarship(int n, struct Student students[]){
    for(int i = 0; i < n; i++){
        struct Student *student = &(students[i]);
        double gpa_sum = 0, comp_sum = 0, elec_sum = 0;
        int comp_credit = 0, elec_credit = 0, total_credit = 0;
        for(int j = 0; j < student->k; j++){
            struct Class class = student->classes[j];
            gpa_sum += class.credit * score2gpa(class.score);
            total_credit += class.credit;
            if(class.type == 0){
                comp_sum += class.credit * class.score;
                comp_credit += class.credit;
            }
            else if(class.type == 1){
                elec_sum += class.credit * class.score;
                elec_credit += class.credit;
            }
        }
        student->gpa_avg = (double)gpa_sum / (double)total_credit;
        student->comp_avg = (double)comp_sum / (double)comp_credit;
        student->elec_avg = (double)elec_sum / (double)elec_credit;
        student->major = comp_credit + elec_credit;
        student->total = total_credit;
    }
 
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            // cmp j & j+1
            struct Student *student1 = &(students[j]);
            struct Student *student2 = &(students[j+1]);
            if(!fcmp(student1->gpa_avg, student2->gpa_avg) &&
               student1->gpa_avg > student2->gpa_avg ){
                struct Student tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
 
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            // cmp j & j+1
            struct Student *student1 = &(students[j]);
            struct Student *student2 = &(students[j+1]);
            if(fcmp(student1->gpa_avg, student2->gpa_avg) &&
               !fcmp(student1->comp_avg, student2->comp_avg) &&
               student1->comp_avg > student2->comp_avg ){
                struct Student tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
 
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            // cmp j & j+1
            struct Student *student1 = &(students[j]);
            struct Student *student2 = &(students[j+1]);
            if(fcmp(student1->gpa_avg, student2->gpa_avg) &&
               fcmp(student1->comp_avg, student2->comp_avg) &&
               !fcmp(student1->elec_avg, student2->elec_avg) &&
               student1->elec_avg > student2->elec_avg){
                struct Student tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
 
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            // cmp j & j+1
            struct Student *student1 = &(students[j]);
            struct Student *student2 = &(students[j+1]);
            if(fcmp(student1->gpa_avg, student2->gpa_avg) &&
               fcmp(student1->comp_avg, student2->comp_avg) &&
               fcmp(student1->elec_avg, student2->elec_avg) &&
               student1->major > student2->major){
                struct Student tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
 
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            // cmp j & j+1
            struct Student *student1 = &(students[j]);
            struct Student *student2 = &(students[j+1]);
            if(fcmp(student1->gpa_avg, student2->gpa_avg) &&
               fcmp(student1->comp_avg, student2->comp_avg) &&
               fcmp(student1->elec_avg, student2->elec_avg) &&
               student1->major == student2->major &&
               student1->total > student2->total){
                struct Student tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }
 
    int num_of_scholor = (n-1)/20 + 1;
    printf("%d\n", num_of_scholor);
    for(int i = n-1, j = 0; j < num_of_scholor; i--, j++){
        printf("%s\n", students[i].id);
    }
}