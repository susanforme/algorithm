#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
  int data;
  struct node *next;
} ListNode, *LinkList;
void insertlist(LinkList l, int x)
{
  ListNode *z = l;
  while (z->next != NULL)
  {
    z = z->next;
  }
  ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
  newNode->next = NULL;
  newNode->data = x;
  z->next = newNode;
}
void init(LinkList *l)
{
  *l = (LinkList)malloc(sizeof(ListNode));
  (*l)->next = NULL;
  (*l)->data = 0x7fffffff;
}
void printList(LinkList l)
{
  ListNode *z = l;
  int count = 0;
  while (z != NULL)
  {
    printf("当前是第%d个值为%d。\n", count, z->data);
    count++;
    z = z->next;
  }
}
void exchange(LinkList *l, int index)
{
  if (index % 2)
  {
    ListNode *p, *q;
    q = (*l)->next;
    p = q;
    while (p->next != NULL)
      p = p->next;
    (*l)->next = q->next;
    p->next = q;
    q->next = NULL;
  }
  else
    *l = (*l)->next;
}
void func(LinkList l)
{
  ListNode *z = l->next;
  int count = 0, res = 0;
  while (z != NULL)
  {
    count++;
    z = z->next;
  }
  z = l;
  while (res <= count)
  {
    if (res)
      exchange(&z, res);
    res++;
  }
}

int main(void)
{
  LinkList l;
  init(&l);
  insertlist(l, 1);
  insertlist(l, 2);
  insertlist(l, 3);
  insertlist(l, 4);
  insertlist(l, 5);
  insertlist(l, 6);
  insertlist(l, 7);
  insertlist(l, 8);
  insertlist(l, 9);
  func(l);
  printList(l);
  return 0;
}