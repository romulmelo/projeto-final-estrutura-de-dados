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

void sortingAscedingStack(Stack *s) {
  Node *aux = s->top;
  int temp;

  while (aux != NULL) {
    Node *aux2 = aux->next;

    while (aux2 != NULL) {
      if (aux->value > aux2->value) {
        temp = aux->value;
        aux->value = aux2->value;
        aux2->value = temp;
      }

      aux2 = aux2->next;
    }

    aux = aux->next;
  }
}

void sortingDescendingStack(Stack *s) {
  Node *aux = s->top;
  int temp;

  while (aux != NULL) {
    Node *aux2 = aux->next;

    while (aux2 != NULL) {
      if (aux->value < aux2->value) {
        temp = aux->value;
        aux->value = aux2->value;
        aux2->value = temp;
      }

      aux2 = aux2->next;
    }

    aux = aux->next;
  }
}

void generateNewStack(Stack *st, Stack *nd, Stack *rd) {
  Node *aux = st->top;

  while (aux) {
    insertItem(rd, aux->value);
    aux = aux->next;
  }

  aux = nd->top;

  while (aux) {
    insertItem(rd, aux->value);
    aux = aux->next;
  }

  sortingDescendingStack(rd);
}

void show(Stack *s) {
  Node *top = s->top;

  if (isStackEmpty(s)) {
    printf("Stack is empty!");
    return;
  }

  printf("\n---------------------\n");

  while(top) {
    if (top != NULL) {
      printf("%d ", top->value);
      top = top->next;
    }
  }

  printf("\n---------------------\n");
}

int main(int argc, char const *argv[]) {
  Stack *st = create(10);
  Stack *nd = create(10);
  Stack *rd = create(20);

  insertItem(st, 11);
  insertItem(st, 7);
  insertItem(st, 3);
  insertItem(st, 24);
  insertItem(st, 54);

  insertItem(nd, 1);
  insertItem(nd, 2);
  insertItem(nd, 6);
  insertItem(nd, 8);

  sortingAscedingStack(st);
  sortingAscedingStack(nd);

  generateNewStack(st, nd, rd);

  show(st);
  show(nd);
  show(rd);

  return 0;
}
