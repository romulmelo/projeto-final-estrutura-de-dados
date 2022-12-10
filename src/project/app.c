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
