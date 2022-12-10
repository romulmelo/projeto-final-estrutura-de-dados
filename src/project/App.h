#define MAX 50

typedef struct wine {
  char name[MAX];
  char birthplace[MAX];
  char grapeType[MAX];
  int harvest;
} Wine;

typedef struct node {
  Wine *wine;
  struct node *next;
  struct node *prev;
} Node;

typedef struct queue {
  Node *head;
  Node *tail;
  int qty;
} Queue;

Queue *createQueue();
Wine *createWine();
int isQueueEmpty(Queue *q);
void insertItem(Queue *q, Wine *w);
void removeItem(Queue *q);
void showUniqueWine(Wine *w);
void showLatestWineList(Queue *q);)
