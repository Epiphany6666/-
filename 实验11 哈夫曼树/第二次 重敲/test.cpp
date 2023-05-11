#include"huffman.h"
int main()
{
	char str[M] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int fnum[M] = { 5, 25, 3, 6, 10, 11, 36, 4 };
	HTNode ht[M];
	int i = 0;
	for (i = 0; i < M; i++)
	{
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	CreateHT(ht);//CreateHTNode
	HCd hc[N];
	CreateHcd(ht, hc);//CreateHCode
	DispHcd( hc);
	return 0;
}