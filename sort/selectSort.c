// 简单选择排序
typedef int ElemType;

void swap(ElemType *a, ElemType *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectSort(ElemType A[], int len)
{
  for (int i = 0; i < len; i++)
  {
    int min = i;
    for (int j = i + 1; j < len; j++)
    {
      if (A[j] < A[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      swap(&A[i], &A[min]);
    }
  }
}

int main(void)
{
  ElemType A[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
  selectSort(A, 10);
  return 0;
}