#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 1000000000;
const int MAX = 500;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M,W,dist[MAX];
		vector<P> adj[MAX];
		scanf("%d %d %d",&N,&M,&W);
		for(int i=0; i<M; i++)
		{
			int S,E,T;
			scanf("%d %d %d",&S,&E,&T);
			adj[S-1].push_back(P(E-1,T));
			adj[E-1].push_back(P(S-1,T));
		}
		for(int i=0; i<W; i++)
		{
			int S,E,T;
			scanf("%d %d %d",&S,&E,&T);
			adj[S-1].push_back(P(E-1,-T));			
		}
		
		bool flag = false;
		bool visited[MAX] = {false};
		for(int i=0; i<N; i++)
		{
			if(visited[i]) continue;
			fill(dist,dist+N,INF);
			dist[i] = 0;
			for(int i=0; i<N; i++) // 싸이클이 있는지 검사하기 위해 루프를 한 번더 실행 
			{
				for(int j=0; j<N; j++)
				{
					for(auto &p: adj[j])
					{
						int d = p.second;
						int next = p.first;
						if(dist[j] != INF && dist[next] > dist[j] + d)
						{
							dist[next] = dist[j]+d;
							visited[next] = true;
							if(i == N-1)
								flag = true; 
						}	
					}
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
