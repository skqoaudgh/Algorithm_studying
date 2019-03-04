#include <cstdio>
#include <iostream>
using namespace std;

typedef pair<int,int> P;

P child[10001]; // left child, right child
P position[10001]; // level, col
int visited[10001], count[10001];
int mins[10001], maxs[10001];
int root, col=1;
long long int maxvalue,maxlevel,sum=0;

void dfs(int node, int level)
{
	if(child[node].first > 0)
		dfs(child[node].first, level + 1);
	
	position[node].first = level;
	position[node].second = col;
	
	if(mins[position[node].first] > position[node].second)
		mins[position[node].first] = position[node].second;
		
	if(maxs[position[node].first] < position[node].second)
		maxs[position[node].first] = position[node].second;	
		
	col ++;
	
	if(child[node].second > 0)
		dfs(child[node].second, level + 1);	
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		int node, left, right;
		scanf("%d %d %d",&node,&left,&right);
		child[node] = P(left,right);
		if(left > -1)
			count[left] ++;
		if(right > -1)
			count[right] ++;
	}
	for(int i=0; i<=N; i++)
		mins[i] = 987654321;
	
	for(int i=1; i<=N; i++)
		if(count[i] == 0)
			root = i;
	
	dfs(root, 1);
	
	for(int i=1; i<=N; i++)
	{
		sum = maxs[i] - mins[i] + 1;
		if(maxvalue < sum)
		{
			maxvalue = sum;
			maxlevel = i;
		}
	}
	printf("%lld %lld",maxlevel,maxvalue);
	return 0;
}
