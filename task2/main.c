#include "task.h"
#include "input.h"

int main() {
  int i = 0, limit;
  int* arr = NULL;
  size_t size;

  size = scanParams(&arr, &limit);

  printArray(arr, size);

  size = refactorNumbers(&arr, size, limit);
  if (size == -1) {
    printf("Some error occured\n");
    return -1;
  }
  printArray(arr, size);
  free(arr);
  return 0;
}

