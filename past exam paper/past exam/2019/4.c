#include <stdio.h>
int index(int *A, int x, int len)
{
  int mid, i = 0, j = len - 1;
  while (i <= j)
  {
    mid = (i + j) / 2;
    if (A[mid] == x)
      return mid;
    else if (A[mid] > x)
      j = mid - 1;
    else
      i = mid + 1;
  }
  puts("查找失败");
  return -1;
}

int main(void)
{
  int A[] = {1, 3, 5, 7, 9, 10};
  int i = index(A, 11, 6);
  return 0;
}