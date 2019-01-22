#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 200000000;
const int MAX = 100;
vector<P> adj[MAX];

bool IsPossible(int S, int E)
{
	bool visited[MAX] = {false};
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(curr == E) return true;
		for(auto &p: adj[curr])
		{
			int next = p.first;
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return false;
}

int main()
{
	int N,M,S,E;
	long long int price[MAX],dist[MAX];
	scanf("%d %d %d %d",&N,&S,&E,&M);
	for(int i=0; i<M; i++)
	{
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		adj[A].push_back(P(B,C));
	}
	for(int i=0; i<N; i++)
		scanf("%d",&price[i]);
		
	fill(dist,dist+N,INF);
	dist[S] = -price[S];
	bool flag = false;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(auto &p: adj[j])
			{
				int d = p.second;
				int next = p.first;
				if(dist[j] != INF && dist[next] > dist[j] + d - price[next])
				{
					dist[next] = dist[j]+d-price[next];
					if(i == N-1 && IsPossible(j, E))
					{
						flag = true;
					}	
				}	
			}
		}
	}
	
	if(!IsPossible(S, E))
		printf("gg");
	else if(flag)
		printf("Gee");
	else
		printf("%d\n",-dist[E]);
	return 0;
}
