#include <stdio.h>
#include <string.h>

typedef struct person {
    unsigned int id;
    char name[32];
} Person;

typedef struct {
    unsigned int id1;
    unsigned int id2;
} Friends;

unsigned int find_id(char name[], Person arr[], int n){
    for(int i = 0; i < n; i++)
        if(strcmp(name, arr[i].name) == 0)
            return arr[i].id;
    return 20000;
}

int is_friend(unsigned int id1, unsigned int id2, Friends arr[], int n){
    for(int i = 0; i < n; i++)
        if((arr[i].id1 == id1 && arr[i].id2 == id2) || 
           (arr[i].id1 == id2 && arr[i].id2 == id1))
            return 1;
    return 0;
}

int main(){
    // input
    FILE *fp = fopen("friends", "rb");
    int P;
    fread(&P, sizeof(int), 1, fp);
    Person persons[10005] = {};
    fread(persons, sizeof(Person), P, fp);
    int F;
    fread(&F, sizeof(int), 1, fp);
    Friends friends[10005] = {};
    fread(friends, sizeof(Friends), F, fp);
    fclose(fp);
    
    // query
    char name1[32], name2[32];
    while(scanf("%s%s", name1, name2) == 2)
        printf(is_friend(find_id(name1, persons, P), find_id(name2, persons, P), friends, F)? "yes\n": "no\n");
}