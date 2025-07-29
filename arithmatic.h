#ifndef ARITHMATIC_H
#define ARITHMATIC_H

#include <stdint.h>
#include <math.h>
#include "main.h"

double addFun(float num1, float num2);
double subFun(float num1, float num2);
double mulFun(float num1, float num2);
double divFun(float num1, float num2);
int    remainderFun(int num1, int num2);
double rootFun(float num1);
double powerFun(float base, float exponent);
long long factorialFun(int num);

#endif /* ARITHMATIC_H */
