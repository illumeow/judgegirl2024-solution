#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    double nums[100005], sum = 0;
    for(int i = 0; i < n; i++){
        double num;
        scanf("%lf", &num);
        nums[i] = num;
        sum += num;
    }
    double mean = sum / n;
    sum = 0;
    for(int i = 0; i < n; i++)
        sum += ((nums[i] - mean)*(nums[i] - mean));
    printf("%lf\n%lf", mean, sum/n);
}