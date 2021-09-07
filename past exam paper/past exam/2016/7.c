// 单链表
#include <stdlib.h>
#define INFINITY 0x7fffffff
typedef int ElemType;
typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

void abc(LinkList L)
{
  LNode *p = NULL;
  LNode *q = L->next;
  while (q)
  {
    LNode *r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
  L->next = p;
}

int main(void)
{
  LNode L = {INFINITY, NULL};
  LNode L1 = {2, NULL};
  LNode L2 = {3, NULL};
  LNode L3 = {4, NULL};
  L.next = &L1;
  L1.next = &L2;
  L2.next = &L3;
  abc(&L);
  return 0;
}