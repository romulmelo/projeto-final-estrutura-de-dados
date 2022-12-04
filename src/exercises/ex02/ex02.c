#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(void) {
  Queue *q = create(TAM);

  return 0;
}

Queue *create(int max_items) {
  Queue *q = (Queue*) malloc(sizeof(Queue));

  if (q != NULL) {
    q->head = NULL;
    q->tail = NULL;
    q->max_items = max_items;
    q->qty = 0;
  }

  return q;
}

int isQueueEmpty(Queue *q) {
  return q->qty == 0;
}
