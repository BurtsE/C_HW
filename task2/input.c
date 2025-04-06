#include "input.h"

#define BUF_SIZE 5

int scanParams(int** arr, int* limit) {
  int buf[5] = {};
  int size = 0;
  printf("Enter limit number\n");
  scanf("%d", limit);
  printf("Enter array\n");
  while (scanf("%d", &buf[size%5]) != EOF) {
      size++;
      if (size%5 == 0) {
        *arr = (int*)realloc(*arr, size * sizeof(int));
        if (!arr) {
          exit(-1);
        }
        memcpy((*arr)+size-5, buf, 5 * sizeof(int));
      }
  }
  if (size%5 != 0) {
    *arr = (int*)realloc(*arr, size * sizeof(int));
    memcpy((*arr)+size-size%5, buf, (size%5) * sizeof(int));
  }
  printf("\n");
  return size;
}


void printArray(int* arr, int size) {
  int i;
  printf("Result array size: %d\n", size);
  for (i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}
