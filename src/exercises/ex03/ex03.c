#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int max_items;
  int qty;
} Stack;

Stack *create(int max_items) {
  Stack *s = (Stack*) malloc(sizeof(Stack));

  if (s != NULL) {
    s->top = NULL;
    s->max_items = max_items;
    s->qty = 0;
  }

  return s;
}

int isStackEmpty(Stack *s) {
  return s->qty == 0;
}

int isStackFull(Stack *s) {
  return s->qty == s->max_items;
}

void insertItem(Stack *s, int value) {
  if (isStackFull(s)) {
    printf("Stack is full!\n");
    return;
  }

  Node *node = (Node*) malloc(sizeof(Node));

  if (node != NULL) {
    node->value = value;
    node->next = s->top;
    s->top = node;
    s->qty++;
  }
}

int main(int argc, char const *argv[]) {
  return 0;
}
