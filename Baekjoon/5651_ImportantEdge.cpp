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
	int t;
	scanf("%d",&t);
	for(int test_case=0; test_case<t; test_case++)
	{
		int N,M;
		vector<Edge*> adj[MAX_VERTEX];
		vector< pair<int,int> > v;
		scanf("%d %d",&N,&M);
		for(int i=0; i<M; i++)
		{
			int f,t,b;
			scanf("%d %d %d",&f,&t,&b);
			v.push_back(make_pair(f,t));
			
			Edge *e1 = new Edge(t,b);
			Edge *e2 = new Edge(f,0);
			e1->reverse = e2;
			e2->reverse = e1;
			adj[f].push_back(e1);
			adj[t].push_back(e2);
		}
		
		int total = 0, S = 1, E = N;
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
			
			int ans = INF;
			
			for(int i=E; i!=S; i=prev[i])
				ans = min(ans,path[i]->spare());
			for(int i=E; i!=S; i=prev[i])
				path[i]->addFlow(ans);
			
			total += ans;
		}
		
		// 모든 간선을 검사해서 유량이 흐르지 않는 간선 찾기 = 완전 중요한 간선
		int import = 0;
		for(int i=0; i<v.size(); i++)
		{
			int S = v[i].first;
			int E = v[i].second;
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
			if(prev[E] == -1)
				import ++;
		}
		printf("%d\n",import);
	}
	return 0;
}
