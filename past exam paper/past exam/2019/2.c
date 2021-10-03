// 鸡兔同笼
#include <stdio.h>
void getCount(void)
{
  for (int chicken = 0; chicken <= 35; chicken++)
    if (chicken * 2 + (35 - chicken) * 4 == 94)
      printf("有%d个兔子和%d只鸡", 35 - chicken, chicken);
}

int main(void)
{
  getCount();
  return 0;
}