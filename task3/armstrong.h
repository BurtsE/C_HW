#ifndef ARMSTRONG_H
#define ARMSTRONG_H

#include <math.h>

typedef enum {
  IS_ARMSTRONG = 1,
  NOT_ARMSTRONG = 0,
  ERR = -1
} status;

int isArmstrong(unsigned long n, unsigned long* sum);

int digitsCount(unsigned long n) ;

#endif
