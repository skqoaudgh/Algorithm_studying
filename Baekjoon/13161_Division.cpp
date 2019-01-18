#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX_N = 500;
const int MAX_V = MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int N, C[MAX_V][MAX_V], F[MAX_V][MAX_V];
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
				return df;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int team;
		scanf("%d",&team);
		if(team == 1) // A진영
		{
			C[S][i] = INF;
			adj[S].push_back(i);	
			adj[i].push_back(S);
		} 
		else if(team == 2) // B진영 
		{
			C[i][E] = INF;
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&C[i][j]);
			if(i != j) adj[i].push_back(j);
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
	printf("%d\n",total);
	
	bool visited[MAX_V] = {false};
	visited[S] = true;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int next: adj[curr])
		{
			if(!visited[next] && C[curr][next]-F[curr][next] > 0)
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
	
	for(int i=0; i<N; i++)
		if(visited[i]) printf("%d ",i+1);
	puts("");
	for(int i=0; i<N; i++)
		if(!visited[i]) printf("%d ",i+1);	
	puts("");	
	return 0;
}
