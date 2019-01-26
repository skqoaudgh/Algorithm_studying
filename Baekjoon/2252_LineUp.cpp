#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 32001

int main()
{
	vector<int> adj[MAX];
	queue<int> q;
	int in[MAX],ans[MAX];
	int N,M,idx=0;
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		in[b] ++;
	}
	for(int i=1; i<=N; i++)
		if(in[i] == 0)
			q.push(i);
	
	for(int i=0; i<N; i++)
	{
		int curr = q.front();
		q.pop();
		ans[idx++] = curr;
		for(int next: adj[curr])
		{
			in[next] --;
			if(in[next] == 0)
				q.push(next);
		}
	}
	
	for(int i=0; i<N; i++)
		printf("%d\n",ans[i]);
	return 0;
}
