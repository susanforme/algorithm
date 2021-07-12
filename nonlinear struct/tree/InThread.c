// 中序线索化
#include <stdbool.h>
#include <stdlib.h>

typedef struct ThreadNode
{
  int data;
  struct ThreadNode *lchild, *rchild;
  // 左右线索标志
  bool ltag, rtag;
} ThreadNode, *ThreadTree;

typedef int ElemType;

void initTree(ThreadTree *root)
{
  *root = NULL;
  *root = (ThreadTree)malloc(sizeof(ThreadNode));
  // c中不能进行如下方式赋值
  (*root)->data = 1;
  (*root)->lchild = NULL;
  (*root)->rchild = NULL;
  (*root)->ltag = false;
  (*root)->rtag = false;
}

// 仅供测试使用 瞎插数据而已
void InsertTree(ThreadNode *n, int data, bool isRight)
{
  ThreadNode *newNode = (ThreadNode *)malloc(sizeof(ThreadNode));
  newNode->data = data;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  newNode->ltag = false;
  newNode->rtag = false;
  if (isRight)
  {
    n->rchild = newNode;
  }
  else
  {
    n->lchild = newNode;
  }
}

void visit(ThreadNode *q, ThreadNode **pre)
{
  // 建立前驱线索
  if (q->lchild == NULL)
  {
    q->lchild = *pre;
    q->ltag = true;
  }
  // 建立前驱节点的后继线索
  if (*pre != NULL && (*pre)->rchild == NULL)
  {
    (*pre)->rchild = q;
    (*pre)->rtag = true;
  }
  *pre = q;
}

void InThread(ThreadTree *t, ThreadNode **pre)
{
  if (*t != NULL)
  {
    InThread(&((*t)->lchild), pre);
    visit(*t, pre);
    InThread(&((*t)->rchild), pre);
  }
}

void CreateInThread(ThreadTree T, ThreadNode **pre)
{
  *pre = NULL;
  if (T != NULL)
  {
    InThread(&T, pre);
    if ((*pre)->rchild == NULL)
    {
      (*pre)->rtag = true;
    }
  }
}

int main(void)
{
  ThreadTree tree;
  static ThreadNode *pre = NULL;
  initTree(&tree);
  InsertTree(tree, 12, false);
  InsertTree(tree, 11, true);
  CreateInThread(tree, &pre);
  return 0;
};