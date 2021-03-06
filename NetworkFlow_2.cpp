#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX	52
#define INF 		1000000000

int CtoI(const char c)
{
	if(c >= 'a' && c <= 'z')
		return c-'a'+26;
	return c-'A';	
}

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
	int N;
	vector<Edge*> adj[MAX_VERTEX];
	
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		char u,v;
		int w;
		scanf(" %c %c %d",&u,&v,&w);
		u = CtoI(u);
		v = CtoI(v);
		
		Edge* e1 = new Edge(v,w);
		Edge* e2 = new Edge(u,0);
		e1->reverse = e2;
		e2->reverse = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	
	int total = 0, S = CtoI('A'), E = CtoI('Z');
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
		
		int sum = INF;
		for(int i=E; i!=S; i=prev[i])
			sum = min(sum,path[i]->spare());
		for(int i=E; i!=S; i=prev[i])
			path[i]->addFlow(sum);
		
		total += sum;
	}
	printf("%d",total);
	return 0;
}
