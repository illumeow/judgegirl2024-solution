void snake(const int *ptr_array[100][100], int m){
    /* 
    sort ptr_array, 
    it is a (int const *) array so the value of pointer can not be changed,
    while the pointer itself can.
    consider arr[i][j] = *(arr + i) + j
    */
   int const * arr[10000];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            arr[i*m + j] = ptr_array[i][j];

    for(int i = m*m - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(*arr[j] > *arr[j+1]){
                int const * tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ptr_array[i][(i&1)?(m-1-j):j] = arr[i*m + j];
        }
    }

    // for(int i = 1; i < m; i += 2)
    //     reverse(ptr_array[i], m);
}