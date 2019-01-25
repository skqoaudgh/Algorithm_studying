#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge {
	int u,v,w;
	Edge() {}
	Edge(int U, int V, int W) : u(U),v(V),w(W) {}
	bool operator <(const Edge& O)const{ return w < O.w; }
};

struct Planet {
	int id,x,y,z;
	Planet() {}
	Planet(int _id,int _x, int _y, int _z) : id(_id),x(_x),y(_y),z(_z) {}
};

Edge e[300001];
Planet plan[100001];
int p[100001];
	
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

bool compX(Planet a, Planet b)
{
	return a.x < b.x;
}
bool compY(Planet a, Planet b)
{
	return a.y < b.y;
}
bool compZ(Planet a, Planet b)
{
	return a.z < b.z;
}

int getCost(Planet a, Planet b)
{
	int x,y,z,temp;
	x = abs(a.x-b.x);
	y = abs(a.y-b.y);
	z = abs(a.z-b.z);
	temp = min(x,y);
	return min(temp,z);	
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		plan[i] =  Planet(i,a,b,c);
	}
	int M = (N*1)*3,idx=0;
	sort(plan,plan+N,compX);
	for(int i=0; i<N-1; i++)
		e[idx++] = Edge(plan[i].id,plan[i+1].id,getCost(plan[i],plan[i+1]));
	sort(plan,plan+N,compY);
	for(int i=0; i<N-1; i++)
		e[idx++] = Edge(plan[i].id,plan[i+1].id,getCost(plan[i],plan[i+1]));
	sort(plan,plan+N,compZ);
	for(int i=0; i<N-1; i++)
		e[idx++] = Edge(plan[i].id,plan[i+1].id,getCost(plan[i],plan[i+1]));
			
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
