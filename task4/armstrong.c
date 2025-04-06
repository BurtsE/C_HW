
#include <math.h>
#include "armstrong.h"

int isArmstrong(unsigned long n, unsigned long* sum) {
  int exp = digitsCount(n);
  unsigned long temp = n;
  unsigned long tempSum = *sum;
  int digit = 0;
  while (temp > 0) {
    digit = temp % 10;
    tempSum += (unsigned long)pow(digit, exp);
    if (*sum > tempSum) {
      return ERR;
    }
    *sum = tempSum;
    temp /= 10;
  }
  if (n == *sum) {
    return IS_ARMSTRONG;
  }
  return NOT_ARMSTRONG;
}


int digitsCount(unsigned long n) {
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}
