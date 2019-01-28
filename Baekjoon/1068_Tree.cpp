#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N,M;
	int root;
	int cnt[51]={0};
	vector<int> adj[51];
	queue<int> q;
	bool visited[51]={false};
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		if(a != -1)
		{
			adj[a].push_back(i);
			adj[i].push_back(a);
		}
		else if(a == -1)
			root = i;
	}
	scanf("%d",&M);
	
	int ans = 0;
	q.push(root);
	visited[root] = true;
	while(!q.empty())
	{
		bool flag = false;
		int curr = q.front();
		q.pop();
		for(int next: adj[curr])
		{
			if(visited[next] || next == M) continue;
			visited[next] = true;
			q.push(next);
			flag = true;
		}
		if(!flag && root != M)
			ans ++;
	}
	printf("%d",ans);
	return 0;
}
