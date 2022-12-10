#include <stdio.h>
#include <stdlib.h>
#include "App.h"

int main(int argc, char const *argv[]) {
  return 0;
}

Queue *createQueue() {
  Queue *q = (Queue*) malloc(sizeof(Queue));

  if (q != NULL) {
    q->head = NULL;
    q->tail = NULL;
    q->qty = 0;
  }

  return q;
}

Wine *createWine() {
  Wine *w = (Wine*) malloc(sizeof(Wine));

  if (w != NULL) {
    fflush(stdin);
    printf("Name: ");
    scanf("%s", w->name);

    fflush(stdin);
    printf("Birthplace: ");
    scanf("%s", w->birthplace);

    fflush(stdin);
    printf("Grape type: ");
    scanf("%s", w->grapeType);

    fflush(stdin);
    printf("Harvest: ");
    scanf("%d", &w->harvest);
  }

  return w;
}

int isQueueEmpty(Queue *q) {
  return q->qty == 0;
}

void insertItem(Queue *q, Wine *w) {
  Node *node = (Node*) malloc(sizeof(Node));

  if (node != NULL) {
    node->wine = w;
    node->next = NULL;

    if (isQueueEmpty(q)) {
      node->prev = NULL;
      q->head = node;
    } else {
      node->prev = q->tail;
      q->tail->next = node;
    }

    q->tail = node;
    q->qty++;
  }
}
