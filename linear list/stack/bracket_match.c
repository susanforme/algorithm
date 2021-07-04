// 括号匹配
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#define MAXSIZE 80
#define RUN_TIMES 10000000
// 自己写的粗糙算法,在只有右括号场景会出现错误
bool bracket_match(const char *str)
{
  int len = strlen(str), count = 0;
  char stack[MAXSIZE];
  for (int i = 0; i < len; i++)
  {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{')
    {
      stack[count++] = str[i];
    }
    else if (str[i] == ')' && stack[count - 1] == '(')
    {

      count--;
    }
    else if (str[i] == ']' && stack[count - 1] == '[')
    {
      count--;
    }
    else if (str[i] == '}' && stack[count - 1] == '{')
    {
      count--;
    }
  }
  return count == 0;
}

// 自己改进后的算法,改进后在程序运行正常速度并无改善,甚至运行速度更缓慢,但是在判错速度有明显改善,以下在空栈时有越界风险
bool bracket_match_ver1(const char *str)
{
  int len = strlen(str), count = 0;
  char stack[MAXSIZE];
  for (int i = 0; i < len; i++)
  {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{')
    {
      stack[count++] = str[i];
    }
    else if (str[i] == ')')
    {
      if (stack[count - 1] == '(')
      {
        count--;
      }
      else
      {
        return false;
      }
    }
    else if (str[i] == ']')
    {
      if (stack[count - 1] == '[')
      {
        count--;
      }
      else
      {
        return false;
      }
    }
    else if (str[i] == '}')
    {
      if (stack[count - 1] == '{')
      {
        count--;
      }
      else
      {
        return false;
      }
    }
  }
  return count == 0;
}

// 老师设计的
bool bracket_match_answer(const char *str)
{
}
int main(void)
{
  char str[MAXSIZE] = ")}}]]]}))))]]]]}] (3+5)/2;int j ={} ";
  bool is_match, is_match_ver1;
  clock_t start, finish, time, time_ver1;
  start = clock();
  for (int i = 0; i < RUN_TIMES; i++)
  {
    is_match = bracket_match(str);
  }
  finish = clock();
  time = finish - start;
  start = clock();
  for (int i = 0; i < RUN_TIMES; i++)
  {
    is_match_ver1 = bracket_match_ver1(str);
  }
  finish = clock();
  time_ver1 = finish - start;
  return 0;
}