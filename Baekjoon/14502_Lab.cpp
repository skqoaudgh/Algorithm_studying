#include <iostream>
#include <queue>
using namespace std;

int N,M; 
int arr[9][9];
bool visited[9][9];
int wall[9][9];
int ans;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	int x,y;
	NODE(int _x, int _y){x=_x; y=_y;};
};

int getSafeArea(int arr[9][9])
{
	int map[9][9];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			map[i][j] = arr[i][j];

	int result = 0;
	queue<NODE> q;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			visited[i][j] = false;
			if(map[i][j] == 2)
				q.push(NODE(i,j));				
		}

				
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = t.x+dx[i];
			int ny = t.y+dy[i];
			if(nx < 0 || ny < 0 || nx >=N || ny >= M) continue;
			if(visited[nx][ny]) continue;
			if(map[nx][ny] == 2 || map[nx][ny] == 1) continue;
			visited[nx][ny] = true;
			map[nx][ny] = 2;
			q.push(NODE(nx,ny));
		}
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j] == 0)
				result ++;
	return result;
}

void makeWall(int index, int cnt)
{
	if(index > N*M) return;
	if(cnt >= 3)
	{
		int res = getSafeArea(arr);
		if(res > ans)
			ans = res;
		return;
	}
	int x = index/M;
	int y = index%M;
	if(x>=N || y >= M) return;
	if(arr[x][y] == 2 || arr[x][y] == 1)
		makeWall(index+1, cnt);
	else
	{
		makeWall(index+1,cnt);
		arr[x][y] = 1;
		makeWall(index+1,cnt+1);
		arr[x][y] = 0;
	}
}

int main()
{
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
	
	makeWall(0,0);
	cout << ans;
	return 0;
}
