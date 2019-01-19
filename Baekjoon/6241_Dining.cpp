#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX_N = 400;
const int MAX_V = MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int C[MAX_V][MAX_V], F[MAX_V][MAX_V];
int level[MAX_V];
int work[MAX_V];
vector<int> adj[MAX_V];

// 레벨그래프를 그리기 위한 BFS 함수 
bool bfs() 
{
	fill(level,level+MAX_V,-1);
	level[S] = 0;
	
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int next: adj[curr])
		{
			if(level[next] == -1 && C[curr][next]-F[curr][next] > 0)
			{
				level[next] = level[curr]+1;
				q.push(next);
			}
		}
	}
	return (level[E] != -1);
}

// 차단유량을 구하기 위한 DFS 함수 
int dfs(int curr, int dest, int flow)
{
	if(curr == dest) return flow;
	for(int &i=work[curr]; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		if(level[next] == level[curr]+1 && C[curr][next]-F[curr][next] > 0)
		{
			int df = dfs(next,dest, min(C[curr][next]-F[curr][next],flow));
			if(df > 0)
			{
				F[curr][next] += df;
				F[next][curr] -= df;
				return df; // 바로 이전의 간선은 다음 경로에서 사용될 수 있으므로 i++가 되기 전에 리턴을 한다. 
			}
		}
	}
	return 0;
}

int main()
{
	// 0~99:IN소 100~199:OUT소 200~299:음식 300~399:음료 400:소스 401:싱크
	int n,f,d; // F:FOOD D:DRINK N:COW
	scanf("%d %d %d",&n,&f,&d);
	
	// 소스와 음식 연결 
	for(int i=0; i<f; i++)
	{
		adj[S].push_back(i+200);
		C[S][i+200] = 1;
	}
		
	// 싱크와 음료 연결 
	for(int i=0; i<d; i++)
	{
		adj[i+300].push_back(E);
		C[i+300][E] = 1;
	}
				
	// 소 두개로 분할
	for(int i=0; i<n; i++)
	{
		adj[2*i].push_back(2*i+1);
		C[2*i][2*i+1] = 1;
	}
		
 
	for(int i=0; i<n; i++)
	{
		int F_cnt,D_cnt;
		scanf("%d %d",&F_cnt,&D_cnt);
		// 음식과 소 연결 
		for(int j=0; j<F_cnt; j++)
		{
			int w;
			scanf("%d",&w);
			w += 199; 
			adj[w].push_back(2*i);
			C[w][2*i] = 1;
			//printf("%d와 %d 연결\n",w,2*i);
		}
		// 음료와 소 연결
		for(int j=0; j<D_cnt; j++)
		{
			int w;
			scanf("%d",&w);
			w += 299; 
			adj[2*i+1].push_back(w);
			C[2*i+1][w] = 1;
			//printf("%d와 %d 연결\n",2*i+1,w);
		}
	}
	
	int total = 0;
	while(bfs())
	{
		fill(work, work+MAX_V, 0);
		while(1)
		{
			int flow = dfs(S,E,INF);
			if(flow == 0) break;
			total += flow;
		}
	}
	printf("%d",total);
	return 0;
}
