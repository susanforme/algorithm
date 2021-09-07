int partion(int A[], int low, int high)
{
  int pivot = A[low];
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
  A[low] = pivot;
  return low;
}

void quickSort(int A[], int low, int high)
{
  if (low < high)
  {
    int pivotN = partion(A, low, high);
    quickSort(A, low, pivotN - 1);
    quickSort(A, pivotN + 1, high);
  }
}

int main(void)
{
  int A[] = {38, 76, 23, 54, 80, 15, 99, 10, 100, 11, 50};
  quickSort(A, 0, 10);
  return 0;
}