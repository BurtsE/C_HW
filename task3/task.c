#include "task.h"

char* formatString(const int*, int);

char *task(const char* str) {
  char *temp = malloc(sizeof(char) * (strlen(str)+1));
  strcpy(temp, str);
  int buf[5] = {};
  int* numbers = NULL;
  int size = 0;
  char* word = strtok(temp, " \t");
  while (word != NULL) {
    int number = (int)strtol(word, NULL, 10);
    if (number) {
      buf[size%5] = number;
      size++;
      if (size%5 == 0) {
      	numbers = (int*)realloc(numbers, size * sizeof(int));
	if (!numbers) {
          free(temp);
	  return NULL;
        }
      	memcpy(numbers+size-5, buf, 5 * sizeof(int));
      }
    }
    word = strtok(NULL, " \t");
  }

  if (size%5 != 0) {
    numbers = (int*)realloc(numbers, size * sizeof(int));
    memcpy(numbers+size-size%5, buf, (size%5) * sizeof(int));
  }
  size = refactorNumbers(&numbers, size, 7);
  char* result = formatString(numbers, size);
  free(numbers);
  free(temp);
  return result;
}


char* formatString(const int* numbers, int size) {
  int i;
  char buf[50];
  char* result = NULL;
  int totalLen = 1;
  for (i = 0; i < size; ++i) {
    sprintf(buf, "%d ", numbers[i]);
    int bufLen = strlen(buf);
    totalLen += bufLen;
    result = (char*)realloc(result, sizeof(char) * totalLen);
    strcpy(result+totalLen-bufLen-1, buf);
  }
  return result;
}
