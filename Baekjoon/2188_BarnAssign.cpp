#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX	402
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

// S : 400
// E : 401
// 소 : 0~199
// 축사 : 200~399 
int main()
{
	int N,M;
	vector<Edge*> adj[MAX_VERTEX];
	
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++) // S -> 소 
	{
		Edge* e1 = new Edge(i,1);
		Edge* e2 = new Edge(400,0);
		e1->reverse = e2;
		e2->reverse = e1;
		adj[400].push_back(e1);
		adj[i].push_back(e2);
	}
	for(int i=200; i<200+M; i++) // 축사 -> E 
	{
		Edge* e1 = new Edge(401,1);
		Edge* e2 = new Edge(i,0);
		e1->reverse = e2;
		e2->reverse = e1;
		adj[i].push_back(e1);
		adj[401].push_back(e2);
	}
	for(int i=0; i<N; i++) // 소 -> 축사 
	{
		int A;
		scanf("%d",&A);
		for(int j=0; j<A; j++)
		{
			int w;
			scanf("%d",&w);
			Edge* e1 = new Edge(w+199,1);
			Edge* e2 = new Edge(i,0);
			e1->reverse = e2;
			e2->reverse = e1;
			adj[i].push_back(e1);
			adj[w+199].push_back(e2);			
		}
	}

	int total = 0, S = 400, E = 401;
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
