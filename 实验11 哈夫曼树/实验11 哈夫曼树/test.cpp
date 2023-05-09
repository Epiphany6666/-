#include"haffman.h"
int main()
{
	char str[M] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int fnum[M] = { 5, 25, 3, 6, 10, 11, 36, 4 };
	/*int N = sizeof(str) / sizeof(str[0]);
	int M = 2 * N - 1;*/
	HTNode ht[M];
	int i = 0;
	for (i = 0; i < M; i++)
	{
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	CreateHT(ht);//CreateHTNode
	HcdNode hc[N];
	Hcod(ht, hc);//CreateHCode
	DispHcd(ht, hc);
	return 0;
}