// 最普通的线性查找
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct
{
  ElemType *elem;
  int len;
} SSTable;

void init(SSTable *t)
{
  t->elem = (ElemType *)malloc(sizeof(ElemType));
  t->len = 0;
}
bool insert(SSTable *t, ElemType data)
{
  ElemType *newElem = (ElemType *)malloc(sizeof(ElemType) * (t->len + 1));
  ElemType *p = t->elem;
  if (newElem == NULL)
  {
    return false;
  }
  for (int i = 0; i < t->len; i++)
  {
    newElem[i] = t->elem[i];
  }
  newElem[t->len++] = data;
  t->elem = newElem;
  free(p);
  return true;
}

int search(SSTable t, ElemType key)
{
  for (int i = 0; i < t.len; i++)
  {
    if (t.elem[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int main(void)
{
  SSTable table;
  int search_res;
  init(&table);
  insert(&table, 12);
  insert(&table, 1);
  insert(&table, 8);
  insert(&table, 2);
  insert(&table, 7);
  insert(&table, 6);
  search_res = search(table, 6);
  return 0;
}