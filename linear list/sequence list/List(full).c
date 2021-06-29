// 完整的一个顺序表
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct
{
  int data[MAXSIZE];
  int length;
} SqList;

void initList(SqList *list)
{
  // 最好在这里对数据进行初始化
  for (int i = 0; i < MAXSIZE; i++)
  {
    list->data[i] = 0;
  }
  list->length = 0;
}

void printList(SqList list)
{
  if (list.length == 0)
  {
    puts("链表为空哦");
  }
  for (int i = 0; i < list.length; i++)
  {
    printf("list->data[%d] = %d.\n", i, list.data[i]);
  }
}

// 此处的i是位置,而不是索引
bool insertList(SqList *list, int i, int e)
{
  if (i > list->length + 1 || i < 1)
  {
    return false;
  }
  if (list->length == MAXSIZE)
  {
    return false;
  }
  for (int k = list->length; k >= i; k--)
  {
    list->data[k] = list->data[k - 1];
  }
  list->data[i - 1] = e;
  list->length++;
  return true;
}

// 通过位置 删除链表中一个值,最好情况时间复杂度O(1) 平均情况O(1)
bool deleteList(SqList *list, int i)
{
  if (i > list->length + 1 || i < 1)
  {
    return false;
  }
  for (int k = i - 1; k < list->length; k++)
  {
    // 处理越界
    if (i == list->length)
    {
      list->data[k] = 0;
    }
    else
    {
      list->data[k] = list->data[k + 1];
    }
  }
  list->length--;
  return true;
}
// 按位置查找值  时间复杂度 O(1)
int getElem(SqList list, int i)
{
  return list.data[i - 1];
}
// 根据值查找,并返回其位序
int locateElem(SqList list, int e)
{
  for (int i = 0; i < list.length; i++)
  {
    if (list.data[i] == e)
    {
      return i + 1;
    }
  }
  return 0;
}
int main(void)
{
  SqList list;
  initList(&list);
  insertList(&list, 1, 99);
  insertList(&list, 2, 1);
  insertList(&list, 3, 3);
  printList(list);
  deleteList(&list, 2);
  printList(list);
  printf("按值查找的返回的位序为%d.\n", locateElem(list, 3));
  return 0;
}