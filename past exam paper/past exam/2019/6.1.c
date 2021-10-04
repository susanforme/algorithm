#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 0x7fffffff

typedef int ElemType;
typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

bool initList(LinkList *list)
{
  // 分配空间 第一个节点不插数据 并不能分配数据,因为list不会将数据带回,必须使用指针的指针
  *list = (LNode *)malloc(sizeof(LNode));
  // 内存不足空间分配失败
  if (list == NULL)
  {
    return false;
  }
  // 初始化下个节点
  (*list)->next = NULL;
  (*list)->data = 0;
  return true;
}
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

void DeleteX(LinkList l, ElemType x, int *count)
{
  LNode *p = l->next, *last = l;
  int c;
  while (p != NULL)
  {
    if (p->data == x)
    {
      c++;
      last->next = p->next;
    }
    else
      last = p;
    p = p->next;
  }
  *count = c;
}

int main(void)
{
  LinkList l;
  int count;
  initList(&l);
  insertList(l, 1, 1);
  insertList(l, 1, 2);
  insertList(l, 1, 3);
  insertList(l, 1, 3);
  insertList(l, 1, 3);
  insertList(l, 1, 1);
  DeleteX(l, 3, &count);
  return 0;
}