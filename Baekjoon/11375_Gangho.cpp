#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

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
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		for(int u=0; u<a; u++)
		{		
			int w;
			scanf("%d",&w);
			adj[i].push_back(w-1);
		}
	}
	
	fill(A,A+N,-1);
	fill(B,B+M,-1);
	int match = 0;
	for(int i=0; i<N; i++)
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
