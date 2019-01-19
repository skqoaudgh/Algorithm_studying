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

// �����׷����� �׸��� ���� BFS �Լ� 
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

// ���������� ���ϱ� ���� DFS �Լ� 
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
				return df; // �ٷ� ������ ������ ���� ��ο��� ���� �� �����Ƿ� i++�� �Ǳ� ���� ������ �Ѵ�. 
			}
		}
	}
	return 0;
}

int main()
{
	// 0~99:IN�� 100~199:OUT�� 200~299:���� 300~399:���� 400:�ҽ� 401:��ũ
	int n,f,d; // F:FOOD D:DRINK N:COW
	scanf("%d %d %d",&n,&f,&d);
	
	// �ҽ��� ���� ���� 
	for(int i=0; i<f; i++)
	{
		adj[S].push_back(i+200);
		C[S][i+200] = 1;
	}
		
	// ��ũ�� ���� ���� 
	for(int i=0; i<d; i++)
	{
		adj[i+300].push_back(E);
		C[i+300][E] = 1;
	}
				
	// �� �ΰ��� ����
	for(int i=0; i<n; i++)
	{
		adj[2*i].push_back(2*i+1);
		C[2*i][2*i+1] = 1;
	}
		
 
	for(int i=0; i<n; i++)
	{
		int F_cnt,D_cnt;
		scanf("%d %d",&F_cnt,&D_cnt);
		// ���İ� �� ���� 
		for(int j=0; j<F_cnt; j++)
		{
			int w;
			scanf("%d",&w);
			w += 199; 
			adj[w].push_back(2*i);
			C[w][2*i] = 1;
			//printf("%d�� %d ����\n",w,2*i);
		}
		// ����� �� ����
		for(int j=0; j<D_cnt; j++)
		{
			int w;
			scanf("%d",&w);
			w += 299; 
			adj[2*i+1].push_back(w);
			C[2*i+1][w] = 1;
			//printf("%d�� %d ����\n",2*i+1,w);
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
