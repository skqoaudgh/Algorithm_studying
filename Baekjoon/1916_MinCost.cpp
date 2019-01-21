#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 1000;
const int INF = 1000000000;
typedef pair<int, int> P;
 
int main()
{
    int N,M,S,E;
    vector<P> adj[MAX_V];
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++)
	{
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(v-1, w));
    }
    scanf("%d %d",&S,&E);
    S--; E--;
    
    int dist[MAX_V];
    fill(dist,dist+MAX_V,INF);
    bool visited[MAX_V] = {false};
    
    priority_queue<P, vector<P>, greater<P>> PQ;
    dist[S] = 0;
    PQ.push(P(0,S));
    while(!PQ.empty())
    {
    	int curr;
    	do {
    		curr = PQ.top().second;
    		PQ.pop();
		} while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		
		for(auto &p : adj[curr])
		{
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d)
			{
				dist[next] = dist[curr]+d;
				PQ.push(P(dist[next],next));
			}
		}
	}
    
    printf("%d",dist[E]);
    return 0;
}
