#include <stdlib.h>
#define INFINITY 0x7fffffff
typedef int ElemType;
typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

int IsDescending(LinkList L)
{
  LNode *p = L;
  while (p != NULL)
  {
    if (p->next != NULL)
      if (p->next->data <= p->data)
        return 0;
    p = p->next;
  }
  return 1;
}

int main(void)
{
  LNode L = {1, NULL};
  LNode L1 = {2, NULL};
  LNode L2 = {3, NULL};
  LNode L3 = {4, NULL};
  L.next = &L1;
  L1.next = &L2;
  L2.next = &L3;
  int res = IsDescending(&L);
  return 0;
}