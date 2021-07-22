// 广度优先搜索
#include <stdbool.h>
// 最大顶点数
#define MAX_VERTEX_NUM 100
#define INFINITY 0X7fffffff
#define MAXSIZE 10

typedef struct
{
  int data[MAX_VERTEX_NUM];
  int front, rear;
} SqQueue;

void init_queue(SqQueue *s)
{
  // 初始化为0
  s->front = s->rear = 0;
}
// 入队
bool en_queue(SqQueue *s, int x)
{
  if (s->rear == MAXSIZE - 1)
  {
    return false;
  }
  // 万一是第九个则有越界可能
  // s->data[s->rear++] = x;

  // 取模 循环队列
  s->data[s->rear] = x;
  s->rear = (s->rear + 1) % MAXSIZE;
  return true;
}

// 出队
bool de_queue(SqQueue *s, int *x)
{
  if (is_empty(s))
  {
    return false;
  }
  // *x = s->data[s->front++];
  *x = s->data[s->front++];
  s->front = (s->front + 1) % MAXSIZE;
  return true;
}

bool is_empty(SqQueue *s)
{
  return s->rear == s->front;
}

typedef char VertexType;
typedef int EdgeType;
typedef struct MGraph
{
  // 顶点表
  VertexType vex[MAX_VERTEX_NUM];
  // 边表 若仅表示是否存在建议使用bool型
  EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  // 图当前的顶点数及边数
  int vexNum, edgeNum;
} MGraph;

// 辅助标记数组
bool visited[MAX_VERTEX_NUM];
SqQueue Q;

// 访问以key关键字的节点
void visit(int key) {}

// 搜索v第一个临节点
int FirstNeighbor(MGraph G, int v) {}

// 搜索v除了w节点的临近节点
int NextNeighbor(MGraph G, int v, int w) {}

// 从顶点v开始广度优先遍历图G
void BFS(MGraph G, int v)
{
  visit(v);
  visited[v] = true;
  en_queue(&Q, v);
  while (!is_empty(&Q))
  {
    // 顶点v出队
    de_queue(&Q, &v);
    int w = FirstNeighbor(G, v);
    while (w >= 0)
    {
      // w为v未访问的邻接顶点
      if (!visited[w])
      {
        visit(w);
        visited[w] = true;
        en_queue(&Q, w);
      }
      // 检测v所有邻接顶点
      w = NextNeighbor(G, v, w);
    }
  }
}
void BFSTraverse(MGraph G)
{
  // 初始化
  for (int i = 0; i < G.vexNum; i++)
  {
    visited[i] = false;
  }
  init_queue(&Q);
  for (int i = 0; i < G.vexNum; i++)
  {
    if (!visited[i])
    {
      BFS(G, i);
    }
  }
}
