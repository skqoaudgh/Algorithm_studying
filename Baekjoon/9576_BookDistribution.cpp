#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_VERTEX 1001

bool visited[1001];
int A[1001];
int B[1001];
vector<int> adj[MAX_VERTEX];

bool dfs(int a)
{
	visited[a] = true;
	for(int b : adj[a])
	{
		if(B[b] == -1 || (!visited[B[b]] && dfs(B[b])))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0; i<MAX_VERTEX; i++)
			adj[i].clear();
		int N,M;
		scanf("%d %d",&N,&M);
		for(int i=0; i<M; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			for(int j=a; j<=b; j++)
				adj[i].push_back(j-1);
		}
		
		int match = 0;
		fill(A,A+M,-1);
		fill(B,B+N,-1);
		for(int i=0; i<M; i++)
		{
			if(A[i] == -1)
			{
				fill(visited,visited+M,false);
				if(dfs(i)) match ++;
			}
		}
		printf("%d\n",match);
	}
	return 0;
}
