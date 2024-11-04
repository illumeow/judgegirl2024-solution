#include "employee.h"
#include <string.h>
#include <stdio.h>

int relation(Employee *employee1, Employee *employee2) {
    // subordinate: 1
    Employee *now = employee1;
    while(now->boss != now){
        now = now->boss;
        if(strcmp(now->first_name, employee2->first_name) == 0 && strcmp(now->last_name, employee2->last_name) == 0)
            return 1;
    }

    // supervisor: 2
    now = employee2;
    while(now->boss != now){
        now = now->boss;
        if(strcmp(now->first_name, employee1->first_name) == 0 && strcmp(now->last_name, employee1->last_name) == 0)
            return 2;
    }

    // colleage: 3
    now = employee1;
    char bossOf1_f[35][32], bossOf1_l[35][32];
    int indx = 0;
    while(now->boss != now){
        now = now->boss;
        strcpy(bossOf1_f[indx], now->first_name);
        strcpy(bossOf1_l[indx], now->last_name);
        indx++;
    }
    now = employee2;
    while(now->boss != now){
        now = now->boss;
        for(int i = 0; i < indx; i++){
            if(strcmp(now->first_name, bossOf1_f[i]) == 0 && strcmp(now->last_name, bossOf1_l[i]) == 0)
                return 3;
        }
    }

    return 4;
}