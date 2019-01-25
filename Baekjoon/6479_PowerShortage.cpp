#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200000

struct Edge {
	int u,v,w;
	Edge() :Edge(-1,-1,0) {}
	Edge(int U, int V, int W) : u(U),v(V),w(W) {}
	bool operator<(const Edge& e) const{ return w < e.w; }
};

int p[MAX];
Edge e[200000];

int find(int a)
{
	if(p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b) return false;
	p[b] = a;
	return true;
}

int main()
{
	while(1)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		if(m == 0 && n == 0)
			break;
					
		fill(p,p+MAX,-1);
		int total = 0;
		for(int i=0; i<n; i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			e[i] = Edge(u,v,w);
			total += e[i].w;
		}
		sort(e,e+n);
		int ans=0,cnt=0;
		for(int i=0; i<n; i++)
		{
			if(merge(e[i].u,e[i].v)) 
			{
				total -= e[i].w;
				if(++cnt == m-1) break;
			}
		}
		printf("%d\n",total);
	}
	return 0;
}
