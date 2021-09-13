// 计算前20项 斐波那契
#include <stdio.h>
int fib(int n)
{
  return n <= 1 ? 1 : fib(n - 1) + fib(n - 2);
}

float mole(int n)
{
  return fib(n + 1) / fib(n);
}

int main(void)
{
  float res = 0;
  for (int i = 1; i <= 20; i++)
  {
    res += mole(i);
  }
  printf("结果是%f。", res);
  return 0;
}