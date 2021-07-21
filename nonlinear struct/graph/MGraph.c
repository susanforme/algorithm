// 领接矩阵法 适合稠密图
#define MAXVERTEXNUM 100
#define INFINITY (int)(~0U >> 1)
typedef char VertexType;
typedef int EdgeType;
typedef struct MGraph
{
  // 顶点表
  VertexType vex[MAXVERTEXNUM];
  // 边表 若仅表示是否存在建议使用bool型
  EdgeType Edge[MAXVERTEXNUM][MAXVERTEXNUM];
  // 图当前的顶点数及边数
  int vexNum, edgeNum;
} MGraph;
