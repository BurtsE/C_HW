#include "linkedlist.h"

LinkedList* createList() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

int push(LinkedList* list, int value) {
  if (!list) {
    return -2;
  }
  Leaf* l = (Leaf*)malloc(sizeof(Leaf));
  if (!l) {
    return -1;
  }
  l->value = value;
  l->next = NULL;
  if (list->tail) {
    (list->tail)->next = l;
    list->tail = l;
    return -2;
  }
  list->head = l;
  list->tail = l;
  return 0;
}

int insert(LinkedList* list, int value, int index) {
  Leaf* l = (Leaf*)malloc(sizeof(Leaf));
  l->value = value;
  Leaf* temp = list->head;
  int current = 0;
  while (temp && current < index-1) {
    temp = temp->next;
  }
  if (!temp) {
    free(l);
    return -1;
  }
  l->next = temp->next;
  temp->next = l;
}


int removeAt(LinkedList* list, int index, int* value) {
  if (!list || !list->head) {
    return -1;
  }
  if (index == 0) {
    Leaf* temp = list->head;
    list->head = list->head->next;
    free(temp);
    return 0;
  }

  Leaf* temp = list->head;
  int current = 0;
  while (temp->next && current < index-1) {
    temp = temp->next;
  }
  if (!temp->next) {
    return -2;
  }
  Leaf* next = temp->next->next;
  if (value) {
    *value = temp->value;
  }
  free(temp->next);
  temp->next = next;
  return 0;
}

int get(LinkedList list, int index, int* value) {
  if (!list.head) {
    return -1;
  }
  Leaf* temp = list.head;
  int current = 0;
  while (temp && current < index) {
    temp = temp->next;
  }
  if (!temp) {
    return -2;
  }
  *value = temp->value;
  return 0;
}

int next(LinkedList* list, int* value) {
  static Leaf* pointer = NULL;
  if (list) {
    pointer = list->head;
  }
  if (pointer == NULL) {
    return -1;
  }
  *value = pointer->value;
  pointer = pointer->next;
  return 0;
}

void freeList(LinkedList* list) {
    if (!list) return;
    Leaf* temp;
    Leaf* head = list->head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    free(list);
}

