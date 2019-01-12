#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX	5001
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
	int t=0;
	while(1)
	{
		int K,N;
		vector<Edge*> adj[MAX_VERTEX];
		scanf("%d %d",&K,&N);
		
		if(K == 0 && N == 0)
			break;
		
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
		
		for(int i=0; i<N; i++)
		{
			while(1)
			{
				int w;
				char c;
				scanf("%d%c",&w,&c);
				w--;
				
				Edge *e1 = new Edge(2*w,1);
				Edge *e2 = new Edge(2*i+1,0);
				e1->reverse = e2;
				e2->reverse = e1;
				adj[2*i+1].push_back(e1);
				adj[2*w].push_back(e2);

				Edge *e3 = new Edge(2*i,1);
				Edge *e4 = new Edge(2*w+1,0);
				e3->reverse = e4;
				e4->reverse = e3;
				adj[2*w+1].push_back(e3);
				adj[2*i].push_back(e4);
								
				if(c == '\n') break;
			}
		}
		
		int ans_count = 0, S = 1, E = 2;
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
			
			ans_count ++;
		}
		
		printf("Case %d:\n", ++t);
		if (ans_count >= K)
		{
			for (int i=0; i<K; i++)
			{
				int now = 1;
				while (now != 2)
				{
					if(now % 2 == 1)
						printf("%d ", now/2+1);
					for (Edge *e : adj[now])
					{
						int next = e->To;
						if (e->F > 0)
						{
							e->F = 0;
							e->reverse->F = 0;
							now = next;
							break;
						}
					}
				}
				printf("2\n");
			}
		}
		else
			printf("Impossible\n");
		printf("\n");
	}
	return 0;
}
