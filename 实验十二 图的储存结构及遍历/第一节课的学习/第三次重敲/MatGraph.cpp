#include"MatGraph.h"
int main()
{
	int A[MAXV][MAXV] = { {0 , 5,INF, 7, INF, INF},
	{INF, 0, 4, INF, INF, INF},
	{0, INF, 0, INF, INF, 9},
	{INF, INF, 5, 0, INF, 6},
	{INF, INF, INF, 5, 0, INF},
	{3, INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 10;
	MatGraph* G = NULL;
	CreateMatGraph(G, A, n, e);
	DispGraph(G);
	DFSTraverse(G);
	BFSTraverse(G);
	return 0;
}