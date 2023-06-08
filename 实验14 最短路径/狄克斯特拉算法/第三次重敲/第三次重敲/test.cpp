#include"Dijkstra.h"
int main()
{
	int A[MAXV][MAXV] = { {0, 6, 3, INF, INF, INF},
		{6, 0, 2, 5, INF, INF},
		{3, 2, 0, 3, 4, INF},
		{INF, 5, 3, 0, 2, 3},
		{INF, INF, 4, 2, 0, 5},
		{INF, INF, INF, 3, 5, 0} };
	int n = 6;
	int e = 9;
	MatGraph g;
	CreateGraph(g, A, n, e);
	Dijkstra(g, 0);
	return 0;
}