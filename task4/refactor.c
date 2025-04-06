#include "refactor.h"

void shift(int**, int, int, int);
void shiftRight(int**, int, int);
void shiftLeft(int**, int, int);
int digitSum(int);

int refactorNumbers(LinkedList* numbers, int minValue) {
  int value = 0;
  int index = 0;
  if (next(numbers, &value)) {
    return 1;
  }
  do {
    if (digitSum(value) < minValue) {
      removeAt(numbers, index, NULL);
      index--;
    } else {
      unsigned long sum = 0;
      status s = 0;
      s = isArmstrong(value, &sum);
      switch (s) {
        case IS_ARMSTRONG:
          insert(numbers, value, index);
	  index++;
          break;
        case ERR:
          return -1;
      }
    }
    index++;
  } while (next(NULL, &value) == 0);
  return 0;
}

int digitSum(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}
