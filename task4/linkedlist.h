#ifndef LIST_H
#define LIST_H

#include <stdlib.h>


typedef struct Leaf {
  int value;
  struct Leaf* next;
} Leaf;

typedef struct {
  Leaf* head;
  Leaf* tail;
} LinkedList;

LinkedList* createList();

int push(LinkedList* list, int value);
int insert(LinkedList* list, int value, int index);
int removeAt(LinkedList* list, int index, int* value);
int get(LinkedList list, int index, int* value);
int next(LinkedList* list, int* value);
void freeList(LinkedList* list);


#endif
