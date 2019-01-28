#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100000];
bool visited[100000];
int parent[100000];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N-1; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a --;
		b --;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int next: adj[curr])
		{
			if(visited[next]) continue;
			visited[next] = true;
			parent[next] = curr;
			q.push(next);
		}
	}
	
	for(int i=1; i<N; i++)
		printf("%d\n",parent[i]+1);
	return 0;
}
