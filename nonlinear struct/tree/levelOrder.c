#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct BiNode
{
  ElemType data;
  struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct LinkNode
{
  BiNode *data;
  struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue
{
  LinkNode *rear, *front;
  int len;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue *q)
{
  q->rear = NULL;
  q->front = NULL;
  q->len = 0;
}

// 队列是否为空
bool EmptyQueue(LinkQueue q)
{
  // 陈越版数据结构判空
  return q.front == NULL;
}

// 入队
void EnQueue(LinkQueue *q, BiNode *data)
{
  LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
  newNode->data = data;
  newNode->next = NULL;
  if (q->rear != NULL)
  {
    q->rear->next = newNode;
  }
  if (q->front == NULL)
  {
    q->front = newNode;
  }
  q->rear = newNode;
  q->len++;
}

// 出队
void DeQueue(LinkQueue *q, BiNode **x)
{
  if (EmptyQueue(*q))
  {
    return;
  }
  *x = q->front->data;
  LinkNode *dele = q->front;
  q->front = dele->next;
  free(dele);
  q->len--;
}

// 初始化二叉树
void InitBiTree(BiTree *t)
{
  *t = (BiTree)malloc(sizeof(BiNode));
  (*t)->lchild = NULL;
  (*t)->rchild = NULL;
}

// 查看树
void visit(BiTree t) {}
// 层序遍历
void LevelOrder(BiTree t)
{
  LinkQueue q;
  InitQueue(&q);
  // 根节点
  BiTree p;
  // 根节点入队
  EnQueue(&q, t);
  while (!EmptyQueue(q))
  {
    DeQueue(&q, &p);
    visit(p);
    if (p->lchild != NULL)
    {
      EnQueue(&q, p->lchild);
    }
    if (p->rchild != NULL)
    {
      EnQueue(&q, p->rchild);
    }
  }
}

int main(void)
{
  LinkQueue q;
  BiNode *b_test;
  InitQueue(&q);
  EnQueue(&q, b_test);
  EnQueue(&q, b_test);
  return 0;
}