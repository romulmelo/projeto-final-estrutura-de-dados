#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(void) {
  Stack *s = create(TAM);

  insertItem(s, 12);
  insertItem(s, 7);
  insertItem(s, 45);
  insertItem(s, 12);
  insertItem(s, 1);

  return 0;
}

Stack *create(int max_items) {
  Stack *s = (Stack *) malloc(sizeof(Stack));

  if (s != NULL) {
    s->top = NULL;
    s->max_items = max_items;
    s->qty = 0;
  }

  return s;
}

int isStackEmpty(Stack *s) {
  return (s->qty == 0);
}

int isStackFull(Stack *s) {
  return (s->qty == s->max_items);
}

void insertItem(Stack *s, int number) {
  if (isStackFull(s)) {
    printf("Stack is full!");
    return;
  }

  Node *node = (Node *) malloc(sizeof(Node));

  if (node != NULL) {
    node->number = number;
    node->next = s->top;
    s->top = node;
    s->qty++;
  }
}
