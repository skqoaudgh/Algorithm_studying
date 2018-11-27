#include <iostream>
#include <queue>
using namespace std;

int N,M;
int ans;
int arr[301][301];
int minusd[301][301];
bool visited[301][301];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	int x,y,cnt;
	NODE(int _x, int _y) {x=_x;y=_y;};
};

int getMinusSea(int x, int y)
{
	if(arr[x][y] < 1) return 0;
	int cnt = 0;
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=M) continue;
		if(arr[nx][ny] < 1)
			cnt ++;
	}
	return cnt;
}

int getArea()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			visited[i][j] = false;
			
	int number = 0;
	queue<NODE> q;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(visited[i][j]) continue;
			if(arr[i][j] > 0)
			{
				number ++;
				q.push(NODE(i,j));
				while(!q.empty())
				{
					NODE t = q.front();
					q.pop();
					
					for(int p=0; p<4; p++)
					{
						int nx = t.x+dx[p];
						int ny = t.y+dy[p];
						if(nx<0||ny<0||nx>=N||ny>=M) continue;
						if(visited[nx][ny]) continue;
						if(arr[nx][ny] < 1) continue;
						q.push(NODE(nx,ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
	return number;
}

int main() 
{
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
		
	int area_cnt = 0;
	while((area_cnt = getArea()) < 2)
	{
		if(area_cnt == 0)
		{
			ans = 0;
			break;
		}
		ans ++;
		
	
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(arr[i][j] > 0)
					minusd[i][j] = getMinusSea(i,j);
				
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(arr[i][j] > 0)
					arr[i][j] -= minusd[i][j];
	}
	
	cout << ans;
	return 0;
}
