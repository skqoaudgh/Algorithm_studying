#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vector<int> adj[MAX];
		queue<int> q;
		int in[MAX],ans[MAX];		
		int time[MAX],result[MAX];		
		int N,K,W;
		scanf("%d %d",&N,&K);
		for(int i=1; i<=N; i++)
		{
			scanf("%d",&time[i]);
			result[i] = time[i];
		}
			
		for(int i=0; i<K; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			in[b] ++;
		}
		scanf("%d",&W);
		
		for(int i=1; i<=N; i++)
			if(in[i] == 0)
				q.push(i);
				
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
		printf("%d\n",result[W]);
	}
	return 0;
}
