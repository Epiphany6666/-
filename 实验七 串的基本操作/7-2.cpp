#include"SqString.cpp"
int Index_BF(SqString s,SqString t)
{
	int i = 0, j = 0;
	for(i = 0;i < s.length; i++)
	{
		for(j = 0; j < t.length; j++)
		{
			if(s.data[i] == t.data[j])
				break;
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
	}
	if(j >= t.length)
	 	return i - t.length;
	else
		return -1;
}
int main()
{
	SqString s,t;
	StrAssign(s,"abcabcdabcdeabcedfabcdefg");
	StrAssign(t,"abcdeabcdefab");
	if(Index_BF(s,t))
		printf("t在s中的位置 = %d\n",Index_BF(s,t));
	else
		printf("没有找到串t"); 
	return 0;
}
