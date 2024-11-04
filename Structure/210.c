#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 50

typedef struct {
    char lastname[90];
    char firstname[90];
    char ID[90];
    int salary, age;
} Person;

void helper(char fields[][10], int indx, Person p){
    for(int i = 0; i < indx; i++){
        if(strcmp(fields[i], "lastname") == 0)
            printf("%s ", p.lastname);
        else if(strcmp(fields[i], "firstname") == 0)
            printf("%s ", p.firstname);
        else if(strcmp(fields[i], "ID") == 0)
            printf("%s ", p.ID);
        else if(strcmp(fields[i], "salary") == 0)
            printf("%d ", p.salary);
        else printf("%d ", p.age);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    Person data[MAXN];
    for(int i = 0; i < n; i++)
        scanf("%s%s%s%d%d", data[i].lastname, data[i].firstname, data[i].ID, &data[i].salary, &data[i].age);
    int m;
    scanf("%d", &m);
    char fields[10][10];
    char s[10];
    for(int i = 0; i < m; i++){
        int indx = 0;
        scanf("%s", s);  // select
        do {
            scanf("%s", s);
            strcpy(fields[indx], s);
            indx++;
        }while(strcmp(s, "where") != 0);
        indx--;
        char field[10], operator[3], constant[90];
        scanf("%s%s%s", field, operator, constant);

        if(strcmp(field, "lastname") == 0){
            if(strcmp(operator, "==") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.lastname, constant) == 0)
                        helper(fields, indx, person);
                }
            }
            else{  // !=
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.lastname, constant) != 0)
                        helper(fields, indx, person);
                }
            }
        }
        else if(strcmp(field, "firstname") == 0){
            if(strcmp(operator, "==") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.firstname, constant) == 0)
                        helper(fields, indx, person);
                }
            }
            else{  // !=
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.firstname, constant) != 0)
                        helper(fields, indx, person);
                }
            }
        }
        else if(strcmp(field, "ID") == 0){
            if(strcmp(operator, "==") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.ID, constant) == 0)
                        helper(fields, indx, person);
                }
            }
            else{  // !=
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(strcmp(person.ID, constant) != 0)
                        helper(fields, indx, person);
                }
            }
        }
        else if(strcmp(field, "salary") == 0){
            int constant_int = atoi(constant);
            if(strcmp(operator, ">") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.salary > constant_int)
                        helper(fields, indx, person);
                }
            }
            else if(strcmp(operator, "<") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.salary < constant_int)
                        helper(fields, indx, person);
                }
            }
            else{  // ==
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.salary == constant_int)
                        helper(fields, indx, person);
                }
            }
        }
        else if(strcmp(field, "age") == 0){
            int constant_int = atoi(constant);
            if(strcmp(operator, ">") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.age > constant_int)
                        helper(fields, indx, person);
                }
            }
            else if(strcmp(operator, "<") == 0){
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.age < constant_int)
                        helper(fields, indx, person);
                }
            }
            else{  // ==
                for(int j = 0; j < n; j++){
                    Person person = data[j];
                    if(person.age == constant_int)
                        helper(fields, indx, person);
                }
            }
        }
    }
}