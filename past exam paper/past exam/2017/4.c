#define COLUMN 5
#include <stdio.h>

void getValue(int A[][COLUMN], int row)
{
  int odd = 1;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      A[i][j] = odd;
      odd += 2;
      if (i >= j)
      {
        printf("当前是第%d行第%d列值为%d.\n", i + 1, j + 1, A[i][j]);
      }
    }
  }
  return;
}

int main(void)
{
  int A[5][COLUMN];
  getValue(A, 5);
  return 0;
}