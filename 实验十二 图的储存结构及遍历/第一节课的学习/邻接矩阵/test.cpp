//1、编写一个程序 GraphMat.cpp，设计一个图的邻接矩阵的存储结构
//(1)以矩阵的形式的输出
//(2)输出其深度优先遍历序列
//(3)输出其广度优先遍历序列
#include"MatGraph.h"
int main()
{
	MatGraph* G = NULL;
	int A[MAXV][MAXV] = { {0, 5, INF, 7, INF, INF},
		{INF, 0, 4, INF, INF, 5, 0, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{3,INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 10;
	CreateGraph(G, A, n, e);
	//(1)以矩阵的形式的输出
	DispGraph(G);
	//(2)输出其深度优先遍历序列
	DFSTraverse(G, 0);
	//(3)输出其广度优先遍历序列
	BFSTraverse(G, 0);
	return 0;
}