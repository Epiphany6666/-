#include"Prim.h"
int main()
{
	int A[MAXV][MAXV] = { {0, 19, INF, INF, 14, INF, 18},
						 {19, 0, 5, 7, 12, INF, INF},
						 {INF, 5, 0, 3, INF, INF, INF},
						 {INF, 7, 3, 0, 8, 21, INF},
						 {14, 12, INF, 8, 0, INF, 16},
						 {18, INF, INF, INF, 16, 0, 27},
						 {INF, INF, INF, 21, INF, 27, 0} };
	int n = 7, e = 11;
	MatGraph g;
	CreateGraph(g, A, n, e);
	Prim(g,  0);
	return 0;
}