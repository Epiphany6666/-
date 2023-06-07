#include"KeyPath.h"
int main()
{
	int A[MAXV][MAXV] = {
	{0,   6,  4,   5,  INF, INF, INF, INF, INF},
	{INF, 0,  INF, INF, 1, INF, INF, INF, INF},
	{INF, INF, 0,  INF, 1, INF, INF, INF, INF},
	{INF, INF, INF, 0, INF, INF, INF, 2, INF},
	{INF, INF, INF, INF, 0,  9,   7, INF, INF},
	{INF, INF, INF, INF, INF, 0, INF, INF, 2},
	{INF, INF, INF, INF, INF, INF, 0, INF, 4},
	{INF, INF, INF, INF, INF, INF, INF, 0, 4},
	{INF, INF, INF, INF, INF, INF, INF, INF, 0} };
	int n = 9, e = 11; 
	AdjGraph* G;
	CreateGraph(G, A, n, e);
	KeyPath(G);
	return 0;
}