#include <stdio.h>
#define MAXNUM 100

void getData(int *A, int *len)
{
  while (scanf("%d", &A[*len]))
    (*len)++;
}
// 升序排列数组
int insert(int *A, int x, int *len)
{
  int i = 0;
  if (*len == 0)
  {
    A[0] = x;
    (*len)++;
    return 0;
  }
  while (i < *len && A[i] <= x)
    i++;
  for (int j = *len; j >= i + 1; j--)
  {
    A[j] = A[j - 1];
  }
  A[i] = x;
  (*len)++;
  return i;
}

void printData(int *A, int len)
{
  puts("数组为");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", A[i]);
  }
}
int main(void)
{
  int A[MAXNUM], len = 0;
  getData(A, &len);
  insert(A, 23, &len);
  printData(A, len);
  return 0;
}