#include <stdio.h>
#include <stdlib.h>

#define checklist for(int i = 0; i < n; i++) printf("%d: (%d, %d) c:%d o:%d\n", parking_lots[i].indx, parking_lots[i].p.x, parking_lots[i].p.y, parking_lots[i].capacity, parking_lots[i].occupied);\
              printf("\n");\
    

typedef struct{
    int x, y;
} Point;

Point ref;

typedef struct{
    Point p;
    int capacity;
    int occupied;
    int indx;
} Parking_Lot;

int dis(Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int cmpdis(const void* a, const void* b){
    const Parking_Lot *A = a, *B = b;
    int disA = dis(A->p, ref), disB = dis(B->p, ref);
    if(disA == disB){
        if(A->p.x == B->p.x) return ((A->p.y > B->p.y)-(A->p.y < B->p.y));
        return ((A->p.x> B->p.x)-(A->p.x < B->p.x));
    }
    return (disA > disB)-(disA < disB);
}

int cmpindx(const void* a, const void* b){
    const Parking_Lot *A = a, *B = b;
    return A->indx - B->indx;
}


int main(){
    // input
    int n;
    scanf("%d", &n);
    Parking_Lot parking_lots[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &parking_lots[i].p.x, &parking_lots[i].p.y, &parking_lots[i].capacity);
        parking_lots[i].occupied = 0;
        parking_lots[i].indx = i;
    }
    int m;
    scanf("%d", &m);
    Point bicycles[m];
    for(int i = 0; i < m; i++) scanf("%d%d", &bicycles[i].x, &bicycles[i].y);

    // checklist
    
    //printf("start for loop\n");
    for(int i = 0; i < m; i++){
        ref.x = bicycles[i].x;
        ref.y = bicycles[i].y;
        qsort(parking_lots, n, sizeof(Parking_Lot), cmpdis);
        for(int j = 0; j < n; j++){
            if(parking_lots[j].occupied < parking_lots[j].capacity){
                parking_lots[j].occupied++;
                break;
            }
        }
        // checklist
    }

    
    qsort(parking_lots, n, sizeof(Parking_Lot), cmpindx);
    /* printf("sort by index\n");
    checklist */
    for(int i = 0; i < n; i++) printf("%d\n", parking_lots[i].occupied);
}