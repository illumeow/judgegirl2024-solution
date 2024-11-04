#define MAX 500
 
void rotate(int *P[MAX][MAX], int n){
    /* DO NOT change *P aka NO *P = n; */
    /* rotate P in counter-clockwise 90deg 
    -> A^t then hori flip */
    
    // transpose
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int *tmp = P[i][j];
            P[i][j] = P[j][i];
            P[j][i] = tmp;
        }
    }

    // hori flip
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            int *tmp = P[i][j];
            P[i][j] = P[i][n-1-j];
            P[i][n-1-j] = tmp;
        }
    }
}