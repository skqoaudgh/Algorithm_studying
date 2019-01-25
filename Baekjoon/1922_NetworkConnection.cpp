#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1000
int p[MAX];

struct Edge {
	int u,v,w;
	Edge() {}
	Edge(int U, int V, int W) : u(U),v(V),w(W) {}
	bool operator <(const Edge& O)const{ return w < O.w; }
};

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
	int N,M;
	Edge e[100000];
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[i] = Edge(u-1,v-1,w);
	}
	sort(e,e+M);
	fill(p,p+N,-1);
	int ans=0,cnt=0;
	for(int i=0; i<M; i++)
	{
		if(merge(e[i].u,e[i].v)) 
		{
			ans += e[i].w;
			if(++cnt == N-1) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
