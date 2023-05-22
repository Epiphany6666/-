#define _CRT_SECURE_NO_WARNINGS
void Prim(MatGraph g, int v)
{
	int lowcost[MAXV];
	int mindist;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++)
	{
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++)
	{
		mindist = INF;
		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < mindist)
			{
				mindist = lowcost[j];
				k = j;
			}
		}
		printf("±ß(%d,%d)È¨Îª£º%d\n", closest[k], k, mindist);
		lowcost[k] = 0;

		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
}