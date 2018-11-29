#include <iostream>
#include <queue>
using namespace std;


/*
'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불 
*/
int w,h;
char arr[1001][1001];
bool visited[1001][1001];
bool fired[1001][1001];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct NODE{
	int x,y,cnt;
	NODE(int _x, int _y, int _cnt) {x=_x;y=_y;cnt=_cnt;};
};

void reset()
{
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			visited[i][j] = false;
			fired[i][j] = false;	
		}	
}

int main()
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++)
	{	
		reset();
		queue<NODE> q;
		queue<NODE> f;
		int a,b;
		cin >> w >> h;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
			{
				cin >> arr[i][j];
				if(arr[i][j] == '@')
				{
					a = i;
					b = j;
				}
				else if(arr[i][j] == '*')
				{
					fired[i][j] = true;
					f.push(NODE(i,j,0));
				}
					
			}

		int ans = 987654321;
		visited[a][b] = true;
		q.push(NODE(a,b,0));

		while(!q.empty())
		{
			int size = f.size();
			while(size --)
			{
				NODE t = f.front();
				f.pop();
				for(int i=0; i<4; i++)
				{
					int nx = t.x+dx[i];
					int ny = t.y+dy[i];
					if(nx<0||ny<0||nx>=h||ny>=w) continue;
					if(fired[nx][ny]) continue;
					if(arr[nx][ny] == '#') continue;
					fired[nx][ny] = true;
					f.push(NODE(nx,ny,0));
				}
			}
	
			int size2 = q.size();
			while(size2 --)
			{
				NODE t = q.front();
				q.pop();
				
				if(t.x == 0 || t.y == 0 || t.x == h-1 || t.y == w-1)
					if(t.cnt < ans)
						ans = t.cnt;
				
				for(int i=0; i<4; i++)
				{
					int nx = t.x+dx[i];
					int ny = t.y+dy[i];
					if(nx<0||ny<0||nx>=h||ny>=w) continue;
					if(fired[nx][ny]) continue;
					if(visited[nx][ny]) continue;
					if(arr[nx][ny] == '#') continue;
					visited[nx][ny] = true;
					q.push(NODE(nx,ny,t.cnt+1));
				}
			}
		}
		if(ans == 987654321)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans+1 << '\n';
	}
	return 0;
}
