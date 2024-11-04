void count_collision(int *ptr[], int A[], int n, int a, int b, int c){
    /* ptr_size = n, A_size = c, F(x) = ax+b mod c */
    for(int i = 0; i < c; i++) A[i] = 0;
    for(int i = 0; i < n; i++){
        int hash = (a*i+b) % c;
        A[hash]++;
        ptr[i] = &(A[hash]);
    }
    for(int i = 0; i < c; i++) 
        if(A[i]) A[i]--;
}