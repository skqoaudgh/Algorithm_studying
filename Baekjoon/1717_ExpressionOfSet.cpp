#include <cstdio>
#include <algorithm>
using namespace std;

int p[1000001];

int find(int a)
{
	if(p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];	
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[b] = a;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	fill(p,p+n+1,-1);
	for(int i=0; i<m; i++)
	{
		int oper,a,b;
		scanf("%d %d %d",&oper,&a,&b);
		if(oper == 0)
			merge(a,b);
		else if(oper == 1)
		{
			if(find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
