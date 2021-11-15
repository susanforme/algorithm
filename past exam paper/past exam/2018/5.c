#include <stdio.h>
#include <stdbool.h>
#define MAXNUM 100

// 升序排列数组
bool insert(int *A, int x, int len)
{
  int i = 0, j = len - 1, mid;
  while (i <= j)
  {
    mid = (i + j) / 2;
    if (A[mid] < x)
      i = mid + 1;
    else if (A[mid] > x)
      j = mid - 1;
    else
      return false;
  }
  if (i == len)
    A[i] = x;
  else
  {
    int k = len;
    while (k >= i)
    {
      A[k] = A[k - 1];
      k--;
    }
    A[i] = x;
  }
  return true;
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
  while (scanf("%d", &A[len]))
    len++;
  insert(A, 23, len);
  len++;
  printData(A, len);
  return 0;
}