#include <stdio.h>
#include <math.h>
#include "armstrong.h"


int main() {
  unsigned long num;
  unsigned long sum = 0;
  status s;
  printf("Enter number:\n");
  scanf("%lu", &num);
  s = isArmstrong(num, &sum);
  switch (s) {
    case IS_ARMSTRONG:
      printf("%lu is Armstrong\n", num);
      break;
    case NOT_ARMSTRONG:
      printf("%lu is not Armstrong, sum: %lu\n", num, sum);
      break;
    case ERR:
      printf("Error occured\n");
      break;
  }
  return 0;
}

