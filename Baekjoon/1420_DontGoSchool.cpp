#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>
#include <cmath>
#include <map>
#include <functional>

#define MAX_N 20002
#define INF 987654321
using namespace std;

char arr[101][101];
vector<int> adj[MAX_N];
map<pair<int, int>, int> cMap;
map<pair<int, int>, int> fMap;

int main()
{
	int n, m;
	int S = -1, T = -1, cnt = 0;
	int sx, sy, tx, ty;
	scanf("%d %d", &n, &m);

	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &arr[i][j]);

			if (arr[i][j] == 'K')
			{
				S = cnt + 1;
				sx = j;
				sy = i;
			}
			else if (arr[i][j] == 'H')
			{
				T = cnt;
				tx = j;
				ty = i;
			}
			cnt += 2;
		}
		getchar();
	}


	if ((n == 1 && m == 1) || S == -1 || T == -1 || abs(sx - tx) + abs(sy - ty) == 1)
	{
		printf("-1\n");
		return 0;
	}

	// 정점을 2개로 쪼갠다.
	for (int i = 0; i < n * m; i++)
	{
		// in :: 0, 2, 4 ... out :: 1, 3, 5 ...
		cMap[{2 * i, 2 * i + 1}] = 1;
		adj[2 * i].push_back(2 * i + 1); 
		
		cMap[{2 * i + 1, 2 * i}] = 0;
		adj[2 * i + 1].push_back(2 * i);
	}

	// 간선 연결 작업(왼쪽 위부터 오른쪽 아래로 작업)
	int from = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (j + 1 < m && arr[i][j] != '#' && arr[i][j + 1] != '#')
			{
				int to = from + 2;
				cMap[{from + 1, to}] = INF;
				cMap[{to, from + 1}] = 0;

				cMap[{to + 1, from}] = INF;
				cMap[{from, to + 1}] = 0;

				adj[from + 1].push_back(to);
				adj[to].push_back(from + 1);

				adj[to + 1].push_back(from);
				adj[from].push_back(to + 1);
			}
			if (i + 1 < n && arr[i][j] != '#' && arr[i + 1][j] != '#')
			{
				int to = 2 * m + from;
				cMap[{from + 1, to}] = INF;
				cMap[{to, from + 1}] = 0;

				cMap[{to + 1, from}] = INF;
				cMap[{from, to + 1}] = 0;

				adj[from + 1].push_back(to);
				adj[to].push_back(from + 1);

				adj[to + 1].push_back(from);
				adj[from].push_back(to + 1);
			}
			from += 2;
		}
	int totalFlow = 0;
	// 증가 경로를 못 찾을 때까지
	while (1)
	{
		int prev[MAX_N];
		memset(prev, -1, sizeof(prev));
		
		queue<int> q;
		q.push(S);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++)
			{
				int next = adj[cur][i];
				if (prev[next] != -1)
					continue;
				if (cMap[{cur, next}] - fMap[{cur, next}] > 0)
				{
					q.push(next);
					prev[next] = cur;
					if (next == T)
						break;
				}
			}
		}
		if (prev[T] == -1)
			break;

		for (int i = T; i != S; i = prev[i])
		{
			fMap[{prev[i], i}] += 1;
			fMap[{i, prev[i]}] -= 1;
		}
		totalFlow += 1;
	}
	printf("%d\n", totalFlow);
	return 0;
}
