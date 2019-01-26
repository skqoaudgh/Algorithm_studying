#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101

vector<int> adj[MAX];
queue<int> q;
int in[MAX],ans[MAX];		
int need[MAX][MAX],cost[MAX][MAX];
int order[MAX];
	
int main()
{
	int N,M,idx=0;
	scanf("%d %d",&N,&M); 
	
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++)
			need[i][j] = 0;
			
	for(int i=0; i<M; i++)
	{
		int x,y,k;
		scanf("%d %d %d",&x,&y,&k);
		need[x][y] = k;
		adj[y].push_back(x);
		in[x] ++;
	}
	for(int i=1; i<=N; i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
			cost[i][i] = 1;
		}
	}
	for(int i=0; i<N; i++)
	{
		if(q.empty()) break;
		int curr = q.front();
		q.pop();
		order[idx++] = curr;
		for(int next: adj[curr])
		{
			for(int i=1; i<=N; i++)
				cost[next][i] += need[next][curr]*cost[curr][i];
			in[next] --;
			if(in[next] == 0)
				q.push(next);
		}
	}
    for (int i=1; i<=N; i++) 
	{
        if (cost[N][i])
            printf("%d %d\n",i,cost[N][i]);
    }
	return 0;
}
