#define INFINITY 0x7fffffff
typedef int ElemType;

// 注意0位
void headAdjust(ElemType A[], int k, int len)
{
  // 存储根节点
  A[0] = A[k];
  // 沿k较大的子节点向下筛选 下沉操作
  for (int i = 2 * k; i <= len; i *= 2)
  {
    // 取更大的子节点,
    if (i < len && A[i] < A[i + 1])
    {
      i++;
    }
    // 满足大根堆
    if (A[0] >= A[i])
    {
      break;
    }
    // 继续检测较小值下沉后是否构成堆
    else
    {
      // 将值上移
      A[k] = A[i];
      // 检查子树的子树
      k = i;
    }
  }
  A[k] = A[0];
}

void buildMaxHeap(ElemType A[], int len)
{
  // 从下到上建立大顶堆
  for (int i = len / 2; i > 0; i--)
  {
    headAdjust(A, i, len);
  }
  A[0] = INFINITY;
}

void swap(ElemType *a, ElemType *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void heapSort(ElemType A[], int len)
{
  buildMaxHeap(A, len);
  for (int i = len; i > 1; i--)
  {
    // 堆顶元素最大，提取到最后
    swap(&A[i], &A[1]);
    // 将剩下i-1元素整理为堆
    headAdjust(A, 1, i - 1);
  }
}

int main(void)
{
  ElemType A[] = {0, 53, 17, 78, 9, 45, 65, 87, 32};
  heapSort(A, 8);
  return 0;
}