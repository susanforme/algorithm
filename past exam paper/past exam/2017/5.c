#include <string.h>
#include <stdio.h>

int find_len_word(char *s1, char *s2)
{
  int s1_len = strlen(s1), s2_len = strlen(s2);
  int max_len_word = 0, position;
  for (position = 0; position < s1_len; position++)
  {
    if (s1[position] != ' ')
      max_len_word++;
    else
    {
      if (max_len_word > s2_len)
        return position - max_len_word;
      max_len_word = 0;
    }
  }
  return max_len_word > s2_len ? position - max_len_word : -1;
}

int main(void)
{
  char *s1 = "hello  world", *s2 = "word";
  int res = find_len_word(s1, s2);
  printf("res is %d", res);
  return 0;
}