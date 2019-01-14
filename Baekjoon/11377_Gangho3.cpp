#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2001

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
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		for(int u=0; u<a; u++)
		{		
			int w;
			scanf("%d",&w);
			adj[i].push_back(w-1);
			adj[i+1000].push_back(w-1);
		}
	}
	
	fill(A,A+N+1000,-1);
	fill(B,B+M,-1);
	int match1 = 0;
	for(int i=0; i<N; i++)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i)) 
				match1 ++;
		}			
	}

	int match2 = 0;
	for(int i=1000; i<N+1000; i++)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i))
			{
				match2 ++;
				if(match2 == K)
					break;
			}
		}			
	}	
	printf("%d",match1+match2);
	return 0;
}
