// 进制转换
#define MAX_LEN 100
#include <stdbool.h>
#include <stdio.h>
typedef struct Stack
{
  int data[MAX_LEN];
  int len;
} Stack;

void Push(Stack *s, int x)
{
  s->data[s->len++] = x;
}

bool Pop(Stack *s, int *x)
{
  if (s->len == 0)
  {
    return false;
  }
  s->len--;
  *x = s->data[s->len];
  return true;
}

void transform(int x, Stack *s)
{
  int remind, y;
  while (x / 2)
  {
    remind = x % 2;
    Push(s, remind);
    x = x / 2;
  }
  Push(s, x);
  puts("转换后的二进制数为");
  while (Pop(s, &y))
  {
    printf("%d", y);
  }
}
int main(void)
{
  Stack s;
  s.len = 0;
  transform(10, &s);
  return 0;
}