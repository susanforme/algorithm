#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 不带头结点
typedef struct LinkNode
{
  int data;
  struct LinkNode *next;
} LinkNode, *LinkStack;

// 初始化栈
void init_stack(LinkStack *l, int x)
{
  *l = (LinkNode *)malloc(sizeof(LinkNode));
  // 默认值
  (*l)->data = x;
  (*l)->next = NULL;
}

// 插入栈顶
bool push(LinkStack *l, int x)
{
  LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
  if (newNode == NULL)
  {
    return false;
  }
  // 空栈操作
  if ((*l)->data == 0 && (*l)->next == NULL)
  {
    (*l)->data == x;
  }
  else
  {
    newNode->next = (*l);
    newNode->data = x;
    *l = newNode;
  }

  return true;
}

// 出栈
bool pop(LinkStack *l, int *x)
{
  LinkNode *last_list = *l;
  *x = (*l)->data;
  *l = (*l)->next;
  free(last_list);
  return true;
}

int main(void)
{
  LinkStack linkStack;
  int pop_value;
  init_stack(&linkStack, 12);
  push(&linkStack, 32);
  push(&linkStack, 19);
  push(&linkStack, 11);
  pop(&linkStack, &pop_value);
  return 0;
}