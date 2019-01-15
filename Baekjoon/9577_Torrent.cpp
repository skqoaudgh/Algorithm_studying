#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 102

vector<int> adj[MAX];
int A[MAX];
int B[MAX];
bool visited[MAX];

bool dfs(int a)
{
	visited[a] = true;
	for(int b: adj[a])
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
		for(int i=0; i<MAX; i++)
			adj[i].clear();
			
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0; i<m; i++)
		{
			int t1,t2,a;
			scanf("%d %d %d",&t1,&t2,&a);
			for(int j=0; j<a; j++)
			{
				int w;
				scanf("%d",&w);
				for(int t=t1+1; t<=t2; t++)
					adj[t].push_back(w);	
			}
		}
		
		int match = 0;
		bool flag = false;
		fill(A,A+MAX,-1);
		fill(B,B+MAX,-1);
		for(int i=0; i<=101; i++)
		{
			if(A[i] == -1)
			{
				fill(visited,visited+MAX,false);
				if(dfs(i)) 
				{
					match++;
					if(match == n)
					{
						printf("%d\n",i);
						flag = true;
					}
				}
			}	
		}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}
