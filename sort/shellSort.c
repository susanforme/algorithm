typedef int ElemType;

//使用0位
void shellSort(ElemType A[], int len)
{
  int step = len / 2;
  while (step >= 1)
  {
    for (int i = step; i < len; i++)
    {
      if (A[i] < A[i - step])
      {
        int temp = A[i];
        int j = i - step;
        while (A[j] > temp && j >= 0)
        {
          A[j + step] = A[j];
          j -= step;
        }
        A[j + step] = temp;
      }
    }
    step /= 2;
  }
}

int main(void)
{
  ElemType A[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
  shellSort(A, 10);
  return 0;
}