// 题目链接 http://t.hk.uy/5W9
#include "stdio.h"
#define MAXSIZE 30
#define COLUMN 6
#define ROW 5

typedef struct Triple
{
  int i, j, v;
} Triple;
typedef struct TsMatrix
{
  Triple data[MAXSIZE];
  // 注意初始化
  int len;
} TsMatrix;

// 行优先存储表示
void transform_v1(int matrix[ROW][COLUMN], TsMatrix *m)
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      if (matrix[i][j])
      {
        Triple newTriple = {i, j, matrix[i][j]};
        m->data[m->len++] = newTriple;
      }
    }
  }
}

// 稀疏矩阵转为三元组存储后将其展示

int main(void)
{
  TsMatrix m;
  int matrix[ROW][COLUMN] = {
      {0, 0, 3, 0, 0, 0},
      {1, 0, 0, 0, 0, 6},
      {0, 0, 4, 0, 0, 0},
      {0, 2, 0, 0, 5, 0},
      {0, 0, 0, 0, 0, 0},
  };
  // 简要初始化
  m.len = 0;
  transform_v1(matrix, &m);
  return 0;
}