#include"SqString.cpp"
int Index_BF(SqString s,SqString t)//�����㷨 
{
	int i = 0, j = 0;
	while(i < s.length || j < t.length)
	{
		if(s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = i - j + 1;
			j = 0;
		}
	}
	if(j >= t.length)
	 	return i - t.length;
	else
		return -1;
}

void GetNext(SqString t,int next[])//���next����ֵ 
{
	int k = -1, j = 0;
	next[0] = -1;
	while(j < t.length-1)
	{
		if(k == -1 || t.data[j] == t.data[k])
		{
		j++;
		k++;
		next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}	
}

void GetNextVal(SqString t,int nextval[])//��nextval����ֵ 
{
	int k = -1, j = 0;
	while(j < t.length)
	{
		if(k == -1 || t.data[j] == t.data[k])
		{
			j++;
			k++;
			if(t.data[k]!=t.data[j])
			{
				nextval[j] = k;
			}
			else
			{
				nextval[j] = nextval[k];
			}
		}
		else
		{
			k = nextval[k];
		}
	}
}

int Index_KMP(SqString s,SqString t)//KMP�㷨 
{
	int i = 0,j = 0;
	int next[Max];
	GetNext(t,next);
	while(i < s.length || j < t.length)
	{
		if(s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[i];
		}
	}
	if(j >= t.length)
		return j-t.length;
	else
		return -1;
}

int Index_KMP1(SqString s,SqString t)//�Ľ���KMP�㷨 
{
	int i = 0,j = 0;
	int nextval[Max];
	GetNextVal(t,nextval);
	while(i < s.length || j < t.length)
	{
		if(s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextval[i];
		}
	}
	if(j >= t.length)
		return j-t.length;
	else
		return -1;
}

int main()
{
	SqString s,t;
	InitString(s);
	InitString(t);
	StrAssign(s,"abcabcdabcdeabcedfabcdefg");
	StrAssign(t,"abcdeabcdefab");
	if(Index_BF(s,t)!=-1)
		printf("t��s�е�λ�� = %d\n",Index_BF(s,t));
	else
		printf("û���ҵ���t"); 
	if(Index_KMP(s,t)!=-1)
		printf("t��s�е�λ�� = %d\n",Index_KMP(s,t));
	else
		printf("û���ҵ���t"); 
	if(Index_KMP1(s,t)!=-1)
		printf("t��s�е�λ�� = %d\n",Index_KMP1(s,t));
	else
		printf("û���ҵ���t"); 
	return 0;
}
