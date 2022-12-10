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
