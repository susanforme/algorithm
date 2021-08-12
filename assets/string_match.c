// 串的简单模式匹配
#define MAXSIZE 50
#include <string.h>

typedef struct String
{
  char s[MAXSIZE];
  int len;
} String;

int index(String s, String t)
{
  int i = 0, j = 0;
  while (i < s.len && j < t.len)
  {
    if (s.s[i] != t.s[j])
    {
      i = i - j + 1;
      j = 0;
    }
    else
    {
      i++;
      j++;
    }
  }
  if (j == t.len)
  {
    return i - t.len;
  }
  return -1;
}
int index_t(char s[MAXSIZE], char t[MAXSIZE])
{
  int i = 0, j = 0;
  while (i < strlen(s) && j < strlen(t))
  {
    if (s[i] != t[j])
    {
      i = i - j + 1;
      j = 0;
    }
    else
    {
      i++;
      j++;
    }
  }
  if (j == strlen(t))
  {
    return i - j;
  }
  return -1;
}

int main(void)
{
  String a = {"whoareyou?", 10};
  String b = {"are", 3};
  int i = index(a, b);
  int i2 = index_t(a.s, b.s);
  return 0;
}