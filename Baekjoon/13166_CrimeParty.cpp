#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 400002;
const int INF = 1000000000;

int N, A[MAX], B[MAX]; // A[i], B[i]: �׷��� i�� ������ ��Ī�� ����� �׷� ���� ��ȣ
int dist[MAX]; // dist[i]: (A�׷���) i�� ������ ����(?)
bool used[MAX]; // used: (A�׷���) �� ������ ��Ī�� ���� �ִ°�?
vector< pair<int,int> > adj[MAX];

// A�׷��� ������ �ű�� ���� �Լ�
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

// ��Ī�� ã���� used�� true�� ����.
// �̺и�Ī�� dfs �˰���� ����������, dist ������ �߰��� 
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
        // �� ������ ������ �ű�� ����
        bfs(cost);

        // �̺� ��Ī�� ����ϰ� A�׷� ������ ��ȸ�ϸ� ��Ī ������ ã��
        int flow = 0;
        for(int i=1; i<=N; i++)
            if(!used[i] && dfs(i,cost)) flow++;

        // �� �̻� ���� ��θ� �� ã���� �˰��� ����
        if(flow == 0) break;
        // ã���� ��� �ݺ�
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

    // ȣ��ũ����Ʈ ī�� �˰���
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
