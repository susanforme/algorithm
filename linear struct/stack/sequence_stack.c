#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
  int data[MAXSIZE];
  // 栈顶位置,数组0位
  int top;
} SqStack;

void initStack(SqStack *s)
{
  s->top = -1;
}

// 进栈操作
bool push(SqStack *s, int x)
{
  if (s->top == MAXSIZE - 1)
  {
    return false;
  }
  s->data[++s->top] = x;
  return true;
}
// 出栈操作
bool pop_stack(SqStack *s, int *x)
{
  if (s->top == -1)
  {
    return false;
  }
  *x = s->data[s->top--];
  return true;
}

int main(void)
{

  return 0;
}