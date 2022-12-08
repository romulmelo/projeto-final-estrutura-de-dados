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

int main(int argc, char const *argv[]){
  Queue *st = create(5);
  Queue *nd = create(5);
  Queue *rd = create(10);

  return 0;
}
