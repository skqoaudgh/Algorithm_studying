#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 10000;
const int INF = 30000;
typedef pair<int, int> P;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main()
{
	int arr[100][100];
	int N,M;
	scanf("%d %d",&M,&N);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d",&arr[i][j]);
			
    vector<P> adj[MAX_V];
    for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			for(int t=0; t<4; t++)
			{
				int nx = i+dx[t];
				int ny = j+dy[t];
				if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				adj[M*i+j].push_back(P(M*nx+ny, arr[nx][ny]));
			}
		}
    }
    
    int dist[MAX_V];
    fill(dist,dist+MAX_V,INF);
    bool visited[MAX_V] = {false};
    
    priority_queue<P, vector<P>, greater<P>> PQ;
    dist[0] = 0;
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
    printf("%d",dist[M*(N-1)+M-1]);
    return 0;
}
