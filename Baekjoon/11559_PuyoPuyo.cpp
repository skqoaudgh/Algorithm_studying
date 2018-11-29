#include <iostream>
#include <queue>
using namespace std;

char arr[13][7];
bool visited[13][7];
int ans = 0;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	char ch;
	int x,y,cnt;
	NODE(int X, int Y, char CH, int CNT) {x=X;y=Y;ch=CH;cnt=CNT;};
};


void reset()
{
	for(int i=0; i<12; i++)
		for(int j=0; j<6; j++)
		{
			visited[i][j] = false;
		}		
} 

bool bfs(int x, int y)
{
	//cout << "bfs시작: " << x << ' ' << y << '\n';
	bool flag = false;
	int count = 0;
	queue<NODE> q;
	vector<NODE> v;
	q.push(NODE(x,y,arr[x][y],0));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = t.x+dx[i];
			int ny = t.y+dy[i];
			if(nx<0||ny<0||nx>=12||ny>=6) continue;
			if(visited[nx][ny]) continue;
			if(arr[nx][ny] != t.ch) continue;
			visited[nx][ny] = true;
			q.push(NODE(nx,ny,t.ch,t.cnt+1));
			v.push_back(NODE(nx,ny,t.ch,t.cnt+1));
			count ++;
		}
	}
	if(count >= 4)
	{
		for(int i=0; i<v.size(); i++)
		{
			arr[v[i].x][v[i].y] = '.';
			//cout << "삭제: " << v[i].x << ' ' << v[i].y << '\n';
		}
		flag = true;
	}
	return flag;
}

int main()
{
	for(int i=0; i<12; i++)
		for(int j=0; j<6; j++)
			cin >> arr[i][j];
		
	queue<NODE> q;
	
	while(1)
	{
		reset();
		bool flag = false;
		for(int i=0; i<12; i++)
			for(int j=0; j<6; j++)
				if(!visited[i][j] && arr[i][j] != '.')
					if(bfs(i,j))
						flag = true;
		
		if(!flag) break;
		else ans++;
		
		// 맵 재조정
		for(int i=11; i>=0; i--)
		{
			for(int j=5; j>=0; j--)
			{
				int cnt = 0;
				if(arr[i][j] != '.')
				{
					for(int p=i+1; p<12; p++)
						if(arr[p][j] == '.')
							cnt ++;
					if(cnt > 0)
					{
						arr[i+cnt][j] = arr[i][j];
						arr[i][j] = '.';						
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}
