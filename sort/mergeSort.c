#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;

void merge(ElemType A[], ElemType B[], int low, int mid, int high)
{
  int i = low, j = mid + 1, k = i;
  for (int k = low; k <= high; k++)
  {
    // 把A中所有元素保存到B中
    B[k] = A[k];
  }
  while (i <= mid && j <= high)
  {
    /* 比较B的左右两段元素
    * {38 47 59   12 50 60}
    */
    if (B[i] <= B[j])
    {
      // 将较小值复制到A中
      A[k] = B[i++];
    }
    else
    {
      A[k] = B[j++];
    }
    k++;
  }
  while (i <= mid)
  {
    // 若第一表未检测完复制
    A[k++] = B[i++];
  }
  while (j <= high)
  {
    // 若第二个表未检测完 复制
    A[k++] = B[j++];
  }
}
void mergeSort(ElemType A[], ElemType B[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(A, B, low, mid);
    mergeSort(A, B, mid + 1, high);
    merge(A, B, low, mid, high);
  }
}

int main(void)
{
  // 辅助数组B
  ElemType *B = (ElemType *)malloc(11 * sizeof(ElemType));
  ElemType A[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
  mergeSort(A, B, 0, 9);
  return 0;
}