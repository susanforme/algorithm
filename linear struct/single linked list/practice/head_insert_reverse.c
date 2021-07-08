// 头插法逆置链表
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

void head_insert_reverse(LinkList list, LinkList *newList)
{
  LNode *p = list->next;
  while (p != NULL)
  {
    LNode *newP = (LNode *)malloc(sizeof(LNode));
    newP->data = p->data;
    newP->next = (*newList)->next;
    (*newList)->next = newP;
    p = p->next;
  }
}

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

int main(void)
{
  LinkList list;
  LinkList newList;
  initList(&list);
  initList(&newList);
  insertList(list, 1, 23);
  insertList(list, 1, 22);
  insertList(list, 1, 99);
  head_insert_reverse(list, &newList);
  return 0;
}