#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int qty;
} Stack;

Stack *create() {
  Stack *s = (Stack *) malloc(sizeof(Stack));

  if (s != NULL) {
    s->top = NULL;
    s->qty = 0;
  }

  return s;
}

int isStackEmpty(Stack *s) {
  return (s->qty == 0);
}

void insertItem(Stack *s, int number) {
  Node *node = (Node *) malloc(sizeof(Node));

  if (node != NULL) {
    node->number = number;
    node->next = s->top;
    s->top = node;
    s->qty++;
  }
}

Stack *fillInputStack() {
  Stack *s = create();

  do {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 0) {
      break;
    }

    insertItem(s, number);
  } while (1);

  return s;
}

int main(int argc, char const *argv[]) {
  Stack *s = fillInputStack();

  return 0;
}
