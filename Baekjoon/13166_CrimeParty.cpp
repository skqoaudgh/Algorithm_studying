#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 400002;
const int INF = 1000000000;

int N, A[MAX], B[MAX]; // A[i], B[i]: 그룹의 i번 정점과 매칭된 상대편 그룹 정점 번호
int dist[MAX]; // dist[i]: (A그룹의) i번 정점의 레벨(?)
bool used[MAX]; // used: (A그룹의) 이 정점이 매칭에 속해 있는가?
vector< pair<int,int> > adj[MAX];

// A그룹의 레벨을 매기기 위한 함수
bool bfs(int cost)
{
	queue<int> q;
	for(int i=1; i<=N; i++)
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
		for(pair<int,int> b: adj[a])
		{
			if(b.second <= cost && B[b.first] != -1 && dist[B[b.first]] == INF)
			{
				dist[B[b.first]] = dist[a]+1;
				q.push(B[b.first]);
			}
		}
	}
} 

// 매칭을 찾으면 used를 true로 만듬.
// 이분매칭의 dfs 알고리즘과 유사하지만, dist 조건이 추가됨 
bool dfs(int a, int cost)
{
	for(pair<int,int> b: adj[a])
	{
		int bid = b.first;
		int bcost = b.second;
		if(bcost <= cost && (B[bid] == -1 || dist[B[bid]] == dist[a]+1 && dfs(B[bid],cost)))
		{
			used[a] = true;
			A[a] = bid;
			B[bid] = a;
			return true;
		}
	}
	return false;
}

bool flow_count(int cost)
{
	int match = 0;
    fill(A, A+MAX, -1);
    fill(B, B+MAX, -1);
	fill(used,used+MAX,false);
	fill(dist,dist+MAX,-1);
    while(1)
	{
        // 각 정점에 레벨을 매기고 시작
        bfs(cost);

        // 이분 매칭과 비슷하게 A그룹 정점을 순회하며 매칭 증가량 찾음
        int flow = 0;
        for(int i=1; i<=N; i++)
            if(!used[i] && dfs(i,cost)) flow++;

        // 더 이상 증가 경로를 못 찾으면 알고리즘 종료
        if(flow == 0) break;
        // 찾았을 경우 반복
        match += flow;
    }
    return (match == N);
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
    {
    	int a,ak,b,bk;
    	scanf("%d %d %d %d",&a,&ak,&b,&bk);
    	adj[i].push_back(make_pair(a+N,ak));
    	adj[i].push_back(make_pair(b+N,bk));
	}

    // 호프크로프트 카프 알고리즘
    int left = 0;
    int right = 1000000;
    int mid;
   	while(left <= right)
   	{
    	mid = (left+right)/2;
    	if(flow_count(mid))
    		right = mid-1;
    	else
    		left = mid+1;
	}
	if(left > 1000000)
		left = -1;
	printf("%d",left);
	return 0;
}
