#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include <stdbool.h>

void init_storage(Employee **storage, int n){
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage){
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id(Employee *set, int n, int id){
    for(int i = 0; i < n; i++)
        if(set[i].id == id)
            return set+i;
    return NULL;
}

Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i = 0; i < n; i++)
        if(strcmp(set[i].first_name, first_name) == 0 && strcmp(set[i].last_name, last_name) == 0)
            return set+i;
    return NULL;
}

// Employee* find_root_boss( Employee *set, int n, Employee *employee );

bool cmp_name(Employee *A, Employee *B){
    return (strcmp(A->first_name, B->first_name) == 0 && strcmp(A->last_name, B->last_name) == 0);
}

bool found(int arr[], int n, int tar){
    for(int i = 0; i < n; i++)
        if(tar == arr[i])
            return true;
    return false;
}

int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *cur = A;
    while(cur->boss_id != cur->id){
        cur = find_employee_by_id(set, n, cur->boss_id);
        if(cmp_name(cur, B)) return 1;
    }
    cur = B;
    while(cur->boss_id != cur->id){
        cur = find_employee_by_id(set, n, cur->boss_id);
        if(cmp_name(cur, A)) return 2;
    }
    int supervisorOfA[40] = {}, idx = 0;
    cur = A;
    while(cur->boss_id != cur->id){
        cur = find_employee_by_id(set, n, cur->boss_id);
        supervisorOfA[idx++] = cur->id;
    }
    cur = B;
    while(cur->boss_id != cur->id){
        cur = find_employee_by_id(set, n, cur->boss_id);
        if(found(supervisorOfA, idx, cur->id))
            return 3;
    }
    return 4;
}