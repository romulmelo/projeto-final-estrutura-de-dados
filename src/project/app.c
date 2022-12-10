#include <stdio.h>
#include <stdlib.h>
#include "App.h"

int main(int argc, char const *argv[]) {
  Queue *wines = createQueue();
  Queue *specialWines = createQueue();

  int option = menu();

  while (option != 7) {
    switch (option) {
      case 1:
        addNewWine(wines);
        break;
      case 2:
        insertItem(specialWines, wines->tail->wine);
        break;
      case 3:
        if (!isQueueEmpty(wines)) {
          showUniqueWine(wines->head->wine);
          removeItem(wines);
        } else {
          printf("Queue is empty.\n");
        }
        break;
      case 4:
        showUniqueWine(specialWines->tail->wine);
        break;
      case 5:
        showOldestWineList(wines);
        break;
      case 6:
        showLatestWineList(wines);
        break;
      case 7:
        showQueueItems(wines);
        showQueueItems(specialWines);
        exit(0);
        break;
      default:
        printf("Invalid option.\n");
        break;
    }

    option = menu();
  }

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

int menu() {
  fflush(stdin);

  int option;

  printf("\n--------------------\n");
  printf("1 -- Add a new wine\n");
  printf("2 -- Add most recent wine to special list\n");
  printf("3 -- Show non-special older wine\n");
  printf("4 -- Show latest special wine\n");
  printf("5 -- Show five older wines\n");
  printf("6 -- Show five most recent wines\n");
  printf("7 -- Exit\n");
  printf("\n--------------------\n");

  scanf("%d", &option);

  return option;
}

int isQueueEmpty(Queue *q) {
  return q->qty == 0;
}

void sortAscedingQueue(Queue *q) {
  if (!isQueueEmpty(q)) {
    Node *node = q->head;

    for (int i = 0; i < node; i++) {
      Node *node2 = node->next;

      for (int j = i + 1; j < node2; j++) {
        if (node->wine->harvest > node2->wine->harvest) {
          Wine *aux = node->wine;
          node->wine = node2->wine;
          node2->wine = aux;
        }

        node2 = node2->next;
      }

      node = node->next;
    }
  } else {
    printf("Queue is empty.\n");
  }
}

void insertItem(Queue *q, Wine *w) {
  Node *node = (Node*) malloc(sizeof(Node));

  if (node != NULL) {
    node->wine = w;
    node->next = NULL;

    if (isQueueEmpty(q)) {
      node->prev = NULL;
      q->head = node;
    } else {
      node->prev = q->tail;
      q->tail->next = node;
    }

    q->tail = node;
    q->qty++;
  }
}

void removeItem(Queue *q) {
  if (!isQueueEmpty(q)) {
    Node *node = q->head;

    q->head = node->next;

    if (q->head != NULL) {
      q->head->prev = NULL;
    }

    free(node);
    q->qty--;
  } else {
    printf("Queue is empty.\n");
  }
}

void showQueueItems(Queue *q) {
  if (!isQueueEmpty(q)) {
    Node *node = q->head;

    while (node) {
      showUniqueWine(node->wine);
      node = node->next;
    }
  } else {
    printf("Queue is empty.\n");
  }
}

void showUniqueWine(Wine *w) {
  printf("\n--------------------\n");
  printf("Name: %s\n", w->name);
  printf("Birthplace: %s\n", w->birthplace);
  printf("Grape type: %s\n", w->grapeType);
  printf("Harvest: %d\n", w->harvest);
  printf("\n--------------------\n");
}

void showLatestWineList(Queue *q) {
  if (!isQueueEmpty(q)) {
    Node *node = q->tail;

    for (int i = 0; i < node && i < 5; i++) {
      showUniqueWine(node->wine);
      node = node->prev;
    }
  } else {
    printf("Queue is empty.\n");
  }
}

void showOldestWineList(Queue *q) {
  if (!isQueueEmpty(q)) {
    Node *node = q->head;

    for (int i = 0; i < node && i < 5; i++) {
      showUniqueWine(node->wine);
      node = node->next;
    }
  } else {
    printf("Queue is empty.\n");
  }
}

void addNewWine(Queue *q) {
  Wine *new_wine = createWine();
  insertItem(q, new_wine);

  sortAscedingQueue(q);
  printf("Wine added successfully.\n");
}
