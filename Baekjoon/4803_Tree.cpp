#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int idx = 0;
	while(++idx)
	{
		int n,m;
		int tree_count = 0;
		vector<int> adj[501];
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0) break;
		for(int i=0; i<m; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	
		bool visited[501];
		fill(visited,visited+501,false);
		for(int i=1; i<=n; i++)
		{			
			int vertex = 0;
			int edge = 0;
			if(!visited[i])
			{
				tree_count ++;
				queue<int> q;
				q.push(i);
				
				while(!q.empty())
				{
					int curr = q.front();
					q.pop();
					if(visited[curr]) continue;
					vertex ++;
					visited[curr] = true;
					for(int next: adj[curr])
					{
						visited[next] = true;
						q.push(next);
						edge ++;
					}
				}
				if(edge/2 != vertex-1)
					tree_count --;	
				
				vertex = 0;
				edge = 0;									
			}
		}
		
		if(tree_count >= 2)
			printf("Case %d: A forest of %d trees.\n",idx,tree_count);
		else if(tree_count == 1)
			printf("Case %d: There is one tree.\n",idx);
		else
			printf("Case %d: No trees.\n",idx);
	}
	return 0;
}
