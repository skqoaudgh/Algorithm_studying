#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const int INF = 1000000000;

int N, A[MAX], B[MAX]; // A[i], B[i]: �׷��� i�� ������ ��Ī�� ����� �׷� ���� ��ȣ
int dist[MAX]; // dist[i]: (A�׷���) i�� ������ ����(?)
bool used[MAX]; // used: (A�׷���) �� ������ ��Ī�� ���� �ִ°�?
vector<int> adj[MAX];

// A�׷��� ������ �ű�� ���� �Լ�
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

// ��Ī�� ã���� used�� true�� ����. 
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
    while(scanf("%d", &N) > 0)
	{
        // �׷��� ���� �Է¹ޱ�
        for(int i=0; i<N; i++)
        {
            int job, J;
            scanf("%d: (%d)", &job, &J);
            for(int j=0; j<J; j++)
			{
                int server;
                scanf("%d", &server);
                adj[job].push_back(server-N);
            }
        }
 
        // ȣ��ũ����Ʈ ī�� �˰���
        int match = 0;
        fill(A, A+MAX, -1);
        fill(B, B+MAX, -1);
        while(1)
		{
            // �� ������ ������ �ű�� ����
            bfs();
 
            // �̺� ��Ī�� ����ϰ� A�׷� ������ ��ȸ�ϸ� ��Ī ������ ã��
            int flow = 0;
            for(int i=0; i<N; i++)
                if(!used[i] && dfs(i)) flow++;
 
            // �� �̻� ���� ��θ� �� ã���� �˰��� ����
            if(flow == 0) break;
            // ã���� ��� �ݺ�
            match += flow;
        }
        // ��� ���
        printf("%d\n", match);
 
        // �׽�Ʈ ���̽��� ���� ���̹Ƿ� �ʱ�ȭ�ϴ� �κ�
        fill(used, used+MAX, false);
        for(int i=0; i<N; i++)
            adj[i].clear();
    }
	return 0;
}
