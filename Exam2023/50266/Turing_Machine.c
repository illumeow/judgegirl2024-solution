void Turing_Machine(int *head, int K){
    /*
    write first, then move
    initial state: s0
    */
    int nextState[3][4] = {{2, 1, 2, 1}, {2, 0, 2, 0}, {1, 0, 1, 0}};
    int moveHead[3][4] = {{1, 1, 1, 1}, {-1, 1, -1, 1}, {0, -1, 1, 0}};

    int state = 0;
    for(int i = 0; i < K; i++){
        int value = *head;
        *head = (value + state) % 4;
        head += moveHead[state][value];
        state = nextState[state][value];
    }
}