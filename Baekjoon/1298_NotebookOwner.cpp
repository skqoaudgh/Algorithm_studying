#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 200

int A[MAX];
int B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

bool dfs(int a)
{
	visited[a] = true;
	for(int b: adj[a])
	{
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			B[b] = a;
			A[a] = b;
			return true;
		}
	}
	return false;
}
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
	}
	
	fill(A+1,A+N+1,-1);
	fill(B+1,B+N+1,-1);
	int match = 0;
	for(int i=1; i<=N; i++)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i)) match ++;
		}
	}
	printf("%d",match);
	return 0;
}
