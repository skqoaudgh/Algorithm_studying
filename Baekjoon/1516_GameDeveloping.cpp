#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501

int main()
{
	vector<int> adj[MAX];
	queue<int> q;
	int time[MAX],in[MAX],result[MAX];
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d",&time[i]);
		while(1)
		{
			int prev;
			scanf("%d",&prev);
			if(prev == -1) break;
			adj[prev].push_back(i);
			in[i] ++;
		}
		if(in[i] == 0)
		{
			result[i] = time[i];
			q.push(i);
		}
			
	}
	
	for(int i=0; i<N; i++)
	{
		if(q.empty()) break;
		int curr = q.front();
		q.pop();
		for(int next: adj[curr])
		{
			result[next] = max(result[next],result[curr]+time[next]);
			in[next] --;
			if(in[next] == 0)
				q.push(next);
		}
	}
	
	for(int i=1; i<=N; i++)
		printf("%d\n",result[i]);
	return 0;
}
