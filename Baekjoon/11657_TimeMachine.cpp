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
	int N,M,dist[MAX];
	vector<P> adj[MAX];
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		adj[A-1].push_back(P(B-1,C));
	}
	
	fill(dist,dist+N,INF);
	dist[0] = 0;
	bool flag = false;
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
					if(i == N-1)
						flag = true; 
				}
					
			}
		}
	}
	if(flag)
		puts("-1");
	else
		for(int i=1; i<N; i++)
			printf("%d\n",dist[i]==INF?-1:dist[i]);
	return 0;
}
