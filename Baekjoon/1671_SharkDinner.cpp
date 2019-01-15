#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51

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
	int N;
	int arr[MAX][3];
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
		
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(arr[i][0] >= arr[j][0] && arr[i][1] >= arr[j][1] && arr[i][2] >= arr[j][2])
				adj[i].push_back(j);
			else if(arr[j][0] >= arr[i][0] && arr[j][1] >= arr[i][1] && arr[j][2] >= arr[i][2])
				adj[j].push_back(i);	
		}
	}
		
	fill(A,A+MAX,-1);
	fill(B,B+MAX,-1);
	int match = 0;
	for(int i=0; i<N; i++)
	{
		if(A[i] == -1)
		{
			fill(visited,visited+MAX,false);
			if(dfs(i))
				match ++;
			fill(visited,visited+MAX,false);
			if(dfs(i))
				match ++;	
		}
	}		
	printf("%d\n",N-match);
	return 0;
}
