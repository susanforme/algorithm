#include <string.h>
typedef int position;
#include <stdio.h>
position cmpsubstr(char s1[], char s2[])
{
  int s1_len = strlen(s1), s2_len = strlen(s2);
  int i = 0, j = 0;
  while (i < s1_len && j < s2_len)
  {
    if (s1[i] != s2[j])
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
  if (j != s2_len)
  {
    return -1;
  }
  return i - j;
}

int main(void)
{
  char s1[] = "were1234", s2[] = "123";
  position p = cmpsubstr(s1, s2);
  printf("%d", p);
  return 0;
}