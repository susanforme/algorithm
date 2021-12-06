#include <stdlib.h>
#include <stdbool.h>
typedef struct ListNode
{
  int data;
  struct ListNode *next;
} ListNode, *LinkList;
void func(LinkList L)
{
  int count = 0, n = 0;
  ListNode *p = L;
  while (p->next != NULL)
  {
    p = p->next;
    count++;
  }
  p = L;
  while (n < count)
  {
    ListNode *m = p->next, *q = p->next;
    while (m->next != NULL)
      m = m->next;
    q->next = NULL;
    m->next = q;
    p->next = p->next->next;
    n += 2;
    p = p->next;
  }
}
