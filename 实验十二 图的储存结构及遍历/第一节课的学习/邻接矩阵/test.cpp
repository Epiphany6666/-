//1����дһ������ GraphMat.cpp�����һ��ͼ���ڽӾ���Ĵ洢�ṹ
//(1)�Ծ������ʽ�����
//(2)�����������ȱ�������
//(3)����������ȱ�������
#include"MatGraph.h"
int main()
{
	MatGraph* G = NULL;
	int A[MAXV][MAXV] = { {0, 5, INF, 7, INF, INF},
		{INF, 0, 4, INF, INF, 5, 0, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{3,INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 10;
	CreateGraph(G, A, n, e);
	//(1)�Ծ������ʽ�����
	DispGraph(G);
	//(2)�����������ȱ�������
	DFSTraverse(G, 0);
	//(3)����������ȱ�������
	BFSTraverse(G, 0);
	return 0;
}