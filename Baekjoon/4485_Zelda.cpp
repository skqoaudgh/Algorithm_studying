#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 15625;
const int INF = 2000;
typedef pair<int, int> P;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main()
{
	int arr[126][126];
	int idx = 1;
	while(1)
	{
		int N;
		scanf("%d",&N);
		if(N == 0) break;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%d",&arr[i][j]);
				
	    vector<P> adj[MAX_V];
	    for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int t=0; t<4; t++)
				{
					int nx = i+dx[t];
					int ny = j+dy[t];
					if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					adj[N*i+j].push_back(P(N*nx+ny, arr[nx][ny]));
				}
			}
	    }
	    
	    int dist[MAX_V];
	    fill(dist,dist+MAX_V,INF);
	    bool visited[MAX_V] = {false};
	    
	    priority_queue<P, vector<P>, greater<P>> PQ;
	    dist[0] = arr[0][0];
	    PQ.push(P(0,0));
	    while(!PQ.empty())
	    {
	    	int curr;
	    	do {
	    		curr = PQ.top().second;
	    		PQ.pop();
			} while(!PQ.empty() && visited[curr]);
			if(visited[curr]) break;
			
			visited[curr] = true;
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
	    printf("Problem %d: %d\n",idx++,dist[N*(N-1)+N-1]);
	}
    return 0;
}
