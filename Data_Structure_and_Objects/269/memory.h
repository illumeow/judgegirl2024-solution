typedef struct node {
    int start, length;
    struct node *next; 
} Node;

typedef struct memory {
    Node *head;
} Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);