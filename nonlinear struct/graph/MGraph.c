// 领接矩阵法 适合稠密图
#define MAX_VERTEX_NUM 100
#define INFINITY (int)(~0U >> 1)
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
