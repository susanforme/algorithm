#include <stdbool.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct BiNode
{
  ElemType data;
  struct BiNode *lchild, *rchild;
  int level;
} BiNode, *BiTree;

void count(BiNode *p, int level)
{
  if (p != NULL)
  {
    count(p->lchild, level + 1);
    p->level = level;
    count(p->rchild, level + 1);
  }
}
void initTree(BiTree *root)
{
  *root = NULL;
  *root = (BiTree)malloc(sizeof(BiNode));
  // c中不能进行如下方式赋值
  (*root)->data = 3;
  (*root)->lchild = NULL;
  (*root)->rchild = NULL;
}
bool BSTInsert(BiTree T, int data)
{
  BiNode *N = T;
  if (data > N->data)
  {
    if (N->rchild == NULL)
    {
      BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
      newNode->data = data;
      newNode->lchild = NULL;
      newNode->rchild = NULL;
      N->rchild = newNode;
      return true;
    }
    return BSTInsert(N->rchild, data);
  }
  else if (data < N->data)
  {
    if (N->lchild == NULL)
    {
      BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
      newNode->data = data;
      newNode->lchild = NULL;
      newNode->rchild = NULL;
      N->lchild = newNode;
      return true;
    }
    return BSTInsert(N->lchild, data);
  }
  return false;
}
int main(void)
{
  BiTree root;
  initTree(&root);
  BSTInsert(root, 1);
  BSTInsert(root, 2);
  BSTInsert(root, 4);
  BSTInsert(root, 5);
  BSTInsert(root, 6);
  BSTInsert(root, 7);
  count(root, 1);
  return 0;
}