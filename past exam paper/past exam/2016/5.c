#include <stdio.h>
// 100元出现两次
int f(void)
{
  int res = 0;
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= (100 - i) / 2; j++)
      for (int z = 0; z <= (100 - i - 2 * j) / 5; z++)
        if (i + j * 2 + z * 5 == 100)
          res++;
  return res;
}
int k(void)
{
  int res = 0;
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 50; j++)
      for (int z = 0; z <= 20; z++)
        if (i + j * 2 + z * 5 == 100)
          res++;
  return res;
}

int main(void)
{
  int res = f();
  int res2 = k();
  printf("res1 %d, res2 %d .", res, res2);
  return 0;
}