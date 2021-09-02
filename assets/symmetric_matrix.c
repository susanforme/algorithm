// 对称矩阵的压缩存储
#define ROW 5
#define COLUMN 5
#define MAXSIZE 20
#include <stdio.h>

// 第i行，第j列,下三角
int getPosition(int i, int j)
{
  int temp = i;
  if (i < j)
  {
    i = j;
    j = temp;
  }
  return i * (i - 1) / 2 + j - 1;
}

// 上三角
int getP2(int i, int j)
{
  int temp = i;
  if (i > j)
  {
    i = j;
    j = temp;
  }
  return (2 * ROW - i + 2) * (i - 1) / 2 + j - i + 1;
}

void compress(int data[][COLUMN], int copy[])
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      int position = getP2(i + 1, j + 1);
      copy[position] = data[i][j];
    }
  }
}

int main(void)
{
  int data[ROW][COLUMN] = {
      {1, 2, 3, 4, 5},
      {2, 6, 8, 6, 3},
      {3, 8, 7, 5, 11},
      {4, 6, 5, 9, 12},
      {5, 3, 11, 12, 10}};
  int copy[MAXSIZE];
  compress(data, copy);
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      printf("%d,", copy[getP2(i + 1, j + 1)]);
    }
    puts("");
  }

  return 0;
}