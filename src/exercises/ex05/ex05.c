#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int qty;
} Stack;

Stack *create() {
  Stack *s = (Stack *) malloc(sizeof(Stack));

  if (s != NULL) {
    s->top = NULL;
    s->qty = 0;
  }

  return s;
}

int isStackEmpty(Stack *s) {
  return (s->qty == 0);
}

void insertItem(Stack *s, int number) {
  Node *node = (Node *) malloc(sizeof(Node));

  if (node != NULL) {
    node->number = number;
    node->next = s->top;
    s->top = node;
    s->qty++;
  }
}

Stack *fillInputStack() {
  Stack *s = create();

  do {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 0) {
      break;
    }

    insertItem(s, number);
  } while (1);

  return s;
}

void generateEvenAndOddStack(Stack *even, Stack *odd, Stack *input) {
  Node *top = input->top;

  while (top) {
    if (top->number % 2 == 0) {
      insertItem(even, top->number);
    } else {
      insertItem(odd, top->number);
    }

    top = top->next;
  }
}

void show(Stack *s) {
  Node *top = s->top;

  if (isStackEmpty(s)) {
    printf("Stack is empty!\n");
    return;
  }

  while(top) {
    if (top != NULL) {
      printf("%d ", top->number);
      top = top->next;
    }
  }

  printf("\n---------------------\n");
}

int main(int argc, char const *argv[]) {
  Stack *s = fillInputStack();

  return 0;
}
