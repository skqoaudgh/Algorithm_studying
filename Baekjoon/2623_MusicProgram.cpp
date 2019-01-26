#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	queue<int> q;
	vector<int> ans;
	vector<int> adj[1001];
	int in[1001],out[1001];
	int N,M;
	scanf("%d %d",&N,&M);
	
	fill(in,in+N+1,0);
	fill(out,out+N+1,0);
	for(int i=0; i<M; i++)
	{
		int cnt, prev=0, curr;
		scanf("%d",&cnt);
		for(int i=0; i<cnt; i++)
		{
			scanf("%d",&curr);
			if(prev != 0)
			{
				in[curr] ++;
				adj[prev].push_back(curr);
			}
			prev = curr;
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(in[i] == 0)
			q.push(i);
	}
	for(int i=0; i<N; i++)
	{
		if(q.empty())
			break;
		int curr = q.front();
		ans.push_back(curr);
		q.pop();
		
		for(int a: adj[curr])
		{
			in[a] --;
			if(in[a] == 0)
				q.push(a);			
		}	
	}
	
	int size = ans.size();
	if(size < N)
		printf("0");
	else
		for(int i=0; i<size; i++)
			printf("%d\n",ans[i]);
	return 0;
}
