#include "task.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
  int i = 0, limit;
  char* line = NULL;
  char* result;
  size_t size;
  printf("Enter your string\n");
  while ((line = readline(NULL)) != NULL) {
    result = task(line);
    printf("Result string:\n%s\n", result);
    free(line);
    free(result);
  }
  return 0;
}

