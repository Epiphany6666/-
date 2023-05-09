#include"haffman.h"
int min(HTNode ht[], int i)
{
	//int minweight = fnum[0];
	int minweight = 1000; 
	int min = 0 ;
	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (minweight > ht[j].weight && ht[j].parent == -1)
		{
			minweight = ht[j].weight;
			min = j;
		}
	}
	ht[min].parent = 1;
	return min;
}

void CreateHT(HTNode ht[])
{
	//int i = N - 1;
	int i = N;
	int j = 0;
	//for(j = 0; j < M; j++)
	for(j = N; j < M; j++)
	{
		int s1 = min(ht, j);
		int s2 = min(ht, j);
		//ht[++i].weight = s1 + s2;
		ht[j].weight = ht[s1].weight + ht[s2].weight;
		ht[j].lchild = s1;
		ht[j].rchild = s2;
		ht[s1].parent = ht[s2].parent = j;
	}

	for (j = 0; j < M; j++)
	{
		printf("%c  %2d %2d %2d %2d\n", ht[j].data, ht[j].weight, ht[j].parent, ht[j].lchild, ht[j].rchild);
	}
}

void Hcod(HTNode ht[], HcdNode hc[])//CreateHCode
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int f = ht[i].parent;
		hc[i].start = N;
		while (f != -1)
		{
			if (ht[f].lchild == i)
			{
				hc[i].start--;
				//hc[i].hcd[hc[i].start] = 0;
				hc[i].hcd[hc[i].start] = '0';
			}
			else
			{
				hc[i].start--;
				//hc[i].hcd[hc[i].start] = 1;
				hc[i].hcd[hc[i].start] = '1';
			}
			f = ht[f].parent;
		}
	}
}

void DispHcd(HTNode ht[], HcdNode hc[])
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%c:", ht[i].data);
		int j = 0;
		for (j = hc[i].start; j < N; j++)
		{
			printf("%c", hc[i].hcd[j]);
		}
		printf("\n");
	}
}