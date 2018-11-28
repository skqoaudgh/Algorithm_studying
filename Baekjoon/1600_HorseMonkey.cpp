#include <iostream>
#include <queue>
using namespace std;

int arr[201][201];
bool visited[201][201][31];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int ndx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ndy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct NODE {
	int x,y,cnt,k;
	NODE(int _x, int _y, int _cnt, int _k) {x=_x,y=_y;cnt=_cnt;k=_k;};
};

int main()
{
	int K,W,H;
	cin >> K >> W >> H;
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			cin >> arr[i][j];

	int ans = 987654321;
	queue<NODE> q;
	q.push(NODE(0,0,0,K));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		if(t.x == H-1 && t.y == W-1)
			if(ans > t.cnt)
				ans = t.cnt;

		for(int i=0; i<4; i++)
		{
			int nx = t.x+dx[i];
			int ny = t.y+dy[i];
			if(nx<0||ny<0||nx>=H||ny>=W) continue;
			if(visited[nx][ny][t.k]) continue;
			if(arr[nx][ny] == 1) continue;
			visited[nx][ny][t.k] = true;
			q.push(NODE(nx,ny,t.cnt+1,t.k));
		}				
		if(t.k > 0)
		{
			for(int i=0; i<8; i++)
			{
				int nx = t.x+ndx[i];
				int ny = t.y+ndy[i];
				if(nx<0||ny<0||nx>=H||ny>=W) continue;
				if(visited[nx][ny][t.k-1]) continue;
				if(arr[nx][ny] == 1) continue;
				visited[nx][ny][t.k-1] = true;
				q.push(NODE(nx,ny,t.cnt+1,t.k-1));
			}
		}
	}
	if(ans == 987654321)
		cout << "-1";
	else
		cout << ans;
	return 0;
}
