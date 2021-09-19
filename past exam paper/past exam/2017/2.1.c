// 算法阅读题第一题
#define INFINITY 0x7fffffff
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DLNode
{
  ElemType data;
  struct DLNode *prior, *next;
} DLNode, *DList;

bool deleteDul(DList L, int i, ElemType *e)
{
  DLNode *p = L->next;
  int index = 1;
  while (p != NULL)
  {
    if (i == index)
    {
      DLNode *prior = p->prior, *next = p->next;
      *e = p->data;
      prior->next = next;
      next->prior = prior;
      return true;
    }
    p = p->next;
    index++;
  }
  return false;
}

bool initList(DList *list)
{
  // 分配空间 第一个节点不插数据 并不能分配数据,因为list不会将数据带回,必须使用指针的指针
  *list = (DLNode *)malloc(sizeof(DLNode));
  // 内存不足空间分配失败
  if ((*list) == NULL)
  {
    return false;
  }
  // 初始化下个节点
  (*list)->next = NULL;
  (*list)->prior = NULL;
  (*list)->data = INFINITY;
  return true;
}
// 插入
void insertList(DList L, ElemType e)
{
  DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
  DLNode *last = L->prior != NULL ? L->prior : L;
  newNode->data = e;
  last->next = newNode;
  newNode->prior = last;
  L->prior = newNode;
}

int main(void)
{
  DList L;
  ElemType res;
  initList(&L);
  insertList(L, 1);
  insertList(L, 2);
  insertList(L, 3);
  insertList(L, 4);
  insertList(L, 5);
  insertList(L, 6);
  deleteDul(L, 1, &res);
  return 0;
}