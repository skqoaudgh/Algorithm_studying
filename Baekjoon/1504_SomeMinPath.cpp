#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 800;
const int INF = 800000;
typedef pair<int, int> P;

vector<P> adj[MAX_V];

void func(int S, int* dist, bool* visited)
{
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
}
int main()
{
    int N,E;
    scanf("%d %d", &N, &E);
    for(int i=0; i<E; i++)
	{
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(v-1, w));
        adj[v-1].push_back(P(u-1, w));
    }
    int a,b;
    scanf("%d %d",&a,&b);
    a--; 
	b--;
    
    int dist[MAX_V];
    bool visited[MAX_V];
    int start[] = {0,a,b};
    int end[] =   {a,b,N-1,b,a,N-1};
    int sum_ab = 0, sum_ba = 0;
	bool flag[2] = {false};
	
	fill(dist,dist+MAX_V,INF);
	fill(visited,visited+MAX_V,false);
	func(0,dist,visited);
	if(dist[a] == INF)
		flag[0] = true;
	if(dist[b] == INF)
		flag[1] = true;		
	sum_ab += dist[a];
	sum_ba += dist[b];

	fill(dist,dist+MAX_V,INF);
	fill(visited,visited+MAX_V,false);
	func(a,dist,visited);
	if(dist[a] == INF)
		flag[0] = true;
	if(dist[b] == INF)
		flag[1] = true;			
	sum_ab += dist[b];
	sum_ba += dist[N-1];
		
	fill(dist,dist+MAX_V,INF);
	fill(visited,visited+MAX_V,false);
	func(b,dist,visited);
	if(dist[a] == INF)
		flag[0] = true;
	if(dist[b] == INF)
		flag[1] = true;			
	sum_ab += dist[N-1];
	sum_ba += dist[a];
		
	if(flag[0] && flag[1])
		printf("-1");
	else
		printf("%d",(sum_ab<sum_ba)?sum_ab:sum_ba);
    return 0;
}
