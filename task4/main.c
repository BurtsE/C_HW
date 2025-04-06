#include <stdio.h>
#include <math.h>
#include "refactor.h"
#include "linkedlist.h"


int main() {
  int num;
  int sum = 0;
  status s;
  LinkedList* list = createList();
  if (!list) {
    exit(-1);
  }
  printf("Enter numbers:\n");
  while(scanf("%d", &num) != EOF) {
    push(list, num);
  }

  int value = 0;

  int status = refactorNumbers(list, 7);
  printf("Result values:\n");
  if (next(list, &value)) {
   printf("Empty array\n");
   return 0;
  }
  do {
    printf("%d ", value);
  } while(!next(NULL, &value));
  printf("\n");
  freeList(list);
  return 0;
}

