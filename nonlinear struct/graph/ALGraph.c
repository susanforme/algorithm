// 邻接表法 适合稀疏图
#include <stdlib.h>
#define MAXVERTEXNUM 100

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
} VNode, AdjList[MAXVERTEXNUM];

typedef struct
{
  // 邻接表
  AdjList vertices;
  // 顶点数量 弧数量
  int vexNum, arcNum;
} ALGraph;