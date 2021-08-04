
typedef int ElemType;
int partition(ElemType A[], int low, int high)
{
  ElemType pivot = A[low];
  while (low < high)
  {
    while (low < high && A[high] >= pivot)
    {
      high--;
    }
    // 比基准小移动到左边
    A[low] = A[high];
    while (low < high && A[low] <= pivot)
    {
      low++;
    }
    // 比基准大的移动到右边
    A[high] = A[low];
  }
  // 基准元素放到最终位置
  A[low] = pivot;
  // 返回存放基准的位置
  return low;
}
void quickSort(ElemType A[], int low, int high)
{
  if (low < high)
  {
    int pivotPos = partition(A, low, high);
    // 对左子表进行排序
    quickSort(A, low, pivotPos - 1);
    // 对右子表进行排序
    quickSort(A, pivotPos + 1, high);
  }
}

int main(void)
{
  ElemType A[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
  quickSort(A, 0, 9);
  return 0;
}
