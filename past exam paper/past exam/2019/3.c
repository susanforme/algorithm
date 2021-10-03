// 3矩阵相乘
#include <stdio.h>
#define COLUMN 4

int multiply(int A[][COLUMN], int B[][COLUMN], int i, int len)
{
  int res = 0;
  for (int j = 0; j < len; j++)
    res += A[i][j] * B[j][i];
  return res;
}

void multiplyMatrix(int A[][COLUMN], int B[][COLUMN], int RES[][COLUMN], int len)
{
  for (int i = 0; i < len; i++)
    for (int j = 0; j < COLUMN; j++)
      RES[i][j] = multiply(A, B, i, len);
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
  int len = 4, A[len][COLUMN];
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < COLUMN; j++)
      A[i][j] = 1;
  }
  printRes(A, A, A, len);
  return 0;
}