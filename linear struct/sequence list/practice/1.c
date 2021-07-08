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

int deleteMin(SqList *list)
{
  if (list->length == 0)
  {
    puts("顺序表为空!");
    return 0;
  }
  int min = list->data[0], index = 1;
  for (int i = 1; i < list->length; i++)
  {
    int v = list->data[i];
    if (min > v)
    {
      min = v;
      index = i + 1;
    }
  }
  list->data[index - 1] = list->data[list->length - 1];
  list->length--;
  return min;
}
int main(void)
{
  SqList list;
  initList(&list);
  insertList(&list, 1, 9);
  insertList(&list, 2, 100);
  insertList(&list, 3, 32);
  deleteMin(&list);
  printList(list);
  return 0;
}