#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#define MAXSIZE 10
#define NOTATION 50

// 实现逻辑 中缀转后缀 左优先原则

/*
* 1. 从左到右扫描下一个元素,直到处理完所有元素
* 2. 若扫描到操作数则压入栈
* 3. 若扫描到运算符,则弹出两个栈顶元素,执行相应运算,运算结果压入栈顶
*/
bool is_operation(char s)
{
  return s == '+' || s == '-' || s == '*' || s == '/';
}

int reverse_polish(const char *notation)
{
  int len = strlen(notation);
  int stack[MAXSIZE], count;
  for (int i = 0; i < len; i++)
  {
    int s = notation[i];
    if (!is_operation(s))
    {
      stack[count++] = s;
    }
    else
    {
      if (s == '+')
      {
        count = count - 2;
        stack[count] = stack[count] + stack[count + 1];
      }
      if (s == '-')
      {
        count = count - 2;
        stack[count] = stack[count] - stack[count + 1];
      }
      if (s == '*')
      {
        count = count - 2;
        stack[count] = stack[count] * stack[count + 1];
      }
      if (s == '/')
      {
        count = count - 2;
        stack[count] = stack[count] / stack[count + 1];
      }
    }
  }
  return stack[0];
}

int main(void)
{
  char str[NOTATION] = "15711+-/3*211++-";
  int result = reverse_polish(str);
  return 0;
}