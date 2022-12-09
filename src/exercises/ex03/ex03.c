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

int main(int argc, char const *argv[]) {
  return 0;
}
