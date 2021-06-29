#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10

typedef struct
{
  int *data;
  int length;
  int MaxSize;
} SqList;

void initList(SqList *list)
{
  // 动态分配空间 , 强制类型转换为int
  list->data = (int *)malloc(INITSIZE * sizeof(int));
  list->length = 0;
  list->MaxSize = INITSIZE;
}
// 增加动态数组的长度
void increaseSize(SqList *list, int len)
{
  int *p = list->data;
  list->data = (int *)malloc((list->MaxSize + len) * sizeof(int));
  // 时间开销大
  for (int i = 0; i < list->length; i++)
  {
    list->data[i] = p[i];
  }
  list->MaxSize += len;
  // 释放原来的内存空间
  free(p);
}
void printList(SqList list)
{
  for (int i = 0; i < list.length; i++)
  {
    printf("list->data[%d] = %d.\n", i, list.data[i]);
  }
}
int main(void)
{
  SqList list;
  initList(&list);
  printList(list);
  return 0;
}