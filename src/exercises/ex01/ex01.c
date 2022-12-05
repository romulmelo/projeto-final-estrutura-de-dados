#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(void) {
  Stack *s = create(TAM);

  return 0;
}

Stack *create(int max_items) {
  Stack *s = (Stack *) malloc(sizeof(Stack));

  if (s != NULL) {
    s->top = NULL;
    s->max_items = max_items;
    s->qty = 0;
  }

  return s;
}

int isStackEmpty(Stack *s) {
  return (s->qty == 0);
}
