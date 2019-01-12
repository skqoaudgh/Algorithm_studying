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
	int N;										// ������ �� 
	int capacity[MAX_VERTEX][MAX_VERTEX] = {0}; // �뷮 
	int flow[MAX_VERTEX][MAX_VERTEX] = {0};		// ���� 
	vector<int> adj[MAX_VERTEX]; 				// ��������Ʈ
	
	scanf("%d",&N); 
	for(int i=0; i<N; i++)
	{
		char u,v;
		int w;
		scanf(" %c %c %d",&u,&v,&w);
		u = CtoI(u);
		v = CtoI(v);
		capacity[u][v] = capacity[v][u] += w; // ���� ������ �Էµ� �� �����Ƿ� ( += ) ��� 
		adj[u].push_back(v);
		adj[v].push_back(u); // ������ ������ �Բ� �߰����־�� �Ѵ�. 
	} 
	
	int total = 0, Source = CtoI('A'), End = CtoI('Z');
	while(1) 
	{
		int prev[MAX_VERTEX]; // ��� ������ ���� �迭 prev[a] = b -> b�� ������ a�� ��
		memset(prev, -1, sizeof(prev));
		queue<int> Q;
		Q.push(Source);
		while(!Q.empty() && prev[End] == -1) // Q�� ������� �ʰ� ���� End�� �������� �ʾ��� ������ ��� �ݺ�. -> ���� ��� ã��
		{
			int current = Q.front();
			Q.pop();
			for(int next: adj[current]) // current�� �������ִ� ��� �˻� 
			{
				// ���� ������ �뷮�� ���� �ʾҰ� ���� next�� �湮���� �ʾ��� �� 
				if(capacity[current][next] - flow[current][next] > 0 && prev[next] == -1)
				{
					Q.push(next);
					prev[next] = current;
					if(next == End) break; // End��� ���� �� ���� 
				}
			}	
		}
		if(prev[End] == -1) break; // End�� �������� ������ �� Ż��
		
		int sum = INF;
		for(int i=End; i!=Source; i=prev[i]) // End���� Source�� �������� ��� ��ȸ�Ͽ� ���� ���� ������ ã�� 
			sum = min(sum,capacity[prev[i]][i]-flow[prev[i]][i]);
		for(int i=End; i!=Source; i=prev[i])
		{
			flow[prev[i]][i] += sum;
			flow[i][prev[i]] -= sum; // �������� �������� ��ȣ �ݴ� 
		}
		total += sum;
	}
	printf("%d",total);
	return 0;
}
