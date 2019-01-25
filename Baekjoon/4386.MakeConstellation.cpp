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

int p[100];
Edge e[10000];

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
	int n,m;
	float arr[100][2];
	scanf("%d",&n);
	m = n*(n-1)/2;
	for(int i=0; i<n; i++)
	{
		float a,b;
		scanf("%f %f",&arr[i][0],&arr[i][1]);
	}
	
	int idx = 0;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			float w = getDist(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
			e[idx++] = Edge(i,j,w);
		}
	}
	sort(e,e+m);
	fill(p,p+n,-1);
	float ans=0;
	int cnt=0;
	for(int i=0; i<m; i++)
	{
		if(merge(e[i].u,e[i].v)) 
		{
			ans += e[i].w;
			if(++cnt == n-1) break;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}
