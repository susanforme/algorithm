#include <stdbool.h>

typedef int ElemType;

// 0位为哨兵
void insertNode(ElemType A[], int len)
{
  for (int i = 2; i <= len; i++)
  {
    if (A[i] < A[i - 1])
    {
      int j = i - 1;
      A[0] = A[i];
      // 到0位即停止
      while (A[j] > A[0])
      {
        A[j + 1] = A[j];
        j--;
      }
      A[j + 1] = A[0];
    }
  }
}

// 二分插入排序
void insertNode2(ElemType A[], int len)
{
  for (int i = 2; i <= len; i++)
  {
    if (A[i] < A[i - 1])
    {
      A[0] = A[i];
      int low = 1, high = i - 1, mid;
      while (low <= high)
      {
        mid = (low + high) / 2;
        if (A[mid] > A[0])
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      for (int k = i - 1; k >= high; k--)
      {
        A[k + 1] = A[k];
      }
      A[high + 1] = A[0];
    }
  }
}

int main(void)
{
  ElemType A[] = {0, 3, 2, 9, 7, 0};
  ElemType B[] = {0, 3, 2, 9, 7, 0};
  insertNode(A, 5);
  insertNode2(B, 5);
  return 0;
}