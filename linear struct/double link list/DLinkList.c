#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 带头节点的单链表, 不带头结点会对代码更多处理
typedef struct DNode
{
  int data;
  struct DNode *next, *prior;
} DNode, *DLinkList;

bool initList(DLinkList *list)
{
  // 分配空间 第一个节点不插数据 并不能分配数据,因为list不会将数据带回,必须使用指针的指针
  *list = (DNode *)malloc(sizeof(DNode));
  // 内存不足空间分配失败
  if ((*list) == NULL)
  {
    return false;
  }
  // 初始化下个节点
  (*list)->next = NULL;
  (*list)->prior = NULL;
  (*list)->data = 0;
  return true;
}

// 平均复杂度 O(n)
DNode *getElem(DLinkList list, int i)
{
  if (i < 0)
  {
    return NULL;
  }
  DNode *p = list;
  int count = 0;
  while (p != NULL && count < i)
  {
    p = p->next;
    count++;
  }
  return p;
}

// 时间复杂度O(n)
DNode *locateElem(DLinkList list, int e)
{
  DNode *p = list->next;
  while (p != NULL && p->data != e)
  {
    p = p->next;
  }
  return p;
}

// 需要将所有数据扫描一次,时间复杂度O(n)
int length(DLinkList list)
{
  int count = 0;
  DNode *p = list;
  while (p->next != NULL)
  {
    p = p->next;
    count++;
  }
  return count;
}

// 后插操作
bool insertNextDNode(DNode *p, int e)
{
  if (p == NULL)
  {
    return false;
  }
  DNode *newNode = (DNode *)malloc(sizeof(DNode));
  newNode->data = e;
  newNode->next = p->next;
  newNode->prior = p;
  if (p->next != NULL)
  {
    //  修改后项数据元素的prior指针
    p->next->prior = newNode;
  }
  p->next = newNode;
  return true;
}

// 插入数据
bool insertList(DLinkList list, int i, int e)
{
  DNode *p = getElem(list, i - 1);
  return insertNextDNode(p, e);
}

// 前插操作
bool insertPriorNode(DNode *p, int e)
{
  if (p == NULL)
  {
    return false;
  }
  DNode *newNode = (DNode *)malloc(sizeof(DNode));
  // 两个节点互换位置 ,此时并不用了解前方的节点,时间复杂度为O(1)
  newNode->next = p->next;
  p->next = newNode;
  newNode->data = p->data;
  p->data = e;
  return true;
}

// 删除指定位序的值
bool deleteList(DLinkList list, int i)
{
  DNode *p = list;
  int count = 0;
  if (i < 1)
  {
    return false;
  }
  while (p != NULL && count < i - 1)
  {
    p = p->next;
    count++;
  }
  if (p == NULL)
  {
    return false;
  }
  p->next = p->next->next;
  return true;
}

// 删除p节点的后继节点
bool deleteNextDNode(DNode *p)
{
  if (p == NULL || p->next == NULL)
  {
    return false;
  }
  DNode *q = p->next;
  if (q->next != NULL)
  {
    q->next->prior = p;
  }
  p->next = q->next;
  free(q);
  return true;
}

// 删除链表
void destoryList(DLinkList *list)
{
  while ((*list)->next != NULL)
  {
    deleteNextDNode((*list));
  }
  free((*list));
  (*list) = NULL;
}

void printList(DLinkList list)
{
  DNode *p = list;
  int i = 0;
  while (p != NULL)
  {
    printf("当前位置为%d,值为%d.\n", i, p->data);
    p = p->next;
  }
}

// 尾插法 建立单链表 时间复杂度O(n)
DLinkList tailInsertList(DLinkList *list)
{
  int data = 0;
  *list = (DLinkList)malloc(sizeof(DNode));
  // 最好将值初始化
  (*list)->next = NULL;
  DNode *newNode, *lastNode = *list;
  scanf("%d", &data);
  while (data != 9999)
  {
    newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    lastNode->next = newNode;
    lastNode = newNode;
    scanf("%d", &data);
  }
  return *list;
}

// 头插法建立单链表 时间复杂度O(n)
DLinkList headInsertList(DLinkList *list)
{
  int data = 0;
  *list = (DLinkList)malloc(sizeof(DNode));
  // 最好将值初始化
  (*list)->next = NULL;
  DNode *newNode;
  scanf("%d", &data);
  while (data != 9999)
  {
    newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = (*list)->next;
    (*list)->next = newNode;
    scanf("%d", &data);
  }

  return *list;
}
int main(void)
{
  DLinkList list;
  initList(&list);
  insertList(list, 1, 23);
  insertList(list, 1, 22);
  insertList(list, 1, 99);
  // deleteList(list, 1);
  deleteNextDNode(list->next->next);
  printf("长度为%d.\n", length(list));
  destoryList(&list);
  return 0;
}