#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 26

int A[MAX];
int B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

bool dfs(int a)
{
	visited[a] = true;
	for(int b: adj[a])
	{
		if(B[b] == -1 || (!visited[B[b]] && dfs(B[b])))
		{
			B[b] = a;
			A[a] = b;
			return true;
		}
	}
	return false;
}

bool isPrime(int num)
{
	for(int i=2; i<num; i++)
		if(num%i == 0)
			return false;
	return true;	
}

int main()
{
	int N;
	vector<int> AA,BB;
	bool flag = false;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int w;
		scanf("%d",&w);
		if(i == 0 && w%2 == 1) flag = true;
		(w%2?BB:AA).push_back(w); // A=Â¦¼ö B=È¦¼ö
	}
	
	if(AA.size() != BB.size())
	{
		printf("-1");
		return 0;
	}
	
	if(flag)
		swap(AA,BB);
	
	int size = AA.size();
	for(int a=0; a<size; a++)
	{
		for(int b=0; b<size; b++)
		{
			if(isPrime(AA[a] + BB[b]))
				adj[a].push_back(b);
		}
	}
	
	vector<int> result;
	for(int i: adj[0])
	{
		int match = 1;
		fill(A,A+MAX,-1);
		fill(B,B+MAX,-1);
		A[0] = i;
		B[i] = 0;
		for(int j=1; j<AA.size(); j++)
		{
			if(A[j] == -1)
			{
				fill(visited,visited+MAX,false);
				visited[0] = true;
				if(dfs(j))
					match ++;
			}
		}
		if(match == size)
			result.push_back(BB[i]);
	}
	if(result.empty())
		printf("-1");
	else
	{
		sort(result.begin(),result.end());
		for(int i: result)
			printf("%d ",i);		
	}

	return 0;
}
