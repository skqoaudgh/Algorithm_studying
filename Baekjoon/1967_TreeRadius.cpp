#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE {
	int idx, cnt;
	NODE(int _idx, int _cnt) { idx = _idx; cnt = _cnt; };
};

struct Lnode {
	int v, w;
	Lnode(int _v, int _w) { v = _v; w = _w; };
};

//int arr[10001][10001];
vector<Lnode> arr[10002];
bool visited[10002];

NODE getMaxLength(int root)
{
	NODE res(0,0);
	queue<NODE> q;
	q.push(NODE(root, 0));
	while (!q.empty())
	{
		NODE t = q.front();
		q.pop();

		if (res.cnt < t.cnt)
		{
			res.cnt = t.cnt;
			res.idx = t.idx;
		}
			

		for (int i = 0; i<arr[t.idx].size(); i++)
		{
			int u = arr[t.idx][i].v;
			if (!visited[u])
			{
				visited[u] = true;
				q.push(NODE(u, t.cnt + arr[t.idx][i].w));
			}
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i<N - 1; i++)
	{
		int A, B, W;
		cin >> A >> B >> W;
		arr[A - 1].push_back(Lnode(B - 1, W));
		arr[B - 1].push_back(Lnode(A - 1, W));
	}
	NODE node_from_root = getMaxLength(0);
	for (int i = 0; i < N; i++)
		visited[i] = false;
	NODE node_from_longest = getMaxLength(node_from_root.idx);
	cout << node_from_longest.cnt;
	return 0;
}
