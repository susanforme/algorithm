#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BiNode
{
  ElemType data;
  struct BiNode *lchild, *rchild;
  // 若经常需要寻找父节点,则可以再定义个父指针,称为三叉链表 考研一般不带,没要求带上比较好
  // struct BiNode *parent
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

int main(void)
{
  BiTree root;
  initTree(&root);
  return 0;
}