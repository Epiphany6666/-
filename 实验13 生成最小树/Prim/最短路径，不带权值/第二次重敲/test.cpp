#include"ShortPath.h"
int main()
{
	int A[MAXV][MAXV] = {
		{0, 1, 1, 1, 1, 0, 0},
		{1, 0, 0, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 1, 0}
	};
	int n = 7, e = 10;
	AdjGraph* G;
	CreateGraph(G, A, n, e);
	ShortPath(G, 1, 4);
	return 0;
}