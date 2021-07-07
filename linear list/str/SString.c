// 串实现
#define MAXLEN 255
#include <string.h>
#include <stdbool.h>

typedef struct
{
  // 0位废弃不使用
  char ch[MAXLEN];
  int len;
} SString;

int StrLength(SString S)
{
  return S.len;
}

void StrAssign(SString *T, char S[])
{
  for (int i = 0; i < strlen(S); i++)
  {
    T->ch[i + 1] = S[i];
    T->len++;
  }
}

void StrCopy(SString *T, SString S)
{
  for (int i = 1; i <= StrLength(S); i++)
  {
    T->ch[i] = S.ch[i];
    T->len++;
  }
}

bool StrEmpty(SString S)
{
  return StrLength(S) == 0;
}

int StrCompare(SString S, SString T)
{
  int len = StrLength(S) < StrLength(T) ? StrLength(S) : StrLength(T);
  for (int i = 1; i <= len; i++)
  {
    if (S.ch[i] != T.ch[i])
    {
      return (int)(S.ch[i] - T.ch[i]);
    }
  }
  // 都相同,返回长度更长的
  return StrLength(S) - StrLength(T);
}

bool SubString(SString *Sub, SString S, int pos, int len)
{
  int count = 0;
  if (pos + len > StrLength(S))
  {
    return false;
  }
  while (count < len)
  {
    // ++放右边就会先加了...
    Sub->ch[count++ + 1] = S.ch[pos + count];
  }
  Sub->len = count;
  return true;
}

void Concat(SString *T, SString S1, SString S2)
{
  int s1_len = StrLength(S1), s2_len = StrLength(S2);
  for (int i = 1; i <= s1_len; i++)
  {
    T->ch[i] = S1.ch[i];
    T->len++;
  }
  for (int j = 1; j <= s2_len; j++)
  {
    T->ch[j + s1_len] = S2.ch[j];
    T->len++;
  }
}

// 暴力破解法
// 若主串S中存在与串T相同的字串,则返回他在主串中第一次出现的位置.否则返回0
int Index(SString S, SString T)
{
  for (int i = 1; i <= StrLength(S) - StrLength(T) + 1; i++)
  {
    SString new_sub;
    if (!SubString(&new_sub, S, i, StrLength(T)))
    {
      return 0;
    };
    if (!StrCompare(new_sub, T))
    {
      return i;
    }
  }
  return 0;
}

// 朴素模式匹配算法,此处不利用任何串的基本操作
int Index_ver1(SString S, SString T)
{
  // 最坏时间复杂度 O(nm) 每个子串都要对比m个字符,共n-m+1个子串
  // 最好时间复杂度O(n) 每个子串的第一个字符就匹配失败,共n-m+1个子串 复杂度O(n-m+1)
  int i = 1, j = 1;
  while (i <= S.len - T.len + 1 && j < T.len)
  {
    if (S.ch[i] == T.ch[j])
    {
      i++;
      j++;
    }
    else
    {
      // 匹配错误,恢复指针,n-m+1 同时指向下一个字串,再+1
      i = i - j + 2;
      j = 1;
    }
  }
  if (j == T.len)
  {
    return i - T.len + 1;
  }
  return 0;
}

// 最坏时间复杂度O(n+m) 模式匹配O(n) 求出next数组 O(m)
int Index_KMP(SString S, SString T, int next[])
{
  int i = 1, j = 1;
  while (i <= S.len - T.len + 1 && j < T.len)
  {
    if (S.ch[i] == T.ch[j])
    {
      i++;
      j++;
    }
    else
    {
      j = next[j];
      if (j == 0)
      {
        i++;
        j++;
      }
    }
  }
  if (j == T.len)
  {
    return i - j + 1;
  }
  return 0;
}

// 清空
void ClearString(SString *S)
{
  S->len = 0;
}

int main(void)
{
  SString concat_str, copy_str, sub_str, str1, str2, str3;
  char c1[MAXLEN] = "qwer1234", c2[MAXLEN] = "654321", c3[MAXLEN] = "wer";
  bool is_empty;
  int cmp, index;
  StrAssign(&str1, c1);
  StrAssign(&str2, c2);

  StrCopy(&copy_str, str1);

  is_empty = StrEmpty(str1);
  cmp = StrCompare(str1, str2);

  SubString(&sub_str, str1, 4, 4);
  Concat(&concat_str, str1, str2);

  index = Index(str1, sub_str);
  index = Index_ver1(str1, sub_str);

  ClearString(&concat_str);
  ClearString(&str1);
  ClearString(&str2);
  ClearString(&copy_str);
  return 0;
}