// This current value is only used for debugging purposes.
#define TAM 5

typedef struct Node{
  int number;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
  int max_items;
  int qty;
} Stack;

Stack *create(int max_items);

int size(Stack *s);
int isStackEmpty(Stack *s);
int isStackFull(Stack *s);
int findItem(Stack *s, int number);
void show(Stack *s);
void insertItem(Stack *s, int number);
void removeItem(Stack *s);
