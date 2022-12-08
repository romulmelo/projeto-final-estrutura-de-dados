#define MAX 5

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct queue {
  Node *head;
  Node *tail;
  int max_items;
  int qtdy;
} Queue;

int isQueueFull(Queue *queue){
  return queue->qtdy == queue->max_items;
}

int isQueueEmpty(Queue *queue){
  return queue->qtdy == 0;
}

Queue *create(int max_items){
  Queue *queue = (Queue *) malloc(sizeof(Queue));

  if (queue != NULL){
    queue->head = NULL;
    queue->tail = NULL;
    queue->max_items = max_items;
    queue->qtdy = 0;
  }

  return queue;
}

void insertItem(Queue *q, int number) {
  if (isQueueFull(q)) {
    printf("Queue is full.\n");
    return;
  }

  Node *node = (Node*) malloc(sizeof(Node));

  if (node != NULL) {
    node->value = number;
    node->next = NULL;

    if (isQueueEmpty(q)) {
      q->head = node;
      q->tail = node;
    } else {
      q->tail->next = node;
      q->tail = node;
    }

    q->qtdy++;
  }
}

void sortingAscedingQueue(Queue *q) {
  Node *head = q->head;
  Node *aux = NULL;
  int temp;

  while (head) {
    aux = head->next;

    while (aux) {
      if (head->value > aux->value) {
        temp = head->value;
        head->value = aux->value;
        aux->value = temp;
      }

      aux = aux->next;
    }

    head = head->next;
  }
}

int main(int argc, char const *argv[]){
  Queue *st = create(MAX);
  Queue *nd = create(MAX);
  Queue *rd = create(MAX * 2);

  insertItem(st, 12);
  insertItem(st, 7);
  insertItem(st, 45);

  insertItem(nd, 25);
  insertItem(nd, 13);
  insertItem(nd, 10);

  return 0;
}
