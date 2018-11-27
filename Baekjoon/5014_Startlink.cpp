#include <iostream>
#include <queue>
using namespace std;

bool visited[1000002];
int F,S,G,U,D; // F: 전체 층 수. S: 현재 있는 층. G: 목적지 층. U: 위로 몇 층 가는지. D: 아래로 몇 층 가는지 

struct NODE {
	int idx, cnt;
	NODE(int _idx, int _cnt) {idx=_idx; cnt=_cnt;};
};

int main()
{
	int move[2];
	int ans = 987654321;
	cin >> F >> S >> G >> U >> D;
	move[0] = U;
	move[1] = -D;
	
	queue<NODE> q;
	q.push(NODE(S,0));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		if(t.idx == G)
			if(ans > t.cnt)
				ans = t.cnt;
				
		for(int i=0; i<2; i++)
		{
			int nx = t.idx+move[i];
			if(nx<0 || nx>F) continue;
			if(visited[nx]) continue;
			visited[nx] = true;
			q.push(NODE(nx,t.cnt+1));
		}
	}
	if(ans == 987654321)
		cout << "use the stairs";
	else
		cout << ans;
	return 0;
}
