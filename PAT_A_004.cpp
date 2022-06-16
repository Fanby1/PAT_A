#include<cstdio>
#include<cstring>
struct Node
{
	int father = 0;
	int level = 0;
	bool NoChild = 1;
};
Node v[100];
char level[100]="\0";
int main()
{
	int N,M,i,j,c,ID,child,MAXLevel=1;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;++i)
	{
		scanf("%d%d",&ID,&c);
		v[ID].NoChild=0;
		for(j=0;j<c;++j)
		{
			scanf("%d",&child);
			v[child].father=ID;
		}
	}
	
	v[1].level=1;
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
		{
			if(v[j].father==i)
			{
				v[j].level=v[v[j].father].level+1;
				if(v[j].level>MAXLevel)
					MAXLevel=v[j].level;
			}
		}
	
	for(i=1;i<=N;++i)
		if(v[i].NoChild==1)
			level[v[i].level]++;
	for(i=1;i<MAXLevel;++i)
		printf("%d ",level[i]);
	printf("%d\n",level[i]);
	return 0;
}