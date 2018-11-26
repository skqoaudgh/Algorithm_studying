#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];

struct NODE {
	int idx, cnt;
	NODE(int _idx, int _cnt) {idx=_idx; cnt=_cnt;};
};
int getBaconNumber(int index, int dest)
{
	bool visited[101];
	for(int i=0; i<N; i++)
		visited[i] = false;

	int res = 987654321;
	queue<NODE> q;
	q.push(NODE(index,0));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		if(t.idx == dest)
		{
			if(res > t.cnt)
				res = t.cnt;
		}
		
		for(int i=0; i<N; i++)
		{
			if(i == t.idx) continue;
			if(visited[i]) continue;
			if(arr[i][t.idx] == 1) 
			{
				visited[i] = true;
				q.push(NODE(i,t.cnt+1));
			}
		}
	}
	if(res == 987654321)
		res = 0;
	return res;
}

int main()
{
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a-1][b-1] = 1;
		arr[b-1][a-1] = 1;
	}
	
	int idx = 0;
	int min = 987654321;
	int sum = 0;
	for(int i=0; i<N; i++)
	{
		sum = 0;
		for(int j=0; j<N; j++)
		{
			if(i==j) continue;
			int temp = getBaconNumber(i,j);
			sum += temp;
		}
		if(min > sum)
		{
			min = sum;
			idx = i;
		}
	}
	cout << idx+1;
	return 0;
}
