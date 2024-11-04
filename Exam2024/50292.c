#include <stdio.h>
 
int main(){
    int x1, y1, x2, y2, ans[4] = {};
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 
    if(x1*x2 >= 0 && y1*y2 >= 0){
        if(x2 > 0 && y2 > 0) ans[0] = (x2-x1)*(y2-y1);
        else if(x1 < 0 && y1 >= 0) ans[1] = (x2-x1)*(y2-y1);
        else if(x1 < 0 && y1 < 0) ans[2] = (x2-x1)*(y2-y1);
        else if(x2 > 0 && y2 <= 0) ans[3] = (x2-x1)*(y2-y1);
    }else if(x1*x2 < 0 && y1*y2 > 0 && y1 > 0){
        ans[0] = (x2)*(y2-y1);
        ans[1] = (-x1)*(y2-y1);
    }else if(x1*x2 < 0 && y1*y2 > 0 && y1 < 0){
        ans[3] = (x2)*(y2-y1);
        ans[2] = (-x1)*(y2-y1);
    }else if(x1*x2 > 0 && y1*y2 < 0 && x1 > 0){
        ans[0] = (x2-x1)*(y2);
        ans[3] = (x2-x1)*(-y1);
    }else if(x1*x2 > 0 && y1*y2 < 0 && x1 < 0){
        ans[1] = (x2-x1)*(y2);
        ans[2] = (x2-x1)*(-y1);
    }else{
        ans[0] = x2*y2;
        ans[1] = -x1*y2;
        ans[2] = x1*y1;
        ans[3] = x2*-y1;
    }
 
 
    for(int i = 0; i < 4; i++) printf("%d\n", ans[i]);
}