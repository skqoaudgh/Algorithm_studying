#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX	52
#define INF 		1000000000

int CtoI(const char c)
{
	if(c >= 'a' && c <= 'z')
		return c-'a'+26;
	return c-'A';	
}

int main()
{
	int N;										// 간선의 수 
	int capacity[MAX_VERTEX][MAX_VERTEX] = {0}; // 용량 
	int flow[MAX_VERTEX][MAX_VERTEX] = {0};		// 유량 
	vector<int> adj[MAX_VERTEX]; 				// 인접리스트
	
	scanf("%d",&N); 
	for(int i=0; i<N; i++)
	{
		char u,v;
		int w;
		scanf(" %c %c %d",&u,&v,&w);
		u = CtoI(u);
		v = CtoI(v);
		capacity[u][v] = capacity[v][u] += w; // 같은 간선이 입력될 수 있으므로 ( += ) 사용 
		adj[u].push_back(v);
		adj[v].push_back(u); // 역방향 간선도 함께 추가해주어야 한다. 
	} 
	
	int total = 0, Source = CtoI('A'), End = CtoI('Z');
	while(1) 
	{
		int prev[MAX_VERTEX]; // 경로 저장을 위한 배열 prev[a] = b -> b를 지나쳐 a로 옴
		memset(prev, -1, sizeof(prev));
		queue<int> Q;
		Q.push(Source);
		while(!Q.empty() && prev[End] == -1) // Q가 비어있지 않고 아직 End에 도달하지 않았을 때까지 계속 반복. -> 증가 경로 찾기
		{
			int current = Q.front();
			Q.pop();
			for(int next: adj[current]) // current와 인접해있는 노드 검사 
			{
				// 아직 유량이 용량을 넘지 않았고 아직 next에 방문하지 않았을 때 
				if(capacity[current][next] - flow[current][next] > 0 && prev[next] == -1)
				{
					Q.push(next);
					prev[next] = current;
					if(next == End) break; // End노드 도달 시 종료 
				}
			}	
		}
		if(prev[End] == -1) break; // End에 도달하지 못했을 시 탈출
		
		int sum = INF;
		for(int i=End; i!=Source; i=prev[i]) // End에서 Source로 역순으로 경로 순회하여 가장 적은 유량을 찾음 
			sum = min(sum,capacity[prev[i]][i]-flow[prev[i]][i]);
		for(int i=End; i!=Source; i=prev[i])
		{
			flow[prev[i]][i] += sum;
			flow[i][prev[i]] -= sum; // 역방향은 정방향의 부호 반대 
		}
		total += sum;
	}
	printf("%d",total);
	return 0;
}
