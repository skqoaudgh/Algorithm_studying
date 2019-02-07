#include <iostream>
#include <queue>
using namespace std;

int arr[105][105];
bool visited[105][105][5];

int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};

struct NODE {
	int x,y,dir,cnt;
	NODE(int X, int Y, int DIR, int CNT) {x=X;y=Y;dir=DIR;cnt=CNT;};
};

int opp(int num)
{
	if(num == 1)
		return 2;
	else if(num == 2)
		return 1;
	else if(num == 3)
		return 4;
	return 3;	
}

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
			
	int start_x, start_y, start_dir;
	int end_x, end_y, end_dir;	
	cin >> start_x >> start_y >> start_dir;
	cin >> end_x >> end_y >> end_dir;
	start_x --; start_y --;
	end_x --; end_y --;
	
	int ans = 0;
	queue<NODE> q;
	visited[start_x][start_y][start_dir] = true;
	q.push(NODE(start_x,start_y,start_dir,0));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();

		if(t.x == end_x && t.y == end_y && t.dir == end_dir)
		{
			ans = t.cnt;
			break;
		}
				
		for(int i=1; i<=3; i++)
		{
			int nx = t.x + dx[t.dir]*i;
			int ny = t.y + dy[t.dir]*i;
			if(nx<0||ny<0||nx>=N||ny>=M) break;
			if(arr[nx][ny] == 1) break;
			if(visited[nx][ny][t.dir]) continue;
			visited[nx][ny][t.dir] = true;
			q.push(NODE(nx,ny,t.dir,t.cnt+1));
		}
        for(int i=1; i<=4; i++) 
		{
            if(t.dir == i) continue;
            if(visited[t.x][t.y][i]) continue;
            visited[t.x][t.y][i] = true;
            if(i == opp(t.dir))
            	q.push(NODE(t.x,t.y,i,t.cnt+2));
            else
            	q.push(NODE(t.x,t.y,i,t.cnt+1));
		}
	}
	cout << ans;
	return 0;
}
