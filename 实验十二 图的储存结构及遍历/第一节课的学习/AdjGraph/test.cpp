#include"AdjGraph.h"
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV] = { {0, 5, INF, 7, INF, INF},
		{INF, 0, 4, INF, INF, 5, 0, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{3,INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 20;
	CreateAdj(G, A, n, e);
	DispAdj(G);
	return 0;
}