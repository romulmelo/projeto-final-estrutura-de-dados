#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(void) {
  Queue *q = create(TAM);

  insertItem(q, 1);
  insertItem(q, 2);
  insertItem(q, 3);

  findItem(q, 4);
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
int isQueueFull(Queue *q) {
  return q->qty == q->max_items;
}

int isQueueEmpty(Queue *q) {
  return q->qty == 0;
}

int findItem(Queue *q, int number) {
  Node *head = q->head;

  while (head) {
    if (head->number == number) {
      printf("Found!\n");
      return 1;
    }

    head = head->next;
  }

  printf("Not found!\n");
  return 0;
}

void insertItem(Queue *q, int number) {
  if (isQueueFull(q)) {
    printf("Queue is full.\n");
    return;
  }

  Node *node = (Node*) malloc(sizeof(Node));

  if (node != NULL) {
    node->number = number;
    node->next = NULL;

    if (isQueueEmpty(q)) {
      q->head = node;
      q->tail = node;
    } else {
      q->tail->next = node;
      q->tail = node;
    }

    q->qty++;
  }
}

void removeItem(Queue *q) {
  if (q->head == NULL) {
    return;
  } else if (isQueueEmpty(q)) {
    printf("Queue is empty.\n");
    return;
  }

  Node *head = q->head;

  q->head = q->head->next;
  free(head);

  if (q->head == NULL) {
    q->tail = NULL;
  }

  q->qty--;
}
