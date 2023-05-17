//2、编写一个程序 Graphadj.cpp，设计一个图的邻接表的存储结构。
//(1)输出其邻接表
//(2)输出深度优先遍历序列
//(3)输出广度优先遍历序列
//(4)输出0 - 4的简单路径
#include"AdjGraph.h"
int main()
{
	int A[MAXV][MAXV] = { {0, 5, INF, 7, INF, INF},
		{INF, 0, 4, INF, INF, 5, 0, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{3,INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 10;
	AdjGraph* G = NULL;
	CreateAdjGraph(G, A, n, e);
	//(1)输出其邻接表
	DispAdjGraph(G);
	//(2)输出深度优先遍历序列
	DFSTraverse(G, 0);
	//(3)输出广度优先遍历序列
	BFSTraverse(G, 0);
	//(4)输出0 - 4的简单路径
	int path[MAXV] = { 0 };//简单路径
	int d = -1;//路径长度
	FindaPath(G, 0, 4, path, d);
	return 0;
}