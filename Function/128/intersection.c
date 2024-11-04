void intersection(int map[100][100], int result[4]){
    int city[102][102] = {};
    int n = 100;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            city[i][j] = map[i-1][j-1];
        
    // up down left right
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};

    int intersection = 0, Tjunction = 0, turn = 0, dead = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!city[i][j]) continue;
            int count = 0;
            for(int k = 0; k < 4; k++)
                count += city[i + dirx[k]][j + diry[k]];
            
            #ifdef DEBUG
            printf("%d ", count);
            #endif
            
            switch(count){
                case 4: intersection++; break;
                case 3: Tjunction++; break;
                case 2:
                    if((city[i-1][j] == city[i+1][j]) || (city[i][j-1] == city[i][j+1])) break;
                    turn++; break;
                case 1: dead++; break;
                default: break;
            }
        }
    }
    
    result[0] = intersection;
    result[1] = Tjunction;
    result[2] = turn;
    result[3] = dead;
}