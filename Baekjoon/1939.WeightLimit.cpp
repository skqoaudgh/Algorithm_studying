#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int start_node,last_node,max_cost = 0;

struct NODE {
	int index, weight;
	NODE(int _idx, int _weight) {index=_idx;weight=_weight;};
};

vector<NODE> arr[10001];
bool visited[10001];

bool bfs(int cost)
{
	queue<int> q;
	q.push(start_node);
	visited[start_node] = true;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (t == last_node)
			return true;

		for (int i = 0; i < arr[t].size(); i++)
		{
			int next = arr[t][i].index;
			int nextCost = arr[t][i].weight;
			if (!visited[next] && cost <= nextCost)
			{
				visited[next] = true;
				q.push(next);
			}
		}	
	}
    return false;
}
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		arr[a].push_back(NODE(b,c));
		arr[b].push_back(NODE(a,c));
		if(max_cost < c)
			max_cost = c;
	}
	cin >> start_node >> last_node;
	
	int left = 0;
	int right = max_cost;
	while(left <= right)
	{
		for(int i=1; i<=N; i++)
			visited[i] = false;
		int mid = (left+right)/2;
		if(bfs(mid))
			left = mid+1;
		else
			right = mid-1;
	}
	cout << right;
	return 0;
}
