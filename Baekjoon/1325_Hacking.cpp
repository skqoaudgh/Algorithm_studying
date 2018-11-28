#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[10002];
bool visited[10002];
bool ans[10002];

struct NODE {
	int idx, start;
	NODE(int _start, int _idx) {start=_start;idx=_idx;};
};

void clearAns(int N)
{
	for(int i=0; i<N; i++)	
		ans[i] = false;
}

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b; // b를 해킹하면 a까지 해킹 가능 
		arr[b-1].push_back(a-1);
	}
	
	queue<NODE> q;
	int max_cnt = 0;	
	for(int i=0; i<N; i++)
	{
		int cnt = 0;
		for(int y=0; y<N; y++)
			visited[y] = false;
			
		visited[i] = true;
		q.push(NODE(i,i));
		while(!q.empty())
		{
			NODE t = q.front();
			q.pop();
			
			for(int p=0; p<arr[t.idx].size(); p++)
			{
				int next = arr[t.idx][p];
				if(visited[next]) continue;
				visited[next] = true;
				q.push(NODE(t.start,next));
				cnt ++;
			}	
		}
		
		if(max_cnt < cnt)
		{
			clearAns(N);
			ans[i] = true;
			max_cnt = cnt;
		}
		else if(max_cnt == cnt && cnt > 0)
			ans[i] = true;
	}
	
	for(int i=0; i<N; i++)
		if(ans[i])
			cout << i+1 << ' ';
	return 0;
}
