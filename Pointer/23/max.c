int max(int *iptr[], int n){
    int ret = -1e9;
    for(int i = 0; i < n; i++){
        if(*iptr[i] > ret) ret = *iptr[i];
    }
    return ret;
}