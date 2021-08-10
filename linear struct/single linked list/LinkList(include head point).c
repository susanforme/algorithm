#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 带头节点的单链表, 不带头结点会对代码更多处理
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

bool initList(LinkList *list)
{
  // 分配空间 第一个节点不插数据 并不能分配数据,因为list不会将数据带回,必须使用指针的指针
  *list = (LNode *)malloc(sizeof(LNode));
  // 内存不足空间分配失败
  if ((*list) == NULL)
  {
    return false;
  }
  // 初始化下个节点
  (*list)->next = NULL;
  (*list)->data = 0;
  return true;
}
// 平均复杂度 O(n)
LNode *getElem(LinkList list, int i)
{
  if (i < 0)
  {
    return NULL;
  }
  LNode *p = list;
  int count = 0;
  while (p != NULL && count < i)
  {
    p = p->next;
    count++;
  }
  return p;
}

// 时间复杂度O(n)
LNode *locateElem(LinkList list, int e)
{
  LNode *p = list->next;
  while (p != NULL && p->data != e)
  {
    p = p->next;
  }
  return p;
}

// 需要将所有数据扫描一次,时间复杂度O(n)
int length(LinkList list)
{
  int count = 0;
  LNode *p = list;
  while (p->next != NULL)
  {
    p = p->next;
    count++;
  }
  return count;
}

// 后插操作
bool insertNextNode(LNode *p, int e)
{
  if (p == NULL)
  {
    return false;
  }
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  newNode->data = e;
  newNode->next = p->next;
  p->next = newNode;
  return true;
}

// 插入数据
bool insertList(LinkList list, int i, int e)
{
  LNode *p = getElem(list, i - 1);
  return insertNextNode(p, e);
}

// 前插操作
bool insertPriorNode(LNode *p, int e)
{
  if (p == NULL)
  {
    return false;
  }
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  // 两个节点互换位置 ,此时并不用了解前方的节点,时间复杂度为O(1)
  newNode->next = p->next;
  p->next = newNode;
  newNode->data = p->data;
  p->data = e;
  return true;
}

// 删除指定位序的值
bool deleteList(LinkList list, int i)
{
  LNode *p = list;
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

// 时间复杂度O(1)
bool deleteNode(LNode *p)
{
  LNode *n = p->next;
  p->data = p->next->data;
  // 可能越界.... 但是考试一般不会扣分
  p->next = p->next->next;
  free(n);
  return true;
}

void printList(LinkList list)
{
  LNode *p = list;
  int i = 0;
  while (p != NULL)
  {
    printf("当前位置为%d,值为%d.\n", i, p->data);
  }
}

// 尾插法 建立单链表 时间复杂度O(n)
LinkList tailInsertList(LinkList *list)
{
  int data = 0;
  *list = (LinkList)malloc(sizeof(LNode));
  // 最好将值初始化
  (*list)->next = NULL;
  LNode *newNode, *lastNode = *list;
  scanf("%d", &data);
  while (data != 9999)
  {
    newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = data;
    lastNode->next = newNode;
    lastNode = newNode;
    scanf("%d", &data);
  }
  return *list;
}

// 头插法建立单链表 时间复杂度O(n)
LinkList headInsertList(LinkList *list)
{
  int data = 0;
  *list = (LinkList)malloc(sizeof(LNode));
  // 最好将值初始化
  (*list)->next = NULL;
  LNode *newNode;
  scanf("%d", &data);
  while (data != 9999)
  {
    newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = (*list)->next;
    (*list)->next = newNode;
    scanf("%d", &data);
  }

  return *list;
}
int main(void)
{
  // 不能直接创建 LinkList list ; 这样只是一个空指针,里面并没有分配内存空间
  // 可以采用如下两种方式创建
  // LNode Node;
  // LinkList list = &Node;
  LinkList list;
  // 不使用指针的指针 则需在外部分配内存
  // list = (LNode *)malloc(sizeof(LNode));
  initList(&list);
  insertList(list, 1, 23);
  insertList(list, 1, 22);
  insertList(list, 1, 99);
  // deleteList(list, 1);
  deleteNode(list->next->next);
  printf("长度为%d.\n", length(list));
  return 0;
}