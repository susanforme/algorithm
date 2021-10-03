// 3矩阵相乘
#include <stdio.h>
#define COLUMN 3

void multiplyMatrix(int A[][COLUMN], int B[][COLUMN], int RES[][COLUMN], int len)
{
  for (int i = 0; i < len; i++)
    for (int j = 0; j < COLUMN; j++)
    {
      int res = 0;
      for (int k = 0; k < len; k++)
      {
        res += A[i][k] * B[k][j];
      }
      RES[i][j] = res;
    }
}

void printRes(int A[][COLUMN], int B[][COLUMN], int C[][COLUMN], int len)
{
  int RES[len][COLUMN], RES2[len][COLUMN];
  multiplyMatrix(A, B, RES, len);
  multiplyMatrix(RES, C, RES2, len);
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < COLUMN; j++)
      printf("%d ", RES2[i][j]);
    puts(".");
  }
}

int main(void)
{
  int len = 3, A[len][COLUMN], t = 1;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < COLUMN; j++)
      A[i][j] = t++;
  }
  printRes(A, A, A, len);
  return 0;
}