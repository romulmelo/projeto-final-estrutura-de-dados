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

int main(int argc, char const *argv[]){
  return 0;
}
