#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
const int INF = 1000000000;

int N, A[MAX], B[MAX]; // A[i], B[i]: 그룹의 i번 정점과 매칭된 상대편 그룹 정점 번호
int dist[MAX]; // dist[i]: (A그룹의) i번 정점의 레벨(?)
bool used[MAX]; // used: (A그룹의) 이 정점이 매칭에 속해 있는가?
vector<int> adj[MAX];

// A그룹의 레벨을 매기기 위한 함수
bool bfs()
{
	queue<int> q;
	for(int i=0; i<N; i++)
	{
		if(!used[i])
		{
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = INF;
	}
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for(int b: adj[a])
		{
			if(B[b] != -1 && dist[B[b]] == INF)
			{
				dist[B[b]] = dist[a]+1;
				q.push(B[b]);
			}
		}
	}
} 

// 매칭을 찾으면 used를 true로 만듬.
// 이분매칭의 dfs 알고리즘과 유사하지만, dist 조건이 추가됨 
bool dfs(int a)
{
	for(int b: adj[a])
	{
		if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b]))
		{
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
    	int a,b;
    	scanf("%d %d",&a,&b);
    	adj[i].push_back(a);
    	adj[i].push_back(b);
	}

    // 호프크로프트 카프 알고리즘
    int match = 0;
    fill(A, A+MAX, -1);
    fill(B, B+MAX, -1);
    while(1)
	{
        // 각 정점에 레벨을 매기고 시작
        bfs();

        // 이분 매칭과 비슷하게 A그룹 정점을 순회하며 매칭 증가량 찾음
        int flow = 0;
        for(int i=0; i<N; i++)
            if(!used[i] && dfs(i)) flow++;

        // 더 이상 증가 경로를 못 찾으면 알고리즘 종료
        if(flow == 0) break;
        // 찾았을 경우 반복
        match += flow;
        if(match == N) break;
    }
    // 결과 출력
    if(match < N)
    	printf("-1");
    else
    	for(int i=0; i<N; i++)
    		printf("%d\n",A[i]);
	return 0;
}
