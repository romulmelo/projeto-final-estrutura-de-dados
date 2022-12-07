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

  removeItem(s);
  removeItem(s);

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

int size(Stack *s) {
  if (s == NULL) {
    return -1;
  } else {
    return s->qty;
  }
}

int isStackEmpty(Stack *s) {
  return (s->qty == 0);
}

int isStackFull(Stack *s) {
  return (s->qty == s->max_items);
}

int findItem(Stack *s, int number) {
  Node *top = s->top;

  while (top) {
    if (top->number == number) {
      printf("Item %d found!\n", number);
      return 1;
    }

    top = top->next;
  }

  printf("Item not found!\n");
  return 0;
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

void removeItem(Stack *s) {
  if (isStackEmpty(s)) {
    printf("Stack is empty!");
    return;
  }

  Node *node = s->top;
  s->top = node->next;

  free(node);

  s->qty--;
}
