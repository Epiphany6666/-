#include"huffman.h"
int s1, s2;
int min(HTNode ht[], int i)
{
    int minWeight = 10000;
    int min = 0;//最小值的下标 
    int j = 0;
    for (j = 0; j < i; j++)
    {
        if (minWeight > ht[j].weight && ht[j].parent == -1)
        {
            minWeight = ht[j].weight;
            min = j;
        }
    }
    ht[min].parent = 1;
    return min;
}

void select(HTNode ht[], int i)
{
    s1 = min(ht, i);
    s2 = min(ht, i);
}

void CreateHT(HTNode ht[])
{
    int i = 0;
    for (i = N; i < M; i++)
    {
        select(ht, i);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[s1].parent = ht[s2].parent = i;
    }
    for (i = 0; i < M; i++)
    {
        printf("%2d  %2d  %2d  %2d\n", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }
}

void CreateHcd(HTNode ht[], HCd hcd[])
{
    int i = 0;
    int f = 0;
    for (i = 0; i < N; i++)
    {
        f = ht[i].parent;
        hcd[i].start = N;
        while (f != -1)
        {
            if (ht[f].lchild == i)
            {
                hcd[i].data[--hcd[i].start] = '0';
            }
            else
            {
                hcd[i].data[--hcd[i].start] = '1';
            }
            f = ht[f].parent;
        }
    }
}

void DispHcd(HCd hcd[])
{
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = hcd[i].start; j < N; j++)
        {
            printf("%c", hcd[i].data[j]);
        }
        printf("\n");
    }
}