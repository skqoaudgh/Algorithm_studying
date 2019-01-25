#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

struct Edge {
	int u,v;
	float w;
	Edge() {}
	Edge(int U, int V, float W) : u(U),v(V),w(W) {}
	bool operator <(const Edge& O)const{ return w < O.w; }
};

int p[501];
Edge e[250001];

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

float getDist(float ax,float ay,float bx,float by)
{
	float a = abs(bx-ax);
	float b = abs(by-ay);
	return sqrt(a*a+b*b);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int S,P,arr[501][2];
		scanf("%d %d",&S,&P);
		for(int i=0; i<P; i++)
			scanf("%d %d",&arr[i][0],&arr[i][1]);
		
		int idx=0;
		for(int i=0; i<P-1; i++)
		{
			for(int j=i+1; j<P; j++)
			{
				float w = getDist(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
				e[idx++] = Edge(i,j,w);
			}
		}

		sort(e,e+idx);
		fill(p,p+P,-1);
		float ans=0;
		int cnt=0;
		for(int i=0; i<idx; i++)
		{
			if(merge(e[i].u,e[i].v)) 
			{
				ans = e[i].w;
				if(++cnt == P-S) break;
			}
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
