#include <stdbool.h>
#include <stdlib.h>
// 邻接表法 适合稀疏图
#define MAX_VERTEX_NUM 100

// 边权值
typedef int InfoType;
typedef int VertexType;
typedef struct ArcNode
{
  int adjvex;
  struct ArcNode *next;
  // 边权值
  InfoType info;
} ArcNode;

typedef struct VNode
{
  VertexType data;
  // 指向第一条弧
  ArcNode *first;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
  // 邻接表
  AdjList vertices;
  // 顶点数量 弧数量
  int vexNum, arcNum;
} ALGraph;

// 初始化栈
void InitStack() {}

// 入度表
int indegree[MAX_VERTEX_NUM];

// 记录拓扑排序
int print[MAX_VERTEX_NUM];

bool TopologicSort(ALGraph G)
{
  InitStack();
  for (int i = 0; i < G.vexNum; i++)
  {
    if (indegree[i] == 0)
    {
      Push(i);
    }
  }
  int count = 0;
  // 栈不空则存在入度为0的点
  while (!IsEmpty())
  {
    // 入度为0的点
    int v;
    // 出栈
    Pop(v);
    // 放入拓扑排序
    print[count++] = v;
    ArcNode *p = G.vertices[v].first;
    // 将所有v指向的顶点的入度减1,并且将入度减为0的顶点压入栈
    while (p != NULL)
    {
      v = p->adjvex;
      if (!(--indegree[v]))
      {
        // 入度为0,入栈
        Push(v);
      }
      p = p->next;
    }
  }
  // 拓扑排序数为顶点数量
  if (count == G.vexNum)
  {
    return true;
  }
  return false;
}