#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char first_name[32];
    char last_name[32];
} Name;

typedef struct {
  int id;
  Name name;
  int boss_id;
} Employee;

int find_by_id(Employee e[], int n, int tar_id){
    for(int i = 0; i < n; i++)
        if(e[i].id == tar_id)
            return i;
    return -1;
}

bool cmp_name(Employee A, Name N){
    return (strcmp(A.name.first_name, N.first_name) == 0 && strcmp(A.name.last_name, N.last_name) == 0);
}

int main(){
    int n;
    scanf("%d", &n);
    Employee employees[32];
    for(int i = 0; i < n; i++)
        scanf("%d%s%s%d", &employees[i].id, employees[i].name.first_name, employees[i].name.last_name, &employees[i].boss_id);
    
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        bool found = false;
        Name name1, name2;
        scanf("%s%s%s%s", name1.first_name, name1.last_name, name2.first_name, name2.last_name);
        
        // find 2 person
        int a = -1, b = -1;
        for(int j = 0; j < n && a == -1 && b == -1; j++){
            if(cmp_name(employees[j], name1)) a = j;
            else if(cmp_name(employees[j], name2)) b = j;
        }

        // subordinate
        int now = a;
        while(employees[now].id != employees[now].boss_id){
            now = find_by_id(employees, n, employees[now].boss_id);
            if(cmp_name(employees[b], employees[now].name)){
                printf("subordinate\n");
                found = true;
                break;
            }
        }

        if(found) continue;

        // supervisor
        now = b;
        while(employees[now].id != employees[now].boss_id){
            now = find_by_id(employees, n, employees[now].boss_id);
            if(cmp_name(employees[a], employees[now].name)){
                printf("supervisor\n");
                found = true;
                break;
            }
        }

        if(found) continue;

        // colleague
        int supervisorOfA[35];
        int indx = 0;
        now = a;
        while(employees[now].id != employees[now].boss_id){
            now = find_by_id(employees, n, employees[now].boss_id);
            supervisorOfA[indx] = now;
            indx++;
        }
        now = b;
        while(employees[now].id != employees[now].boss_id){
            now = find_by_id(employees, n, employees[now].boss_id);
            for(int j = 0; j < indx; j++){
                if(now == supervisorOfA[j]){
                    printf("colleague\n");
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        if(found) continue;
        printf("unrelated\n");
    }
}