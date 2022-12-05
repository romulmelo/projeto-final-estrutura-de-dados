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
