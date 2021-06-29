#include <stdio.h>
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