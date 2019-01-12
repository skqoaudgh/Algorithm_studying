#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX	801
#define INF 		1000000000

struct Edge {
	int To, C, F;
	Edge* reverse;
	
	Edge() : Edge(-1,0){}
	Edge(int _To, int _C) : To(_To),C(_C),F(0){}
	
	int spare() {
		return C-F;
	}
	void addFlow(int Flow) {
		F += Flow;
		reverse->F -= Flow;
	}
};

int main()
{
	int N,P;
	vector<Edge*> adj[MAX_VERTEX];
	scanf("%d %d",&N,&P);
	for(int i=0; i<N; i++)
	{
		int u = 2*i;
		int v = u+1;
		Edge *e1 = new Edge(v,1);
		Edge *e2 = new Edge(u,0);
		e1->reverse = e2;
		e2->reverse = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	for(int i=0; i<P; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		
		Edge* e1 = new Edge(2*a,1);
		Edge* e2 = new Edge(2*b+1,0);
		e1->reverse = e2;
		e2->reverse = e1;
		adj[2*b+1].push_back(e1);
		adj[2*a].push_back(e2);	
		
		Edge* e3 = new Edge(2*b,1);
		Edge* e4 = new Edge(2*a+1,0);
		e3->reverse = e4;
		e4->reverse = e3;
		adj[2*a+1].push_back(e3);
		adj[2*b].push_back(e4);		
	}
	
	int total = 0, S = 1, E = 2;
	while(1)
	{
		int prev[MAX_VERTEX];
		Edge* path[MAX_VERTEX] = {0};
		memset(prev,-1,sizeof(prev));
		
		queue<int> Q;
		Q.push(S);
		while(!Q.empty() && prev[E] == -1)
		{
			int curr = Q.front();
			Q.pop();
			for(Edge *e: adj[curr])
			{
				int next = e->To;
				if(e->spare() > 0 && prev[next] == -1)
				{
					Q.push(next);
					prev[next] = curr;
					path[next] = e;
					if(next == E) break;
				}
			}
		}
		if(prev[E] == -1) break;
		
		for(int i=E; i!=S; i=prev[i])
			path[i]->addFlow(1);
		
		total += 1;
	}
	printf("%d",total);
	return 0;
}
