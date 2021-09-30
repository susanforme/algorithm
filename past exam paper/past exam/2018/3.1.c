#include <stdlib.h>
#include <stdio.h>
// 二叉树双分支节点
typedef struct BiNode
{
  int data;
  struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void initTree(BiTree *root)
{
  *root = NULL;
  *root = (BiTree)malloc(sizeof(BiNode));
  // c中不能进行如下方式赋值
  (*root)->data = 1;
  (*root)->lchild = NULL;
  (*root)->rchild = NULL;
}

int count = 0;
int double_count(BiTree t)
{
  if (t != NULL)
  {
    if ((t->lchild != NULL) && (t->rchild != NULL))
    {
      count++;
    }
    double_count(t->lchild);
    double_count(t->rchild);
  }
  return count;
}

int main(void)
{
  BiTree tree;
  BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
  initTree(&tree);
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  newNode->data = 13;
  tree->lchild = newNode;
  tree->rchild = newNode;
  int data = double_count(tree);
  printf("data is %d.\n", data);
  return 0;
}