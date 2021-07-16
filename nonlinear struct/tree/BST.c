// 二叉排序树
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct BSTNode
{
  int key;
  struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

typedef BSTNode Position;
// 递归搜索版 最坏空间复杂度 O(h) h为树高度
BSTNode *BSTNodeSearch(BSTree T, int key)
{
  BSTNode *N = T;
  if (N == NULL)
  {
    return NULL;
  }
  if (key == N->key)
  {
    return N;
  }
  if (key > N->key)
  {
    return BSTNodeSearch(N->rchild, key);
  }
  if (key < N->key)
  {
    return BSTNodeSearch(N->lchild, key);
  }
  return NULL;
}

// 非递归搜索版 最坏空间复杂度 O(1)
BSTNode *BSTNodeSearchV2(BSTree T, int key)
{
  BSTNode *N = T;
  while (N != NULL)
  {
    if (key == N->key)
    {
      return N;
    }
    N = key > N->key ? N->rchild : N->lchild;
  }
  return NULL;
}

// 插入递归实现 最坏空间复杂度 O(h)
bool BSTInsert(BSTree *T, int key)
{
  BSTNode *N = *T;
  if (key > N->key)
  {
    if (N->rchild == NULL)
    {
      BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
      newNode->key = key;
      newNode->lchild = NULL;
      newNode->rchild = NULL;
      N->rchild = newNode;
      return true;
    }
    return BSTInsert(&(N->rchild), key);
  }
  if (key < N->key)
  {
    if (N->lchild == NULL)
    {
      BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
      newNode->key = key;
      newNode->lchild = NULL;
      newNode->rchild = NULL;
      N->lchild = newNode;
      return true;
    }
    return BSTInsert(&(N->lchild), key);
  }
  return false;
}

// 插入非递归实现
bool BSTInsertV2(BSTree *T, int key)
{
  BSTNode *N = *T, *F;
  bool isLeft = true;
  while (N != NULL)
  {
    if (key == N->key)
    {
      return false;
    }
    F = N;
    if (key > N->key)
    {
      N = N->rchild;
      isLeft = false;
    }
    else
    {
      N = N->lchild;
      isLeft = true;
    }
  }
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  newNode->key = key;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  if (isLeft)
  {
    F->lchild = newNode;
  }
  else
  {
    F->rchild = newNode;
  }
  return true;
}

// 插入非递归实现
bool BSTInsertV3(BSTree *T, int key)
{
  BSTNode *N = *T;
  while (N != NULL)
  {
    BSTNode *new = (BSTNode *)malloc(sizeof(BSTNode));
    new->key = key;
    new->rchild = NULL;
    new->lchild = NULL;
    if (key = N->key)
    {
      return false;
    }
    if (key > N->key)
    {
      if (N->rchild == NULL)
      {
        N->rchild = new;
        return true;
      }
      else
      {
        N = N->rchild;
      }
    }
    if (key > N->key)
    {
      if (N->lchild == NULL)
      {
        N->lchild = new;
        return true;
      }
      else
      {
        N = N->lchild;
      }
    }
    free(new);
  }
}
// 找出最小元素 并返回其地址
BSTNode *FindMin(BSTree T)
{
  BSTNode *N = T;
  while (N->lchild != NULL)
  {
    N = N->lchild;
  }
  return N;
}

// 找出最大元素 并返回其地址
BSTNode *FindMax(BSTree T)
{
  BSTNode *N = T;
  while (N->rchild != NULL)
  {
    N = N->rchild;
  }
  return N;
}

// 删除元素
BSTNode *BSTDelete(BSTree *T, int key)
{
  BSTNode *N = *T, *TMP;
  if (key < (*T)->key)
  {
    N->lchild = BSTDelete(&(N->lchild), key);
  }
  else if (key > (*T)->key)
  {
    N->rchild = BSTDelete(&(N->rchild), key);
  }
  else
  {
    if (N->lchild && N->rchild)
    {
      TMP = FindMin(N->rchild);
      N->key = TMP->key;
      N->rchild = BSTDelete(&(N->rchild), N->key);
    }
    else
    {
      TMP = N;
      // 左子树为空
      if (!N->lchild)
      {
        N = N->rchild;
      }
      else
      {
        N = N->lchild;
      }
      free(TMP);
    }
  }
  return N;
}

// 初始化搜索树
void InitTree(BSTree *T, int key)
{
  *T = (BSTree)malloc(sizeof(BSTNode));
  (*T)->key = key;
  (*T)->lchild = NULL;
  (*T)->rchild = NULL;
}

// 构造二叉排序树
void CreateBST(BSTree *T, int data[], int n)
{
  for (int i = 0; i < n; i++)
  {
    BSTInsert(T, data[i]);
  }
}

int main(void)
{
  BSTree T;
  int data[10] = {9, 8, 7, 6, 13, 17, 0, 12, 14, 19};
  InitTree(&T, 10);
  CreateBST(&T, data, 10);
  BSTDelete(&T, 13);
  BSTDelete(&T, 10);
  return 0;
}