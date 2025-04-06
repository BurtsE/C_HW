#include "armstrong.h"
#include "task.h"

void shift(int**, int, int, int);
void shiftRight(int**, int, int);
void shiftLeft(int**, int, int);
int digitSum(int);

int refactorNumbers(int** numbers, int length, int minValue) {
  int newLen = length;
  int i, j;
  *numbers = (int*)realloc(*numbers, sizeof(int) * length * 2);
  if(*numbers == NULL) {
    return -1;
  }
  for (i = 0; i < newLen; ++i) {
    if (digitSum((*numbers)[i]) < minValue) {
      shift(numbers, i+1, newLen, 0);
      newLen--;
      i--;
    } else {
      unsigned long sum = 0;
      status s = 0;
      s = isArmstrong((*numbers)[i], &sum);
      switch (s) {
    	case IS_ARMSTRONG:
	  shift(numbers, i, newLen, 1);
	  (*numbers)[i++] = (*numbers)[i];
	  newLen++;
      	  break;
    	case ERR:
	  free(*numbers);
	  return -1;
      }
    }
  }
  if (!newLen) {
    return newLen;
  }
  *numbers = (int*)realloc(*numbers, sizeof(int) * newLen);
  if (*numbers == NULL) {
    return -1;
  }
  return newLen;
}

void shift(int** numbers, int start, int end, int d) {
  if (d > 0) {
    shiftRight(numbers, start, end);
  } else {
    shiftLeft(numbers, start, end);
  }
}

void shiftRight(int** numbers, int start, int end) {
  int i;
  for (i = end; i > start; --i) {
    (*numbers)[i] = (*numbers)[i-1];
  }
}

void shiftLeft(int** numbers, int start, int end) {
  int i;
  for (i = start; i < end; ++i) {
    (*numbers)[i-1] = (*numbers)[i];
  }
}


int digitSum(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

