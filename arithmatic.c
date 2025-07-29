#include "Arithmatic.h"

double addFun(float num1, float num2)    { return (double)(num1 + num2); }
double subFun(float num1, float num2)    { return (double)(num1 - num2); }
double mulFun(float num1, float num2)    { return (double)(num1 * num2); }
double divFun(float num1, float num2)    { 
    if (num2 == 0.0f) return 0.0;  // handled in caller
    return (double)(num1 / num2);
}
int    remainderFun(int num1, int num2)  {
    if (num2 == 0) return 0;
    return num1 % num2;
}
double rootFun(float num1)               {
    if (num1 < 0.0f) return -1.0;
    return sqrt((double)num1);
}
double powerFun(float base, float exp)   { return pow((double)base, (double)exp); }
long long factorialFun(int num)          {
    if (num < 0) return -1;
    if (num < 2) return 1;
    long long res = 1;
    for (int i = 2; i <= num; ++i)
    {
        res *= i;
        if (res < 0) return -1; // overflow
    }
    return res;
}
