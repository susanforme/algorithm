#include <stdbool.h>
#define MAX_VEX_NUM 100
#define INFINITY 0x7fffffff

bool visited[MAX_VEX_NUM];
typedef int VexType;
typedef int EdgeType;
typedef struct MGraph
{
  VexType vex[MAX_VEX_NUM];
  EdgeType edge[MAX_VEX_NUM][MAX_VEX_NUM];
  int vexNum, edgeNum;
} MGraph;

void visit(int v) {}
// 搜索v第一个临节点
int FirstNeighbor(MGraph G, int v) {}

// 搜索v除了w节点的临近节点
int NextNeighbor(MGraph G, int v, int w) {}

void DFS(MGraph G, int v)
{
  visit(v);
  visited[v] = true;
  int w = FirstNeighbor(G, v);
  while (w >= 0)
  {
    // 递归
    if (!visited[v])
    {
      DFS(G, w);
    }
    w = NextNeighbor(G, v, w);
  }
}

void DFSTraverse(MGraph G, int v)
{
  for (int i = 0; i < G.vexNum; i++)
  {
    G.vex[i] = false;
  }
  G.vexNum = 0;
  G.edgeNum = 0;
  for (int i = 0; i < G.vexNum; i++)
  {
    if (!visited[i])
    {
      DFS(G, i);
    }
  }
}