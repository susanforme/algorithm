#include <stdbool.h>
#include <time.h>

typedef int ElemType;
void bubbleSort(ElemType A[], int len)
{
  for (int j = 0; j < len; j++)
  {
    bool flag = false;
    for (int i = 1; i < len - j; i++)
    {
      if (A[i - 1] > A[i])
      {
        flag = true;
        int temp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = temp;
      }
    }
    // 本轮未交换已然有序
    if (!flag)
    {
      return;
    }
  }
}
void test(ElemType A[])
{
  ElemType B[9];
  for (int i = 0; i < 9; i++)
  {
    B[i] = A[i];
  }

  bubbleSort(B, 9);
}

int main(void)
{
  ElemType A[] = {10, 3, 2, 9, 7, 0, 5, 6, 8};
  int start = clock(), end;
  for (int i = 0; i < 1000000; i++)
  {
    test(A);
  }
  end = clock();
  return 0;
}