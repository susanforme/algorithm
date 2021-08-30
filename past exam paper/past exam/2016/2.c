// 水仙花数
#include <stdio.h>
#include <math.h>

void flower_num()
{
  for (int i = 100; i < 1000; i++)
  {
    int hundred = i / 100,
        ten = (i - hundred * 100) / 10,
        one = i - hundred * 100 - ten * 10;
    if (i == (int)(pow(hundred, 3) + pow(ten, 3) + pow(one, 3)))
    {
      printf("当前数字%d是水仙花数\n", i);
    }
  }
}

int main()
{
  flower_num();
}