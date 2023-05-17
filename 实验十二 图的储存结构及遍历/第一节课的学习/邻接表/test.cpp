//2����дһ������ Graphadj.cpp�����һ��ͼ���ڽӱ�Ĵ洢�ṹ��
//(1)������ڽӱ�
//(2)���������ȱ�������
//(3)���������ȱ�������
//(4)���0 - 4�ļ�·��
#include"AdjGraph.h"
int main()
{
	int A[MAXV][MAXV] = { {0, 5, INF, 7, INF, INF},
		{INF, 0, 4, INF, INF, 5, 0, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{3,INF, INF, INF, 1, 0} };
	int n = 6;
	int e = 10;
	AdjGraph* G = NULL;
	CreateAdjGraph(G, A, n, e);
	//(1)������ڽӱ�
	DispAdjGraph(G);
	//(2)���������ȱ�������
	DFSTraverse(G, 0);
	//(3)���������ȱ�������
	BFSTraverse(G, 0);
	//(4)���0 - 4�ļ�·��
	int path[MAXV] = { 0 };//��·��
	int d = -1;//·������
	FindaPath(G, 0, 4, path, d);
	return 0;
}