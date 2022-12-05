// This current value is only used for debugging purposes.
#define TAM 5

typedef struct Node{
  int number;
  struct Node *next;
} Node;

typedef struct {
  Node* head;
  Node* tail;

  int max_items;
  int qty;
} Queue;

Queue *create(int max_items);

int size(Queue *q);
int isQueueFull(Queue *q);
int isQueueEmpty(Queue *q);
int findItem(Queue *q, int number);
void insertItem(Queue *q, int number);
void removeItem(Queue *q);
